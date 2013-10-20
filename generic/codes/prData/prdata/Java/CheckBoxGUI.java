import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class CheckBoxGUI extends Applet implements ItemListener{
	

	public static Label lb1 = new Label( "BACKGROUND COLOR", 1 );
	public static Label lb2 = new Label( "FOREGROUND COLOR", 1 );
	
	public static Panel pnl1 = new Panel( );
	public static Panel pnl2 = new Panel( );

	public static CheckboxGroup cbg1 = new CheckboxGroup();
	public static CheckboxGroup cbg2 = new CheckboxGroup();

	public static Checkbox cb1 = new Checkbox( "RED", cbg1, false );
	public static Checkbox cb2 = new Checkbox( "BLUE", cbg1, false  );
	public static Checkbox cb3 = new Checkbox( "GREEN", cbg1, false  );

	public static Checkbox cb4 = new Checkbox( "CYAN", cbg2, false  );
	public static Checkbox cb5 = new Checkbox( "MAGENTA", cbg2, false  );
	public static Checkbox cb6 = new Checkbox( "YELLOW", cbg2, false  );

	public void paint( Graphics g ){
			
		setLayout( new FlowLayout() );
		pnl1.setLayout( new GridLayout( 4, 2 ) );
		pnl2.setLayout( new GridLayout( 4, 2 ) );
		
		cb1.addItemListener( this );
		cb2.addItemListener( this );
		cb3.addItemListener( this );
		cb4.addItemListener( this );
		cb5.addItemListener( this );
		cb6.addItemListener( this );

		pnl1.add( lb1 );
		pnl2.add( lb2 );		
		pnl1.add( cb1 );
		pnl2.add( cb4 );		
		pnl1.add( cb2 );
		pnl2.add( cb5 );
		pnl1.add( cb3 );
		pnl2.add( cb6 );

		add( pnl1 );
		add( pnl2 );
		
	}
	
	public void itemStateChanged( ItemEvent e ){
		
		if ( e.getSource() == cb1 )
			setBackground( Color.red );
		
		if ( e.getSource() == cb2 )
			setBackground( Color.blue );
				

		if ( e.getSource() == cb3 )
			setBackground( Color.green );
				

		if ( e.getSource() == cb4 )
			setForeground( Color.cyan );
				

		if ( e.getSource() == cb5 )
			setForeground( Color.magenta );
				

		if ( e.getSource() == cb6 )
			setForeground( Color.yellow );
		
	}

}

/* <applet code = CheckBoxGUI Height = 100 Width = 600 >
   </applet> */
			  
			