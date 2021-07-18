import java.io.*;
import java.util.Scanner;

abstract class shape{
    int a,b;
    public abstract void printArea();
}
class rectangle extends shape{
    public void printArea(){
        System.out.println("Area of a rectangle is " + a * b);
    }
}
class triangle extends shape{
    public void printArea(){
        System.out.println("Area of a triangle is " + (float)(a*b)/2);
    }
}
class circle extends shape{
    public void printArea(){
        System.out.println("Area of a circle is " + (3.14*a*a));
    }
}
public class myshape{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int x,y;
        System.out.println("Enter the dimensions: ");
        x = sc.nextInt();
        y = sc.nextInt();
        rectangle obj1 = new rectangle();
        obj1.a=x;
        obj1.b=y;
        obj1.printArea();
        triangle obj2 = new triangle();
        obj2.a=x;
        obj2.b=y;
        obj2.printArea();
        circle obj3 = new circle();
        obj3.a=x;
        obj3.b=y;
        obj3.printArea();
    }
}
