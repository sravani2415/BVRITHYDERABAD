import java.util.*;

abstract class Shape {
	public int x, y;

	public abstract void printArea();
}

class Rectangle extends Shape {
	public void printArea() {
		float area;
		area = x * y;
		System.out.println("Area of Rectangle is " + area);
	}
}

class Triangle extends Shape {
	public void printArea() {
		float area;
		area = (x * y) / 2;
		System.out.println("Area of Triangle is " + area);
	}
}

class Circle extends Shape {
	public void printArea() {
		float area;
		area = (22 * x * x) / 7;
		System.out.println("Area of Circle is " + area);
	}
}

public class Shapes {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter values : \n1.First Value\t2.Second value");
		int a = sc.nextInt();
		int b = sc.nextInt();
		Rectangle r = new Rectangle();
		r.x = a;
		r.y = b;
		r.printArea();
		Triangle t = new Triangle();
		t.x = a;
		t.y = b;
		t.printArea();
		System.out.print("With First Value ");
		Circle c = new Circle();
		c.x = a;
		c.printArea();
		System.out.print("With Second Value ");
		Circle c1 = new Circle();
		c1.x = b;
		c1.printArea();
	}
}
