import java.util.*;

abstract class Shape {
	public int a, b;

	public abstract void printArea();
}

class Rectangle extends Shape {
	public void printArea() {
		float area;
		area = a * b;
		System.out.println("Area of Rectangle is " + area);
	}
}

class Triangle extends Shape {
	public void printArea() {
		float area;
		area = (a * b) / 2;
		System.out.println("Area of Triangle is " + area);
	}
}

class Circle extends Shape {
	public void printArea() {
		float area;
		area = (22 * a * a) / 7;
		System.out.println("Area of Circle is " + area);
	}
}

public class Shapes_1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the numbers : ");
		int a1 = sc.nextInt();
		int b1 = sc.nextInt();
		Rectangle r = new Rectangle();
		r.a = a1;
		r.b = b1;
		r.printArea();
		Triangle t = new Triangle();
		t.a = a1;
		t.b = b1;
		t.printArea();
		Circle c = new Circle();
		c.a = a1;
		c.printArea();
	}
}
