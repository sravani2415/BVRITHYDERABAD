import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import java.lang.*;

public class division extends Applet implements ActionListener {
    String msg;
    TextField t1, t2, res;
    Label l1, l2, l3;
    Button div;
    public void init() {
        l1 = new Label("Dividend");
        l2 = new Label("Divisor");
        l3 = new Label("Result");

        t1 = new TextField(10);
        t2 = new TextField(10);
        res = new TextField(10);
        div = new Button("Click");

        div.addActionListener(this);

        add(l1);
        add(t1);

        add(l2);
        add(t2);

        add(l3);
        add(res);
        add(div);
    }
    public void actionPerformed(ActionEvent ae)
    {
        String arg=ae.getActionCommand();
        String s1=t1.getText();
        String s2=t2.getText();
        int num1 =0, num2 =0;
        if(arg.equals("Click"))
        {
            try 
            {
                num1=Integer.parseInt(s1);
                num2=Integer.parseInt(s2);
                try
                {
                        if(num2 != 0)
                        {
                            int num3 = num1/num2;
                            res.setText(String.valueOf(num3));
                            msg = "Successful!!";
                           // repaint();
                        }
                        else{
                            throw new ArithmeticException();
                        }
                }
                catch (ArithmeticException e) {
                    //TODO: handle exception
                    System.out.println("Divide by zero"+e);
                    res.setText("");
                    msg = "Can't Divide by Zero";
                    //repaint(); 
                }    
            } 
            catch (NumberFormatException e1) {
                //TODO: handle exception
                System.out.println("Number Format Exception"+e1);
                res.setText("");
                msg = "NumberFormatException";
                //repaint();
            }
        }
    }

    public void paint(Graphics g) {
        g.drawString(msg, 30, 70);
    }
}