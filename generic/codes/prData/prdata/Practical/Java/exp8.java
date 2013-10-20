import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.lang.String;
import java.util.*;

public class GaussianNumbers extends JFrame implements ActionListener,WindowListener
{
    JLabel  Label9 = new JLabel(", decimal places = ", SwingConstants.LEFT);
    JTextField  accuracy = new JTextField("2",6);
    JLabel  Label2 = new JLabel("mu in [", SwingConstants.LEFT);
    JLabel  Label1 = new JLabel("Priors :", SwingConstants.LEFT);
    JTextField  muHi = new JTextField("500",6);
    JLabel  Label12 = new JLabel("+/- S.D.=", SwingConstants.LEFT);
    JLabel  Label8 = new JLabel(", N = ", SwingConstants.LEFT);
    JLabel  Label6 = new JLabel("mu = ", SwingConstants.LEFT);
    JLabel  Label7 = new JLabel(", sigma = ", SwingConstants.LEFT);
    JLabel  Label3 = new JLabel("Data Generation :", SwingConstants.LEFT);
    JTextField  muLo = new JTextField("-500",6);
    JList  List1 = new JList();

    JTextField  mean = new JTextField("",8);
    JTextField  SD = new JTextField("",8);
    JButton  Command1 = new JButton("Randomise");
    JTextField  sigmaHi = new JTextField("30",5);
    JTextField  N = new JTextField("20",6);
    JLabel  Label5 = new JLabel("], sigma in [0 ... ", SwingConstants.LEFT);
    JLabel  Label11 = new JLabel("maxLHmean = ", SwingConstants.LEFT);
    JLabel  Label4 = new JLabel("...", SwingConstants.LEFT);
    JLabel  Label10 = new JLabel("Sample : ", SwingConstants.LEFT);
    JTextField  mu = new JTextField("0",6);
    JTextField  sigma = new JTextField("1",6);

    static int ArgValue; int acc;
    ArrayList A = new ArrayList();
    double root2pi = Math.sqrt(2*Math.PI);
    double N01cumulative[] = new double[201]; // N(0,1) to let us sample from N(mu,sigma)
    int imu = 0, isigma = 1; // generating parameters
    int muF = 0, sigmaF = 1; // nominated estimates
    int imean= 0,   iSD = 1; // calculated from sample
    int muRange = 1000, sigmaRange =100; // prior ranges for inferred mu and sigma
    int power10 = 1; // measurement accuracy is  +/- 1/(2*power10)

    void prt(String s)
    {
        System.out.println(s);
    }

    boolean getControls() // read mu, sigma
    {
        int imuLo = Integer.parseInt(muLo.getText()),        // prior for mu
           imuHi = Integer.parseInt(muHi.getText());
        muRange = imuHi - imuLo;
        sigmaRange = Integer.parseInt(sigmaHi.getText());   // prior sigma
        if(sigmaRange <= 0)
            { err("sigma prior range must be +ve"); return false; }
        if(muRange < 4*sigmaRange)
            { err("mu prior range is too small w.r.t. sigma"); return false; }

        imu = Integer.parseInt(mu.getText());            // generating model
        if(imu < imuLo+2*sigmaRange || imu > imuHi-2*sigmaRange)
            { err("mu must be well within its prior!"); return false; }
        isigma = Integer.parseInt(sigma.getText());
        if(isigma <= 0 || isigma > sigmaRange/2)
            { err("sigma must be well within its prior!"); return false; }

        acc = Integer.parseInt(accuracy.getText());
        if(acc < 0) { err("# decimal places must be positive"); return false; }
        if(acc >10) { err("# decimal places too large");        return false; }
        power10 = 1;
        int i; for(i = 0; i < acc; i++) power10 *= 10; // measurement accuracy

        // else all ok
        return true;
    }//getControls

    void randomise()
    {
        if(! getControls()) return;
        int iN = Integer.parseInt(N.getText());
        if(iN <= 0) { err("N must be positive"); return; }

        for(int i = 0; i < iN; i++)             // NB. measurement accuracy
            A.add(new Double(Nrandom(imu, isigma)));

        showresult();
    }//randomise

    double normalMuS(int amu, int asigma, double x)                                 // N(mu,sigma)
    {
        double xLessMuOverSigma = (x-amu)/asigma;
        double xLessMuOverSigmaSqr = xLessMuOverSigma * xLessMuOverSigma;
        return Math.exp(- xLessMuOverSigmaSqr / 2) / (root2pi * asigma);
    }//normal

