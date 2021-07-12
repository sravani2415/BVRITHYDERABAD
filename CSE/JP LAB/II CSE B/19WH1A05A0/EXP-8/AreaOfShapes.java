import java.util.*;

abstract class Shape {
	public int x, y;

	public abstract void Area();
}

class Rectangle extends Shape {
	public void Area() {
		float a;
		a = x * y;
		System.out.println("Area of Rectangle is " + a);
	}
}

class Triangle extends Shape {
	public void Area() {
		float a;
		a = (x * y) / 2;
		System.out.println("Area of Triangle is " + a);
	}
}

class Circle extends Shape {
	public void Area() {
		float a;
		a = (22 * x * x) / 7;
		System.out.println("Area of Circle is " + a);
	}
}

public class AreaOfShapes {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter values : ");
		int x1 = sc.nextInt();
		int y1 = sc.nextInt();
		Rectangle r = new Rectangle();
		r.x = x1;
		r.y = y1;
		r.Area();
		Triangle t = new Triangle();
		t.x = x1;
		t.y = y1;
		t.Area();
		Circle c = new Circle();
		c.x = x1;
		c.Area();
	}
}
