import java.util.Scanner;
public class BubbleSort {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int n,i,j,temp;
        System.out.println("Enter number of integers to sort: ");
        n=scan.nextInt();
        System.out.println("Enter the "+ n +" elements");
        int arr[] = new int[n];
        for(i=0;i<n;i++){
            arr[i]=scan.nextInt();
        }
        for(i=0;i<n-1;i++){
            for(j=0;j<n-1-i;j++){
                if(arr[j]<arr[j+1]){
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        System.out.println("The sorted integers are : ");
        for(i=0;i<n;i++) {
            System.out.print(arr[i]+"\t");
        }
    }
}