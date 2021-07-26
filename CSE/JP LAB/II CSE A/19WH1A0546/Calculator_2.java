import	java.awt.*;
import	java.awt.event.*;
import	java.applet.*;

public class Calculator_2 extends Applet implements ActionListener {
	int n1, n2, result;
	
	TextField t;
	Button b[] = new	Button[10];
	Button add,sub,mul,div,clear,mod,equal;
	char operator;
	
	public static void main(String args[]) {
		Calculator_2 c = new Calculator_2();
		c.init();
	}
	
	public void init()	{
		t = new TextField(10);
		GridLayout g = new GridLayout(4,5);
		setLayout(g);
		for(int i=0;i<10;i++) {
			b[i]=new Button(""+i);
		}
		add = new Button("+");
		sub = new Button("-");
		mul = new	Button("*");
		div = new	Button("/");
		mod = new	Button("%");
		clear = new Button("Clear");
		equal = new	Button("=");
		t.addActionListener(this);
		
		for(int i=0;i<10;i++){
			add(b[i]);
		}
		add(add);
		add(sub);
		add(mul);
		add(div);
		add(mod);
		add(clear);
		add(equal);
		add(t);
		for(int i=0;i<10;i++) {
			b[i].addActionListener(this);
		}
		add.addActionListener(this);
		sub.addActionListener(this);
		mul.addActionListener(this);
		div.addActionListener(this);
		mod.addActionListener(this);
		clear.addActionListener(this);
		equal.addActionListener(this);
	}
	public void actionPerformed(ActionEvent ae) {
		String character = ae.getActionCommand();
		char ch = character.charAt(0);
		if(Character.isDigit(ch))
			t.setText(t.getText()+character);
		else if(character == "+"){ //str.equals("+")
			n1 = Integer.parseInt(t.getText());
			operator='+';
			t.setText("");
		}
		else if(character == "-") {
			n1=Integer.parseInt(t.getText());
			operator = '-';
			t.setText("");
		}
		else if(character == "*"){
			n1=Integer.parseInt(t.getText());
			operator='*';
			t.setText("");
		}
		else if(character == "/"){
			n1=Integer.parseInt(t.getText());
			operator='/';
			t.setText("");
		}
		else if(character == "%"){
			n1=Integer.parseInt(t.getText());
			operator='%';
			t.setText("");
		}
		if(character == "=")	{
			n2=Integer.parseInt(t.getText());
			if	(operator=='+')
				result=n1+n2;
			else if (operator=='-')
				result=n1-n2;
			else if(operator=='*')
				result=n1*n2;
			else if	(operator=='/'){
				try {
					result=n1/n2;
				}
				catch(ArithmeticException e){
					System.out.println("Division by zero not possible");
				}	
			}
			else if(operator=='%')
				result=n1%n2;
			t.setText(""+result);
		}
		if(character == "Clear") {
			t.setText("");
		}
	}
}
/* <applet code="Calculator_2.class" width=200 height=300></applet>*/