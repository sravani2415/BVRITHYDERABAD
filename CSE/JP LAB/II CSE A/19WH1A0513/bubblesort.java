import java.io.*;
import java.util.Scanner;

public class bubblesort{
    public static void main(String args[]){
        System.out.println("19WH1A0513");
        System.out.println("Enter number of elements:");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter integers:");
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }        
        int temp,swapcount=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j] > arr[j+1]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    swapcount += 1;
                }
            }
        }  
        System.out.println("Sorted list in descending order:");
        for(int i=n-1;i>=0;i--){
            System.out.println(arr[i]);
        }
        System.out.println("Number of swaps = " + swapcount);
    }
}
            
        
    



