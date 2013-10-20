import java.applet.*;
import java.awt.*;

public class AppletDemo extends Applet{
	
	public void paint( Graphics grp ){

		setBackground( Color.pink );
		setForeground( Color.blue );
		grp.drawString( "Nitin Kumar", 50, 50 );
		System.out.print( "Nitin Kumar" );
		
		/**  	@return void
			@param grp
			@since 2005
			@exception no exception */	

	}

	
	
/*	<applet code = AppletDemo Height = 100 Width = 200>
	</applet>*/
}
