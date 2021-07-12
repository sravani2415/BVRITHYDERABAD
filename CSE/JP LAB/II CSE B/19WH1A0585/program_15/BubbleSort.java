import java.util.Scanner;

public class BubbleSort {
        public static void main(String[] args) {
                int num, c = 0;
                Scanner sc = new Scanner(System.in);
                System.out.println("Enter total no.of Elements");
                num = sc.nextInt();
                int arr[] = new int [num];
                System.out.println("Enter " + num + " Elements");
		for(int i = 0; i < num; i++) {
			arr[i] = sc.nextInt();
		}
                for(int i = 0; i < num; i++) {
                        for(int j = 0; j < num - i - 1; j++) {
                                if(arr[j] < arr[j + 1]) {
                                        int temp = arr[j];
                                        arr[j] = arr[j + 1];
                                        arr[j + 1] = temp;
                                        c += 1;
                                }
                        }
                }
                System.out.println("Sorted list: ");
                for(int i = 0; i < num; i++) {
                        System.out.println(arr[i]);
                }
                System.out.println("Total no.of Swaps required: " + c);
        }
}
