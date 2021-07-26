import java.io.*;
import java.util.*;

abstract class shape{
	int len,bre,r;
	Scanner input = new Scanner(System.in);
	abstract void Area();
}

class rectangle extends shape{
	void Area(){
		System.out.println("Enter the length and breadth of rectangle:");
		len = input.nextInt();
		bre = input.nextInt();
		System.out.println("The area of Rectangle is:"+len*bre);
	}
}

class circle extends shape{
	void Area(){
		System.out.println("Enter the radius of circle:");
                r = input.nextInt();
		System.out.println("The area of circle is:"+ 3.14 * r * r);
	}
}

class triangle extends shape{
	void Area(){
		System.out.println("Enter the length and breadth of triangle:");
                len = input.nextInt();
                bre = input.nextInt();
		System.out.println("The area of triangle is:"+ (len+bre)/2);
	}
}

public class abstractclass{
	public static void main(String args[]){
		rectangle rec = new rectangle();
		rec.Area();

		triangle tri = new triangle();
		tri.Area();

		circle c = new circle();
		c.Area();
	}
}





