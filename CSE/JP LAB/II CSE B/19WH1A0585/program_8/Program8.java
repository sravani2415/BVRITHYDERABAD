import java.util.Scanner;

abstract class shape {
	public int param1, param2;
	public abstract void printArea();
}

class Rectangle extends shape {
	public void printArea() {
		float area;
		area = param1 * param2;
		System.out.println("area of rectangle: " + area);
	}
}

class Triangle extends shape {
	public void printArea() {
		float area;
		area = (param1 * param2) / 2;
		System.out.println("area of triangle: " + area);
	}
}

class Circle extends shape {
	public void printArea() {
		float area;
		area = (22 / 7) * param1 * param1;
		System.out.println("area of circle: " + area);
	}
}

public class Program8 {
	public static void main(String[] args) {
		int p1, p2;
		Scanner sc = new Scanner(System.in);
                System.out.println("Enter len and wid of rectangle: ");
		p1 = sc.nextInt();
		p2 = sc.nextInt();
		Rectangle r;
		r = new Rectangle();
		r.param1 = p1;
		r.param2 = p2;
		r.printArea();
		System.out.println("Enter b and h of Triangle: ");
		p1 = sc.nextInt();
		p2 = sc.nextInt();
		Triangle t;
		t = new Triangle();
                t.param1 = p1;
		t.param2 = p2;
		t.printArea();
                System.out.println("Enter r of circle: ");
		p1 = sc.nextInt();
		Circle c;
		c = new Circle();
		c.param1 = p1;
		c.printArea();
	}
}


