import java.util.*;

public class arraylist {

	public static void main(String[] args) {
		ArrayList<String> alist = new ArrayList<String>();
		alist.add("BVRIT");
		alist.add("Hyderabad");
		alist.add("college of Engineering");
		alist.add("for women");
		alist.remove("for women");
		System.out.println("Elements in ArrayList: " + alist);
		Iterator<String> itr = alist.iterator();
		System.out.println("Elements in ArrayList using Iterator : ");
		while(itr.hasNext())
		{
			String i = (String)itr.next();
			System.out.println(i);
		}
		System.out.println("Elements in ArrayList using for each loop : ");
		alist.forEach((n) -> System.out.println(n));
	}}