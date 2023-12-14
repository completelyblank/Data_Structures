// C++ program for implementation of
// selection sort
#include <iostream>

using namespace std;
 
// Function for Selection sort
void selectionSort(int arr[], int n)
{
    int i, j, min_index;
 
    // One by one move boundary of
    // the unsorted subarray
    for (i = 0; i < n - 1; i++) 
    {
 
        // Find the minimum element in
        // unsorted array
        min_index = i;
        for (j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
 
        // Swap the found minimum element
        // with the first element
        if (min_index != i)
            swap(arr[min_index], arr[i]);
    }
}
 
// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
        cout << endl;
    }
}
 
// Driver program
int main()
{
    int num_elements;
    cout<<"How many elements are in the array? "<<endl;
    cin>>num_elements;
    int *arr=new int[num_elements];
    cout<<"Enter the elements of the array: "<<endl;
    for (int i = 0; i < num_elements; i++)
    {
        cout<<"Element "<<i<<": ";
        cin>>arr[i];
    }
    // Function Call
    selectionSort(arr, num_elements);
    cout << "Sorted array: \n";
    printArray(arr, num_elements);
    return 0;
}