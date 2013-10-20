import java.applet.*;
import java.awt.*;

public class DrawCircle extends Applet
{
    public void paint(Graphics g)
    {
        Dimension d;
        d = getSize();
        g.drawOval(d.width/2 - 50, d.height/2 - 50, 100, 100);
    }
}

/*<Applet code = My app Height = 100 width = 100>
</Applet>*/