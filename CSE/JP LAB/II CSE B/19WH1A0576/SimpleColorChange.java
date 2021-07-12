import java.awt.*;
import java.awt.event.*;

public class SimpleColorChange{
	Frame f1;
	Scrollbar s1;
	public SimpleColorChange()
	{
	f1 = new Frame();
	f1.setSize(500,400);
	s1 = new Scrollbar();
	s1.setBounds(50,50,20,400);
	f1.add(s1);
	f1.setLayout(null);
	f1.setVisible(true);
	}

	public static void main(String args[]){
	SimpleColorChange sc = new SimpleColorChange();
	}
}