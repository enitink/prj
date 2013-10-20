/*
 * Created on Jun 8, 2006
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */

/**
 * @author Nitin
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
/*
 * StopWatch.java
 * KIDware (206) 721-2556
 */
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class StopWatch extends JFrame 
{

  // declare controls used
  static JButton startButton = new JButton();
  static JButton stopButton = new JButton();
  static JButton exitButton = new JButton();
  static JLabel startLabel = new JLabel();
  static JLabel stopLabel = new JLabel();
  static JLabel elapsedLabel = new JLabel();;
  static JTextField startTextField = new JTextField();
  static JTextField stopTextField = new JTextField();
  static JTextField elapsedTextField = new JTextField();

  // declare class level variables
  static long startTime;
  static long stopTime;
  static double elapsedTime;

  public static void main(String args[]) 
  {
    new StopWatch().show();
  }

  public StopWatch() 
  {

    // Frame constructor
    setTitle("StopWatch Application");
    addWindowListener(new WindowAdapter() 
    {
      public void windowClosing(WindowEvent e) 
      {
    		exitForm(e);
      }
    });
    getContentPane().setLayout(new GridBagLayout());

    // add controls
    GridBagConstraints gridConstraints = new GridBagConstraints();
    startButton.setText("Start Timing");
    gridConstraints.gridx = 0;
    gridConstraints.gridy = 0;
    getContentPane().add(startButton, gridConstraints);    
    startButton.addActionListener(new ActionListener() 
    {
      public void actionPerformed(ActionEvent e) 
      {
      	startButtonActionPerformed(e);
      }
    });

    stopButton.setText("Stop Timing");
    gridConstraints.gridx = 0;
    gridConstraints.gridy = 1;
    getContentPane().add(stopButton, gridConstraints);
    stopButton.addActionListener(new ActionListener() 
    {
      public void actionPerformed(ActionEvent e) 
      {
      	stopButtonActionPerformed(e);
     	}
    });

    exitButton.setText("Exit");
    gridConstraints.gridx = 0;
    gridConstraints.gridy = 2;
    getContentPane().add(exitButton, gridConstraints);
    exitButton.addActionListener(new ActionListener() 
    {
      public void actionPerformed(ActionEvent e) 
      {
      	exitButtonActionPerformed(e);
      }
    });

    startLabel.setText("Start Time");
    gridConstraints.gridx = 1;
    gridConstraints.gridy = 0;
    getContentPane().add(startLabel, new GridBagConstraints());

    stopLabel.setText("Stop Time");
    gridConstraints.gridx = 1;
    gridConstraints.gridy = 1;
    getContentPane().add(stopLabel, gridConstraints);

    elapsedLabel.setText("Elapsed Time (sec)");
    gridConstraints.gridx = 1;
    gridConstraints.gridy = 2;
    getContentPane().add(elapsedLabel, gridConstraints);

    startTextField.setText("");
    startTextField.setColumns(15);
    gridConstraints.gridx = 2;
    gridConstraints.gridy = 0;
    getContentPane().add(startTextField, new GridBagConstraints());

    stopTextField.setText("");
    stopTextField.setColumns(15);
    gridConstraints.gridx = 2;
    gridConstraints.gridy = 1;
    getContentPane().add(stopTextField, gridConstraints);

    elapsedTextField.setText("");
    elapsedTextField.setColumns(15);
    gridConstraints.gridx = 2;
    gridConstraints.gridy = 2;
    getContentPane().add(elapsedTextField, gridConstraints);
    pack();
  }
  
  private void startButtonActionPerformed(ActionEvent e)
  {
		// click of start timing button
    startTime = System.currentTimeMillis();  
    startTextField.setText(String.valueOf(startTime));
    stopTextField.setText("");
    elapsedTextField.setText("");
  }
  
  private void stopButtonActionPerformed(ActionEvent e)
  {
 		// click of stop timing button
    stopTime = System.currentTimeMillis();
    stopTextField.setText(String.valueOf(stopTime));
    elapsedTime = (stopTime - startTime) / 1000.0;
    elapsedTextField.setText(String.valueOf(elapsedTime));
  }
  
  private void exitButtonActionPerformed(ActionEvent e)
  {
  	System.exit(0);
  }
  
  private void exitForm(WindowEvent e)
  {
  	System.exit(0);
  }
}
