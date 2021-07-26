import java.applet.*;
import java.awt.*;
public class simpleApplet_3a extends Applet{
    public void paint(Graphics g){
		setForeground(Color.blue);
		setBackground(Color.pink);
		g.drawString("Welcome to applet", 50, 60);
	}
}
/* <applet code="simpleApplet_3a.class" width=200 height=300></applet>*/