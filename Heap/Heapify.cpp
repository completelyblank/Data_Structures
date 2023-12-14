#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i) //to put the max as the root
{
    int largest = i; //largest is at the start
    int left = 2 * i + 1; //left formula
    int right = 2 * i + 2; //right formula

    if (left < n && arr[left] > arr[largest]) //if left is smaller than n & the left element is greater than the largest index element
    {
    	largest = left;  //new largest val
	}
        

    if (right < n && arr[right] > arr[largest]) //if right is smaller than n & the right element is greater than the largest index element
    {
    	largest = right; //new largest val
	}    
	

    if (largest != i) //if largest is not the index
	{
        swap(arr[i], arr[largest]); //now largest has index val
        maxHeapify(arr, n, largest); //carries out recursion
    }
}

void deleteValue(int arr[], int n, int value) //delete val from heap
{
    for (int i = 0; i < n; ++i)  //i starts from 0 to n //linear searching
	{
        if (arr[i] == value) //if the index has the val we want to delete
		{
            arr[i] = arr[n - 1]; //index will go to second last
            --n; //array shortened by one
            maxHeapify(arr, n, i); //now will form the heap
            break; //dont need to go further
        }
    }
}

void buildMaxHeap(int arr[], int n) 
{
    int start = (n / 2) - 1; //starts from just behind the mid index

    for (int i = start; i >= 0; --i)  //i covers before the mid
	{
        maxHeapify(arr, n, i); //heap made
    }
}

void minHeapify(int arr[], int n, int i) 
{
    int smallest = i; //smallest is at index
    int left = 2 * i + 1; //left formula
    int right = 2 * i + 2; //right formula

    if (left < n && arr[left] < arr[smallest]) //if left is smaller than n & left index val is smaller than smallest index val
	{
        smallest = left; //smallest is left
    }

    if (right < n && arr[right] < arr[smallest]) //if right is smaller than n & right index val is smaller than smallest index val
	{
        smallest = right; //smallest is right
    }

    if (smallest != i) //if smallest is not index 
	{
        swap(arr[i], arr[smallest]); //swap the vals of index and smallest 
        minHeapify(arr, n, smallest); //recursion
    }
}

void buildMinHeap(int arr[], int n) 
{
    int start = (n / 2) - 1; //starts from one before the mid index

    for (int i = start; i >= 0; --i) //loop from before the mid
	{
        minHeapify(arr, n, i); //form the min heap
    }
}

void minHeapSort(int arr[], int n) 
{
    buildMinHeap(arr, n); // Build a min heap

    while (n > 1) 
	{
        swap(arr[0], arr[n - 1]); // Swap the smallest element to the end
        --n; // Decrease the heap size
        minHeapify(arr, n, 0); // Heapify the reduced heap
    }
}


void maxHeapSort(int arr[], int n) //sort
{
    buildMaxHeap(arr, n); //first make the heap
    while (n > 1) //until n <1
	{
        swap(arr[0], arr[n - 1]); //first and second last index swapped
        --n; //array shortened by 1
        maxHeapify(arr, n, 0); //heaped
    }
}

void printArray(int arr[], int n) //normal print the 1D Array
{
    for (int i = 0; i < n; ++i) 
	{
        cout << arr[i] << " ";
    }
    cout << std::endl;
}

int main() 
{
    int maxSize = 100;
    int arr[maxSize];
    int n;

    cout << "Enter the number of elements (max 100): ";
    cin >> n;

    cout << "Enter the array elements separated by spaces: ";
    for (int i = 0; i < n; ++i) 
	{
        cin >> arr[i];
    }

    int choice;
    while (true) 
	{
        cout << "\nMenu:\n";
        cout << "1. Create Max Heap\n";
        cout << "2. Create Min Heap\n";
        cout << "3. Sort Max Heap\n";
        cout << "4. Sort Min Heap\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                buildMaxHeap(arr, n);
                cout << "Max Heap: ";
                printArray(arr, n);
                break;
            case 2:
                buildMinHeap(arr, n);
                cout << "Min Heap: ";
                printArray(arr, n);
                break;
            case 3:
                maxHeapSort(arr, n);
                cout << "Sorted in Ascending Heap: ";
                printArray(arr, n);
                break;
            case 4:
                minHeapSort(arr, n);
                cout << "Sorted in Descending Heap: ";
                printArray(arr, n);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}
