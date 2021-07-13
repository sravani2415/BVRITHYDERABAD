import java.util.Scanner;

public class Bubble_sort
{
	public static void main(String[ ] args)
	{
		int n;
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the number of integers");
		n = input.nextInt();
		int a[ ] = new int[n];
		System.out.println("Enter the integers:");
		for(int i=0;i<n;i++)
			a[i] = input.nextInt();
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<n-i-1;j++)
			{
				if(a[j] < a[j+1])
				{
					int t = a[j];
					a[j] = a[j+1];
					a[j+1] = t;
				}
			}
		}
		System.out.println("The sorted integers are:");
		for(int i=0;i<n;i++)
			System.out.println(a[i]);
	}
}
		