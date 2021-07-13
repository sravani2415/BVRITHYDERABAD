import java.io.*;
import java.util.Scanner;

class linkedlist 
{
	int data;
	linkedlist prev;
	linkedlist next;

	linkedlist(int value) 
	{
		this.data = value;
	}

	void display()
	 {
		System.out.println(data);
	}
}

class linked 
{
	public linkedlist firstnode, lastnode;

	linked() 
	{
		firstnode = null;
		lastnode = null;
	}

	/* Insert node at the beginning or create linked list */
	void insert_front(int value) 
	{
		linkedlist node = new linkedlist(value);
		if (firstnode == null)
		 {
			node.prev = node.next = null;
			firstnode = lastnode = node;
			System.out.println("Linked list created successfully!");
		} 
		else 
		{
			node.prev = null;
			node.next = firstnode;
			firstnode.prev = node;
			firstnode = node;
			System.out.println("Node Inserted at the front of the Linked list!");
		}
	}

	/* Insert node at the end or create linked list */
	void insert_end(int value) 
	{
		linkedlist node = new linkedlist(value);
		if (firstnode == null) 
		{
			node.prev = node.next = null;
			firstnode = lastnode = node;
			System.out.println("Linked list created successfully!");
		} 
		else
		 {
			node.next = null;
			node.prev = lastnode;
			lastnode.next = node;
			lastnode = node;
			System.out.println("Node Inserted at the end of the Linked list!");
		}
	}

	/* Delete node from linked list */
	void delete() 
	{
		int count = 0, number, i;
		linkedlist node, node1, node2;
		Scanner input = new Scanner(System.in);

		for (node = firstnode; node != null; node = node.next)
			count++;
		display();
		node = node1 = node2 = firstnode;
		System.out.println(count + " nodes available here!");
		System.out.println("Enter the node number which you want to delete from ascending order list:");
		number = Integer.parseInt(input.nextLine());
		if (number != 1) 
		{
			if (number < count && number > 0)
			 {
				for (i = 2; i <= number; i++)
					node = node.next;
				for (i = 2; i <= number - 1; i++)
					node1 = node1.next;
				for (i = 2; i <= number + 1; i++)
					node2 = node2.next;
				node2.prev = node1;
				node1.next = node2;
				node.prev = null;
				node.next = null;
				node = null;
			} 
			else if (number == count) 
			{
				node = lastnode;
				lastnode = node.prev;
				lastnode.next = null;
				node = null;
			} 
			else
				System.out.println("Invalid node number!\n");
		}
		 else
		 {
			node = firstnode;
			firstnode = node.next;
			firstnode.prev = null;
			node = null;
		}

		System.out.println("Node has been deleted successfully!\n");
	}

	/* Display linked list */
	void display() 
	{
		linkedlist node = firstnode;
		System.out.println("List of node in Ascending order!");
		while (node != null) 
		{
			node.display();
			node = node.next;
		}

		node = lastnode;
		System.out.println("List of node in Descending order!");
		while (node != null) 
		{
			node.display();
			node = node.prev;
		}
	}
}

class doublelinkedlist 
{
	public static void main(String args[]) 
	{
		linked list = new linked();
		Scanner input = new Scanner(System.in);
		int op = 0;
		while (op != 5) 
		{
			System.out.println("1.Insert at front\n2.Insert at back\n3.Delete\n4.Display\n5.Exit");
			System.out.println("Enter your choice:");
			op = Integer.parseInt(input.nextLine());
			switch (op) 
			{
			case 1:
				System.out.println("Enter the positive value for Linked list:");
				list.insert_front(Integer.parseInt(input.nextLine()));
				break;
			case 2:
				System.out.println("Enter the positive value for Linked list:");
				list.insert_end(Integer.parseInt(input.nextLine()));
				break;
			case 3:
				list.delete();
				break;
			case 4:
				list.display();
				break;
			case 5:
				System.out.println("Exit");
				System.exit(0);
				break;
			default:
				System.out.println("Invalid choice!");

			}
		}
	}
}
