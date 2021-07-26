import java.io.*;
import java.util.*;
class Even implements Runnable {
	public int num1;
	public Even(int num1) {
	this.num1 = num1;
	}
	public void run() {
	System.out.println("New Thread "+ num1 +" is EVEN and Square of " + num1 + " is: " + num1 * num1);
	}
}

class Odd implements Runnable{
	public int num2;
	public Odd(int num2){
	this.num2 = num2;
	}
	public void run(){
		System.out.println("New Thread "+ num2 +" is ODD and Cube of " + num2 + " is: " + num2 * num2 * num2);
	}
}

class A extends Thread {
	public void run() {
		int num = 0;
		Random r = new Random();
		try {
			for (int i = 0; i< 5; i++)   {
				num = r.nextInt(100);
				System.out.println("Main Thread and Generated Number is " + num);
				if (num % 2 == 0){
					  Thread t1 = new Thread(new Even(num));
					  t1.start();
				} 
				else 
				{
					 Thread t2 = new Thread(new Odd(num));
					 t2.start();
				}
				Thread.sleep(1000);
				System.out.println("--------------------------------------");
			}
		 }
		catch (Exception ex) {
			System.out.println(ex.getMessage());
		}
   }
}

public class MultiThreadApplication{
	public static void main(String[] args) {
        A a = new A();
        a.start();
	}
}