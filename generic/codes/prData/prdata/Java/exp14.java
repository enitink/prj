import java.applet.*;
import java.awt.*;

public class exp14 extends Applet{
	
	public void paint( Graphics grp ){
		Dimension d = getSize();
		grp.drawLine( 0,0,d.width,d.height );
		grp.drawLine( d.width,0,0,d.height );		
		
	}

	
	
/*	<applet code = exp14 Height = 500 Width = 500>
	</applet>*/
}
