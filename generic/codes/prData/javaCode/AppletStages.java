import java.applet.*;
import java.awt.*;

public class AppletStages extends Applet{
	
	String x;
	int i = 35;

	public void update( Graphics g ){
		setBackground( Color.gray );
		setForeground( Color.red );
	}
		
	public void init(){
		
		x = "\nExecuting init()";
	}

	public void start(){
		x += "\nExecuting start()";
	}
	
	public void paint( Graphics grps){
		update( grps );
		i+=5;
		x += "\nExecuting paint()";
		grps.drawString( x, 35, i );
	}

	public void stop(){
		
		x += "\nExecuting stop()";
	}

	public void destroy(){
		
		x += "\nExecuting destroy()";
		System.out.print(x + i);
	}

/*	<applet code = AppletStages Height = 300 Width = 600>
	</applet>*/
}
		