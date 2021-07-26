import java.io.*;
import java.awt.*;
import java.awt.event.*;

public class Factorial_3b extends java.applet.Applet implements ActionListener{
	Label label1, label2, label3;
	TextField t1, t2;
	Button b;
	int n;
	int fact = 1;
	
	public Factorial_3b() {
		t1 = new TextField(20);
		t2 = new TextField(20);
		
		label1 = new Label("Enter a number");
		label2 = new Label("Factorial");
		label3 = new Label("Result");
		
		b = new Button("Compute");
		
		add(label2);
		add(label1);
		add(t1);
		add(label3);
		add(t2);
		add(b);
		
		b.addActionListener(this);
	}
	
	public void actionPerformed(ActionEvent ae) {
		String text = t1.getText();
		n = Integer.parseInt(text);
		for(int i = n ; i > 0 ; i--) {
			fact = fact * i;
		}
		String text2 = ""+fact;
		t2.setText(text2);
		fact = 1;
	}
	public static void main(String args[]) {
		Factorial_3b f = new Factorial_3b();
	}
}
/*<applet code ="Factorial_3b.class" width = 200 height = 300></applet>*/
		