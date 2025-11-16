using System;

class InsertionSort
{
    public static void InsertSort(int[] arr)
    {
        int n = arr.Length;
        for (int i = 1; i < n; i++)
        {
            int key = arr[i];
            int j = i - 1;
            
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    
    public static void PrintArray(int[] arr)
    {
        foreach (int element in arr)
        {
            Console.Write(element + " ");
        }
        Console.WriteLine();
    }
    
    public static void Main(string[] args)
    {
        int[] arr = {64, 34, 25, 12, 22, 11, 90, 100, 0, -1, -5};
        
        Console.WriteLine("Original array:");
        PrintArray(arr);
        
        InsertSort(arr);
        
        Console.WriteLine("Sorted array:");
        PrintArray(arr);
    }
}