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

