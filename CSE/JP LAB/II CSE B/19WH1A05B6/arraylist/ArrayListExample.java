// program for Array List operations like add,del,itterating over foreach loop and iterator
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;


public class ArrayListExample {
    public static void main(String args[]){
        ArrayList<Integer> a1 = new ArrayList(15);
        for(int i=0;i<13;i++){
            a1.add((i+1)*10);
        }
        a1.add(1,15);
        a1.add(5,55);
        System.out.println("Elements before deletion");
        //Displaying elements Using For each loop
        for (Integer elements : a1) {
            System.out.println(elements);
        }
        Random r = new Random();
        for (int i=0;i<5;i++) {
            int a = r.nextInt(10);
            System.out.println("removing element " + a1.get(a));
            a1.remove(a);
        }
        System.out.println("Elements after deletion");
        //Displaying elements using Iterator
        Iterator<Integer> i = a1.iterator();
        while(i.hasNext()){
            System.out.println(i.next());
        }
    }
}
