import java.util.Scanner;
class bubble_sort{
	public static void main(String args[]){
	int i,j,num,temp;
	Scanner input = new Scanner(System.in);
	System.out.println("Enter the numbers\n");
	num = input.nextInt();
	int a[] = new int[num];
	System.out.println("Enter the numbers");
	for(i=0;i<num;i++)
	{
		a[i] = input.nextInt();
	}	
	for(i=0;i<num-1;i++)
	{	
		for(j=0;j<num-1-i;j++)
		{
			if(a[j] < a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
		}
	}
	for(i=0;i<num;i++)
	System.out.println(a[i]);}
}
	
