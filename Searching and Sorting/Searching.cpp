#include <iostream>
using namespace std;

// Function for Selection sort
void bubbleSort(int arr[], int n)
{
    int i, j;
 	bool swapped;
    for (i = 0; i < n - 1; i++) //Loop for first element
    {
 		swapped=false;
        for (j = 0; j < n-2; j++) //Loop for second element
        {
            if (arr[j] > arr[j+1]) //comparing element with the right hand side element
                {
                	swap(arr[j], arr[j+1]); //switching values
                	swapped=true;	
				}
				
        }
 
        if (swapped=false)
        {
        	break;	
		}
    }
}


int linearSearch(int arr[], int size, int target) 
{
    for (int i = 0; i < size; ++i) //starts from the start, and ends at end
	{
        if (arr[i] == target) //basic if
		{
            return i;
        }
    }
    return -1; //if target not found
}

int binarySearch(int arr[], int size, int target) //requires sorted array (ascending)
{
    int left = 0; //left index
    int right = size - 1; //right index
    while (left <= right) //until left is smaller or equal to right
	{
        int mid = left + (right - left) / 2; //mid adjusted
        if (arr[mid] == target) //adjusted mid has target
		{
            return mid; //index returned
        }
        if (arr[mid] < target) //if mid is smaller in a sorted structure
		{
            left = mid + 1; //left will move forward //recursion
        }
		else 
		{
            right = mid - 1; //right will move backwards
        }
    }
    return -1; //target not found
}

int interpolationSearch(int arr[], int size, int target) //requires sorted array (ascending)
{
    int left = 0; //left starts from 0th index
    int right = size - 1; //right is the max index
    while (left <= right && arr[left] <= target && arr[right] >= target) //until left is smaller or equal to right //array from left side is smaller than the target and array from right side is greater than the target
	{
        int mid = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]); //interpoaltion fromula
        if (arr[mid] == target) //if the adjusted mid has target
		{
            return mid;
        }
        if (arr[mid] < target) //if adjusted mid is smaller than target
		{
            left = mid + 1; //left moves forward
        }
		else 
		{
            right = mid - 1; //right moves backwards
        }
    }
    return -1; //target not found
}

int main() 
{
    using namespace std;

    int n;
    cout << "Enter the number of elements in the sorted array: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) 
	{
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int choice;
    while (true) 
	{
        cout << "\nSearch Options:" << endl;
        cout << "1. Linear Search" << endl;
        cout << "2. Binary Search" << endl;
        cout << "3. Interpolation Search" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 4) 
		{
            break;
        }

        int target;
        cout << "Enter the target element to search: ";
        cin >> target;

        int result = -1;
        if (choice == 1) 
		{
			
            result = linearSearch(arr, n, target);
        } 
		else if (choice == 2) 
		{
			bubbleSort(arr, n);
            result = binarySearch(arr, n, target);
        }
		else if (choice == 3) 
		 {
		 	bubbleSort(arr, n);
            result = interpolationSearch(arr, n, target);
        }
		else 
		{
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        if (result != -1) 
		{
            cout << "Element " << target << " found at index " << result << "." << endl;
        } 
		else 
		{
            cout << "Element " << target << " not found in the array." << endl;
        }
    }

}