    double normal(double x) { return normalMuS(imu, isigma, x); }

    double Simpson(double lo, double hi, double step) //integrate f from lo to hi in step intervals
    {
        double N = Math.ceil((hi-lo)/step);
        if(N < 2) N = 2;
            N = 2*Math.ceil(N/2);   // N must be even
        int i; double total = normal(lo) + normal(hi);
        for(i = 1; i < N; i++)      // eval f() at interval boundaries, *4, *2, ... *4
            total += normal( ((N-i)*lo + i*hi)/N ) * ( 2*Math.floor(i/2)==i ? 2 : 4 );
        return total * (hi-lo)/(3*N);
    }//Simpson
 
    void setCumulative() // for N(0,1)  over [-10 ... +10]
    {
        int i;
        N01cumulative[0] = 0;
        for(i=1; i <= 200; i++)
        {
            double left = (i-101)/10,  right=(i-100)/10;  // e.g.  0.5 ... 0.6
            N01cumulative[i] = N01cumulative[i-1] + Simpson(left, right, .05);
        }
    }//setCumulative

    double Nrandom(int amu, int asigma)
    {
        int lo = 0, hi = N01cumulative.length-1;
        double ran = Math.random() * N01cumulative[hi]; // allow for numerical errors
        while(lo < hi-1) // binary search
        // find mid s.t. N01cumulative[mid] < ran <= N01cumulative[mid+1]
        {
            int mid = (int)Math.floor((hi+lo)/2);
            if( N01cumulative[mid] < ran )
                lo = mid;
            else
                hi = mid;
        }

        double N01lo = N01cumulative[lo], N01hi = N01cumulative[hi];
        double r = amu + ((ran-N01lo)*(hi-100)+(N01hi-ran)*(lo-100))/(N01hi-N01lo) * asigma / 10;
        return r;
    }//Nrandom

    void showresult()
    {
        int i; double sum=0.0, sumSq=0.0; double d, Ai;
        DefaultListModel listModel = new DefaultListModel();
        for (i=0; i < A.size(); i++)
        {
            Object o = A.get(i);
            Ai = ((Double)o).doubleValue();
            sum += Ai;  sumSq += Ai*Ai;
            Ai = Ai * Math.pow(10.0, (double)acc);
            Ai = Math.round(Ai) / Math.pow(10.0, (double)acc);
            listModel.addElement("" + Ai);
        }
        List1.setModel(listModel);
        d = sum / A.size();
        mean.setText("" + d);
        d = Math.sqrt( sumSq/A.size() - imean*imean );
        SD.setText("" + d);
    }//showresult

    void err(String s)
    {
        Toolkit.getDefaultToolkit().beep();
        JOptionPane.showMessageDialog(this, s, "Input Error", JOptionPane.ERROR_MESSAGE);
    }

