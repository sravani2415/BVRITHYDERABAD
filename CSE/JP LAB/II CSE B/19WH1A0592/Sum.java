import java.util.Scanner;

public class Sum
{
	public static void main(String[ ] args)
	{
		int n,i,even_sum=0,odd_sum=0;
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the number of integers");
		n = input.nextInt();
		int a[ ] = new int[n];
		System.out.println("Enter the integers:");
		for(i=0;i<=n;i++)
			a[i] = input.nextInt();
		for(i=0;i<=n;i++)
		{
			if(i % 2 == 0)
			{
				even_sum = even_sum+i;
			}
			else
			{
				odd_sum = odd_sum+i;
			}
		}
		System.out.println("The sum of even numbers:" + even_sum);
		System.out.println("The sum of odd numbers:" + odd_sum);
	}
}