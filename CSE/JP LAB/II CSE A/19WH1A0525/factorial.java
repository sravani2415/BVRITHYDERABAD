import java.io.*;
import java.awt.*;
import java.awt.event.*;
import java.applet.Applet;


public class factorial extends Applet implements ActionListener
{
    Button b1; 
    TextField t1, t2;
    Label l1, l2;

    public factorial()
    {
        l1 = new Label("Num");
        t1 = new TextField(6);

        b1 = new Button("Compute");
        
        l2 = new Label("Factorial");
        t2 = new TextField(30);

        l1.setBounds(20, 50, 70, 20);
		t1.setBounds(100, 50, 100, 20);
		l2.setBounds(20, 90, 70, 20);
		t2.setBounds(100, 90, 100, 20);
       
        add(l1);
		add(t1);

		add(b1);

		add(l2);
		add(t2);

        b1.addActionListener(this);

      

    }
    public void actionPerformed(ActionEvent e){
        if(e.getSource()==b1)
        {
            int fact=fact(Integer.parseInt(t1.getText()));
            t2.setText(String.valueOf(fact));
        }
    }
    int fact(int f) 
    {
        int s=0; 
        if(f==0)
            return 1;
        else
            return f*fact(f-1);
    }
}