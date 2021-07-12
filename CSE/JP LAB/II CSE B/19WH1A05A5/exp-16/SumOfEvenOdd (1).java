import java.sql.SQLOutput;
import java.util.Scanner;

public class SumOfEvenOdd {
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        int i,n,even_sum=0,odd_sum=0;
        System.out.println("Enter the number of elements: ");
        n=scan.nextInt();
        int arr[]=new int[n];
        System.out.println("Enter "+n+" elements: ");
        for(i=0;i<n;i++){
            arr[i]=scan.nextInt();
            if(arr[i] % 2 ==0){
                even_sum+=arr[i];
            }
            else{
                odd_sum+=arr[i];
            }
        }
        System.out.println("The sum of even numbers are : "+even_sum);
        System.out.println("The sum of odd numbers are : "+odd_sum);
    }
}