    public GaussianNumbers() {
      addWindowListener(this);
      setTitle("Gaussian Distribution");
      getContentPane().setLayout(null);
      setBounds (4, 23, 512, 285 );
      setFont(new Font ("Arial", Font.PLAIN, 12));
      setBackground(Color.lightGray);

      getContentPane().add(Label9);
      Label9.setBounds( getInsets().left + getInsets().right + 328, getInsets().top + getInsets().bottom + 104, 131, 16);
      //Object.setBounds( Left, Top, Width, Height);
      Label9.setFont(new Font( "Arial", Font.BOLD, 13));

      getContentPane().add(accuracy);
      accuracy.setBounds( getInsets().left + getInsets().right + 454, getInsets().top + getInsets().bottom + 104, 41, 19);

      getContentPane().add(Label2);
      Label2.setBounds( getInsets().left + getInsets().right + 32, getInsets().top + getInsets().bottom + 32, 46, 16);
      Label2.setFont(new Font( "Arial", Font.BOLD, 13));

      getContentPane().add(Label1);
      Label1.setBounds( getInsets().left + getInsets().right + 8, getInsets().top + getInsets().bottom + 0, 67, 24);
      Label1.setFont(new Font( "Arial", Font.BOLD, 19));

      getContentPane().add(muHi);
      muHi.setBounds( getInsets().left + getInsets().right + 144, getInsets().top + getInsets().bottom + 32, 41, 19);

      getContentPane().add(Label12);
      Label12.setBounds( getInsets().left + getInsets().right + 312,  getInsets().top + getInsets().bottom + 232, 60, 16);
      Label12.setFont(new Font( "Times New Roman", Font.BOLD, 13));

      getContentPane().add(Label8);
      Label8.setBounds( getInsets().left + getInsets().right + 240, getInsets().top + getInsets().bottom + 104, 36, 16);
      Label8.setFont(new Font( "Arial", Font.BOLD, 13));

      getContentPane().add(Label6);
      Label6.setBounds( getInsets().left + getInsets().right + 32, getInsets().top + getInsets().bottom + 104, 37, 16);
      Label6.setFont(new Font( "Arial", Font.BOLD, 13));

      getContentPane().add(Label7);
      Label7.setBounds( getInsets().left + getInsets().right + 120, getInsets().top + getInsets().bottom + 104, 67, 16);
      Label7.setFont(new Font( "Arial", Font.BOLD, 13));

      getContentPane().add(Label3);
      Label3.setBounds( getInsets().left + getInsets().right + 8, getInsets().top + getInsets().bottom + 72, 163, 24);
      Label3.setFont(new Font( "Arial", Font.BOLD, 19));

      getContentPane().add(muLo);
      muLo.setBounds( getInsets().left + getInsets().right + 80, getInsets().top + getInsets().bottom + 32, 41, 19);

      JScrollPane listScrollPane = new JScrollPane(List1);
      Dimension minimumSize = new Dimension(70, 50);
      listScrollPane.setMinimumSize(minimumSize);
      getContentPane().add(listScrollPane);
      listScrollPane.setBounds( getInsets().left + getInsets().right + 104, getInsets().top + getInsets().bottom + 136, 183, 82);
      List1.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

      getContentPane().add(mean);
      mean.setBounds( getInsets().left + getInsets().right + 136,  getInsets().top + getInsets().bottom + 232, 169, 19);

      getContentPane().add(SD);
      SD.setBounds( getInsets().left + getInsets().right + 376,  getInsets().top + getInsets().bottom + 232, 121, 19);

      getContentPane().add(Command1);
      Command1.setBounds( getInsets().left + getInsets().right + 316, getInsets().top + getInsets().bottom + 160, 119, 25);
      Command1.addActionListener(this);

      getContentPane().add(sigmaHi);
      sigmaHi.setBounds( getInsets().left + getInsets().right + 296, getInsets().top + getInsets().bottom + 32, 33, 19);

      getContentPane().add(N);
      N.setBounds( getInsets().left + getInsets().right + 280, getInsets().top + getInsets().bottom + 104, 41, 19);
      N.setText("" + ArgValue);

      getContentPane().add(Label5);
      Label5.setBounds( getInsets().left + getInsets().right + 192, getInsets().top + getInsets().bottom + 32, 109, 16);
      Label5.setFont(new Font( "Arial", Font.BOLD, 13));

      getContentPane().add(Label11);
      Label11.setBounds( getInsets().left + getInsets().right + 32,  getInsets().top + getInsets().bottom + 232, 102, 16);
      Label11.setFont(new Font( "Courier New", Font.BOLD, 13));

      getContentPane().add(Label4);
      Label4.setBounds( getInsets().left + getInsets().right + 128, getInsets().top + getInsets().bottom + 32, 13, 23);
      Label4.setFont(new Font( "Arial", Font.BOLD, 13));

      getContentPane().add(Label10);
      Label10.setBounds( getInsets().left + getInsets().right + 32, getInsets().top + getInsets().bottom + 160, 66, 16);
      Label10.setFont(new Font( "Arial", Font.BOLD, 13));

      getContentPane().add(mu);
      mu.setBounds( getInsets().left + getInsets().right + 72, getInsets().top + getInsets().bottom + 104, 41, 19);

      getContentPane().add(sigma);
      sigma.setBounds( getInsets().left + getInsets().right + 192, getInsets().top + getInsets().bottom + 104, 41, 19);
    }  // end init

    public void actionPerformed(ActionEvent thisEvent)
    {
        setCumulative();
        randomise();
    }

    public void windowClosed(WindowEvent event) {
    }
    public void windowDeiconified(WindowEvent event) {
    }
    public void windowIconified(WindowEvent event) {
    }
    public void windowActivated(WindowEvent event) {
    }
    public void windowDeactivated(WindowEvent event) {
    }
    public void windowOpened(WindowEvent event) {
    }
    public void windowClosing(WindowEvent event) {
        System.exit(0);
    }

    public static void main(String args[])
    {
        try
        {
            ArgValue = Integer.parseInt(args[0]);
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            ArgValue = 100;
        }
        GaussianNumbers f = new GaussianNumbers();
        f.show();
    }
}  // end class
