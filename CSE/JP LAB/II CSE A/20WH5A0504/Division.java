import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class Division extends JFrame implements ActionListener
{
	JButton b1,b2;
 	JLabel l1,l2,l3;
 	JTextField tf1,tf2,tf3;
 	Division()
 	{
		l1=new JLabel("Enter Number1");
		tf1=new JTextField(18);
		l2=new JLabel("Enter Number2");
		tf2=new JTextField(18);
		b1=new JButton("DIVIDE");
		b1.addActionListener(this);
		l3=new JLabel("RESULT OF DIVISION");
 		tf3=new JTextField(18);
		setLayout(new FlowLayout());
 		add(l1);
		add(tf1);
 		add(l2);
		add(tf2);
 		add(l3);
		add(tf3);
 		add(b1);
 		setSize(400,400);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public void actionPerformed(ActionEvent e)
 	{
 		if(e.getSource()==b1)
 		{
 			try
 			{
 				int num1=Integer.parseInt(tf1.getText());
 				int num2=Integer.parseInt(tf2.getText());
 				int result=num1/num2;
 				tf3.setText(Integer.toString(result));
 			}
			catch(ArithmeticException ex)
 			{
				JOptionPane.showMessageDialog(null,"ArithmeticException: divide by zero");
 			}
 			catch(NumberFormatException ex)
 			{
				JOptionPane.showMessageDialog(this,"NumberFormatException");
 			}
 		}
 	}
 	public static void main(String args[])
 	{
		System.out.println("Name: G Indu");
		System.out.println("Roll No: 20WH5A0504");
 		Division b=new Division();

 	}
}