import java.util.Scanner;
class QuickSort
{
    int partition(int arr[], int low, int high)
    {
        int pivot = arr[high]; 
        int i = (low-1); 
        for (int j=low; j<high; j++)
        {
          
            if (arr[j] <= pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;
  
        return i+1;
    }

    void sort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);
 
            sort(arr, low, pi-1);
            sort(arr, pi+1, high);
        }
    }
    /*static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<num; ++i)
            System.out.print(arr[i]);
        System.out.println();
    }*/
 
    public static void main(String args[])
    {
        int num;
        Scanner input = new Scanner(System.in);
        System.out.println();

        System.out.println("20WH5A0506");
        System.out.println();
        System.out.println("Enter the number of integers to sort:");
        num = input.nextInt();

        int arr[] = new int[num];
        System.out.println();
        System.out.println("Enter "+num+" integers");
        for(int i = 0; i<num; i++)
           arr[i] = input.nextInt();

        int n = arr.length;
  
        QuickSort ob = new QuickSort();
        ob.sort(arr, 0, n-1);
        System.out.println();
        System.out.println("QuickSort");
        for(int i = 0; i<num; i++)
           System.out.println(arr[i]);
        //printArray(arr);
    }
}