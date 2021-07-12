package com.bvrith.csec;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Calendar;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.Enumeration;
import java.util.Formatter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Properties;
import java.util.Queue;
import java.util.Random;
import java.util.Set;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.Vector;

public class CollectionsDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		// List = homo+het, size is growable, allow duplicates  , hold null values, ordered
	
		ArrayList<Integer> list=new ArrayList();  //10
		Integer i=new Integer(10);
		//Character c1=new Character('f');
		list.add(i);
		//list.add("one");
		list.add(2);
		//list.add(10.10);
		//list.add(true);
		//list.add('c');
		list.add(5);
		list.add(3);
		list.add(6);
		
		
		System.out.println(list.size());
		System.out.println(list);
	//	System.out.println(list.remove(2));
		list.add(5, 1);
		System.out.println("the data in ArrayList is"+list);
		
		LinkedList llist=new LinkedList();
		llist.add("one");
		llist.add(2);
		llist.add(10.10);
		llist.add(true);
		llist.add('c');
		llist.add(2);
		llist.addFirst(1);
		llist.addAll(list);
		System.out.println("the data in Linked Lisst is"+llist);
		System.out.println(llist.poll());
		System.out.println(llist);
		
		
		Vector v=new Vector();   //Java1.0v= Lagacy=synchronized
		System.out.println("initial cap of vector"+v.capacity());
		v.add("one");
		v.addAll(list);
		v.addAll(list);
		System.out.println("now the size of vector is"+v.size());
		System.out.println("now the capacity of vector"+v.capacity());
		System.out.println(v);
		
		
		Stack myStack=new Stack();   //Java1.0=Legacy=synch
		myStack.push("one");
		myStack.push(2);
		myStack.push(3.0);
		myStack.push(4);
		System.out.println("the  data of stack"+myStack);
		System.out.println("the top is"+myStack.peek());
		myStack.pop();
		System.out.println("now the  data of stack after pop"+myStack);
		myStack.get(2); //
		
		for (int j = 0; j < myStack.size(); j++) {
			System.out.println(myStack.get(j));
		}
		
		for (Object object : myStack) {
			System.out.println(object);
		}
		
		//Cursors=Enumeration-->Legacy, ListIterator-->List, Iterator-->all
		System.out.println("========Cursors=========for fetching data from collection object");
		Enumeration enumeration=v.elements();
		while (enumeration.hasMoreElements()) {
			System.out.println(enumeration.nextElement());
		}
		
		ListIterator ltr=list.listIterator();
		while (ltr.hasNext()) {
			 System.out.println("data from ArryaList is"+ltr.next());
		}
		
		Iterator itr=llist.iterator();
		while (itr.hasNext()) {
			System.out.println("data from LinkedList using Iterator"+itr.next());
		}
		
		HashSet set =new HashSet();
		set.add("one");
		set.add(new Student());
		set.add(10);
		set.add(45.30);
		set.add("one");
		set.addAll(list);
		set.add(null);
		set.add(null);
		System.out.println("the data in Set object is"+set);
		
		
		LinkedHashSet lset=new LinkedHashSet(list);
		lset.add(null);
		System.out.println(lset);
		
		TreeSet tset=new TreeSet(new TestOrder());
		tset.add(30);
		tset.add(10);
		tset.add(20);
		tset.add(5);
		System.out.println(tset);
		
		
		PriorityQueue pq=new PriorityQueue();
		pq.add("one");
		pq.add("two");
		pq.add("three");
		pq.add("four");
		System.out.println(pq); 
		System.out.println(pq.peek()); 
		System.out.println(pq.poll()); 
		System.out.println(pq); 
		System.out.println(pq.peek()); 
		System.out.println(pq.element()); 
		
		
		ArrayDeque ad=new ArrayDeque();
		ad.addAll(list);
		System.out.println("elements in Deq are:"+ad);
		ad.addFirst("front");
		System.out.println(ad);
		System.out.println(ad.element());
		ad.addLast("last");
		System.out.println(ad);
		System.out.println(ad.peek());  //front
		System.out.println(ad.peekFirst());  //front
		System.out.println(ad.peekLast());  //2
		
		
		ArrayList<Student> myList=new ArrayList();
		myList.add(new Student());
		
		HashMap hm=new HashMap();
		hm.put(1, "one");
		hm.put(2, "two");
		hm.put(3, "three");
		//hm.put(10.20, "one");
		//hm.put("four", 4);
		hm.put(1, "oneone");
		//hm.put(null, "oneone");
		System.out.println(hm);
		System.out.println(hm.get(3));
		System.out.println(hm.replace(2, "twotwo"));
		System.out.println(hm.keySet());
		System.out.println(hm.values());
		System.out.println(hm);
		Set mapset=hm.entrySet();  // map is converted into set
		Iterator setitr=mapset.iterator();
		while (setitr.hasNext()) {
			Entry m=(Entry) setitr.next();
			System.out.println(m.getKey()+"\t"+m.getValue());
		}
		
		
		LinkedHashMap lmap=new LinkedHashMap(hm);
		lmap.put(10, "ten");
		lmap.put(11, "elev");
		lmap.put(12, "twelv");
		lmap.put(6, "six");
		lmap.put(5, "five");
		lmap.put(9, "nine");
		
		System.out.println("data in LMap are:"+lmap);
		
		
		TreeMap treeMap =new TreeMap<>(new TestOrder());
		treeMap.putAll(lmap);
		System.out.println(treeMap);   //
		
		
		Hashtable ht=new Hashtable<>();
		ht.put(1, "one");
		ht.put(2, "two");
		ht.put(3, "three");
		ht.put(10.20, "one");
		ht.put("four", 4);
		ht.put(1, "oneone");
		ht.put(11, "oneone");
		System.out.println("the data in HT are:"+ht);
		// HM is allowing null,HT is not allowing null
		
		Properties prop=new Properties();
		prop.put(1, 101);
		prop.putAll(ht);
		System.out.println(prop);
		
		try {
			FileReader fr=new FileReader("students.properties");
			prop.load(fr);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("after loading from prop file:"+prop);
		System.out.println(prop.getProperty("195h1"));
		System.out.println("before sorting ArrayList:"+list);
		int a[]=new int[list.size()];
		for (int j = 0; j < list.size(); j++) {
			a[j]=list.get(j);
		}
		Arrays.sort(a);
		for (int j = 0; j < a.length; j++) {
			System.out.print(a[j]+"\t");
		}  
		System.out.println("");
		System.out.println(Arrays.binarySearch(a, 5));
		
		
		Collections.sort(list);
		System.out.println("after sorting list:"+list);
		Collections.shuffle(list);
		System.out.println("after shuffle the list is:"+list);
		Collections.reverse(list);
		System.out.println("after reversing the list is:"+list);
		
		
		Random random=new Random();
		System.out.println(random.nextInt());
		System.out.println(tset);
		System.out.println("list data:"+list);
		System.out.println(treeMap);   //
		
		
		BitSet bs=new BitSet();
		bs.set(0);
		bs.set(3);
		bs.set(5);
		bs.set(6);
		bs.set(15);
		
		System.out.println(bs.get(0));  // true
		System.out.println(bs.get(1));  //
		System.out.println(bs.get(2));  //
		System.out.println(bs.get(3));  //true
		System.out.println(bs.get(5));  //true
		System.out.println(bs.get(15));  //true
		System.out.println(bs);
		
		Date date=new Date();
		System.out.println(date.getTime());
		
		System.out.println(Calendar.getInstance().getTime());
		
		Formatter form=new Formatter();
		System.out.println(form.format("%c", 96));
		
		
		
		
	}
}

class TestOrder implements Comparator{

	@Override
	public int compare(Object o1, Object o2) {
		// TODO Auto-generated method stub
		int i1=(int)o1;
		int i2=(int)o2;
		
		if(i1<i2) {
			return +1;
		}else if(i1>i2) {
			return -1;
		}else {
			return 0;
		}
		
	}
	
}



