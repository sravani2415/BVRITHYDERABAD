import java.applet.*;
import java.awt.*;
public class DisplayApplet extends Applet{
    public void paint(Graphics g){
			setForeground(Color.white);
			setBackground(Color.blue);
			g.drawString("Welcome To Applet", 200, 210);
		}
	}