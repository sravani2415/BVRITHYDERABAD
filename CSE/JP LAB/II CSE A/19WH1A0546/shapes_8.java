import java.io.*;
import java.util.Scanner;

public class shapes_8 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter nos: ");
		int x1, y1;
		x1 = sc.nextInt();
		y1 = sc.nextInt();
		
		rectangle r = new rectangle();
		triangle t = new triangle();
		circle c = new circle();
		
		r.x = x1;
		r.y = y1;
		t.x = x1;
		t.y = y1;
		c.x = x1;
		c.y = y1;
		
		r.area();
		t.area();
		c.area();
	}
}

abstract class shape {
	int x, y;
	abstract void area();
}
class rectangle extends shape {
	void area() {
		float area_rectangle;
		area_rectangle = x * y;
		System.out.println("Area of rectangle = "+area_rectangle);
	}
}

class triangle extends shape {
	void area() {
		float area_triangle;
		area_triangle = x*y/2;
		System.out.println("Area of triangle = "+area_triangle);
	}
}

class circle extends shape {
	void area() {
		double area_circle;
		area_circle = 3.14 * x * x;
		System.out.println("Area of circle = "+area_circle);
	}
}