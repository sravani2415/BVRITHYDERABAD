import java.util.*;

class Even implements Runnable {
	public int x;
	public Even(int x) {
	this.x = x;
	}
	public void run() {
	System.out.println("New Thread "+ x +" is even.");
	System.out.println("Square of " + x + " is: " + x * x);
	}
}

class Odd implements Runnable {
	public int x;
	public Odd(int x) {
	this.x = x;
	}
	public void run(){
		System.out.println("New Thread "+ x +" is odd.");
		System.out.println("Cube of " + x + " is: " + x * x * x);
	}
}
class A extends Thread {
	public void run() {
	int num = 0;
	Random r = new Random();
	try {
		int i;
        	for (i=0;i<3;i++) {
        	num = r.nextInt(25);
        	System.out.println("Main Thread");
		System.out.println("Generated Number is " + num);
		if (num % 2 == 0) {
			Thread t1 = new Thread(new Even(num));
			t1.start();
		} 
		else {
			Thread t2 = new Thread(new Odd(num));
			t2.start();
		}
		Thread.sleep(1000);
		System.out.println(" ");
		System.out.println("--------------------------------------");
		System.out.println(" ");
		}
	}
	catch (Exception ex) {
		System.out.println(ex.getMessage());
	}
	}
}
public class multiThread {
	public static void main(String[] args) {
        A a = new A();
        a.start();
	}
}