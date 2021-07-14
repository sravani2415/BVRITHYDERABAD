import java.util.Scanner;

public class MyShapes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter values : ");
        int x1 = sc.nextInt();
        int y1 = sc.nextInt();
        Rectangle r = new Rectangle();
        r.x = x1;
        r.y = y1;
        r.printArea();
        Triangle t = new Triangle();
        t.x = x1;
        t.y = y1;
        t.printArea();
        Circle c = new Circle();
        c.x = x1;
        c.printArea();
    }
}
