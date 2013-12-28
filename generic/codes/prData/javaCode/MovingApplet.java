import java.awt.*;
import java.applet.*;

public class MovingApplet extends Applet implements Runnable{
	
	String msg = "   JAVA2 STANDARD EDITION VERSION 5.0   ";
	Thread t = null;
	boolean stoppage;
	
	public void init(){

		setBackground( Color.blue );
		setForeground( Color.pink );
	}

	public void start(){


		//System.out.print( Thread.currentThread() );		
		t = new Thread( this );
		//System.out.print( t.getName() );
		//System.out.print( this.getName() );

		stoppage = false;
		t.start();
		
	}

	public void run(){

		while( true ){

			repaint();

			try{
				t.sleep(250);
			} catch( Exception e ) {}

			char temp = msg.charAt(0);
			msg = msg.substring( 1 );
			msg = msg + temp;

			if( stoppage )
				break;
			
		}
		
	}

	public void stop(){

		t = null;
		stoppage = true;
	}

	public void paint( Graphics grps ){
		
		grps.drawString( msg, 60, 60 );
	}

/* 	<applet code = "MovingApplet" height = 100 width = 375>
	</applet>*/
}
		
		