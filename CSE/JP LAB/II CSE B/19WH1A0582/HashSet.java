import java.util.*;
import java.io.*;

public class HashSet {
   public static void main(String args[]) {
      HashSet<String> hs = new HashSet<String>();
      Scanner sc = new Scanner(System.in);
      //adding elements to hashset 
      System.out.println("Enter the number of elements to be added in the HashSet");
	int n = sc.nextInt();
	System.out.print("Enter the elements to be added : ");
	for(int i=0;i < n + 1;i++){
		String s = sc.nextLine();
		hs.add(s);
	}

      //deleting the elements
	System.out.println("Enter the element to be deleted");
	String e = sc.nextLine();
	if(hs.contains(e))
	hs.remove(e);
	else
	System.out.println("Sorry!!! Hash Set doesn't contain the entered string");
     // printing the elements
	System.out.println("Printing elements in HashSet using for each Loop");
	for(String s: hs)
		System.out.print(s + " ");
	System.out.println();
	System.out.println("Printing the elements using Iterator");
	Iterator i = hs.iterator();
	while(i.hasNext())
		System.out.print(i.next() + " ");
	System.out.println();
	}
} 
      
      

