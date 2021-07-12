import java.applet.Applet;  
import java.awt.*; 
import java.awt.event.*; 
  
public class GraphicsDemo extends Applet implements ActionListener
{ 
	Button b1;
	Label l1;
	public void init() {
		b1=new Button("ok");
		l1=new Label();
		l1.setBounds(50,80,80,20);
		b1.setBounds(50,50,80,20);
		//setLayout(null);
		b1.addActionListener(this);
		
		add(l1);
		add(b1);
	}
	public void actionPerformed(ActionEvent e){
		l1.setText("hello");
	}
	
		
  
	/*public void paint(Graphics g){  
		g.setColor(Color.red); 
		g.drawString("Welcome",50, 50);  
		g.drawLine(20,30,20,300);  
		g.drawRect(70,100,30,30);  
		g.fillRect(170,100,30,30);  
		g.drawOval(70,200,30,30);  
		g.setColor(Color.pink);  
		g.fillOval(170,200,30,30);  
		g.drawArc(90,150,30,30,30,270);  
		g.fillArc(270,150,30,30,0,180);  
	}  

	/*Button b1;
	Label l1;
	public void init() {
		b1=new Button("ok");
		b1.setBounds(50,50,80,20);
		
		setLayout(null);
		b1.addActionListener(this);
		add(b1);
	}
	public void actionPerformed(ActionEvent e){
		
	}*/
} 