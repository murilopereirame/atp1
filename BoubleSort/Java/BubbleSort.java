// Bubble Sort em java

public class BubbleSort{  
    static void bubbleSort(int[] array) {  
        int n = array.length;  
        int temp = 0;  
         for(int i=0; i < n; i++){  
                 for(int j=1; j < (n-i); j++){  
                          if(arr[j-1] > array[j]){  
                                   
                                 temp = array[j-1];  
                                 array[j-1] = array[j];  
                                 array[j] = temp;  
                         }  
                          
                }  
         }  

    }

public static void main(String[] args) {  
    int array[] ={2, 75, 41, 99, 105, 3, 53};
    bubbleSort(array);
    system.out.println(array);
    }  
}