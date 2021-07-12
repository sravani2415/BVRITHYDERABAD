import java.io.*;
import java.util.Scanner;

abstract class shape {
	public int a, b;
	public abstract void printArea();
}
class rectangle extends shape {
	public void printArea() {
		float area; 
		area = a * b;
		System.out.println("Area of rectangle = " + area);
	}
}

class triangle extends shape {
	public void printArea() {
		float area; 
		area = (a * b) / 2;
		System.out.println("Area of triangle = " + area);
	}
}
class circle extends shape {
	public void printArea() {
		float area; 
		area = (22 * a * a) / 7;
		System.out.println("Area of circle with radius " + a + " is " + area);
		area = (22 * b * b) / 7;
		System.out.println("Area of circle with radius " + b + " is " + area);
	}
}

public class shapes {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a value: ");
		int a1 = sc.nextInt();
		System.out.println("Enter a value: ");
		int b1 = sc.nextInt();
		rectangle rect = new rectangle();
		rect.a = a1;
		rect.b = b1;
		rect.printArea();
		triangle tri = new triangle();
		tri.a = a1;
		tri.b = b1;
		tri.printArea();
		circle cir = new circle();
		cir.a = a1;
		cir.b = b1;
		cir.printArea();
	}
}


	