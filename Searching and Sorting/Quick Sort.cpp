#include <iostream>
using namespace std;

void swap(int& a, int& b) //swapping function to save lines and time
{
    int t = a;
    a = b;
    b = t;
}

int median(int arr[], int low, int high) //make median the pivot //5% faster //Saad Carter told me this
{
    int mid = (low + high) / 2;
    if ((arr[low] - arr[mid]) * (arr[high] - arr[low]) >= 0) //if low index is the closest to the median
	{
        return low;
    } 
	else if ((arr[mid] - arr[low]) * (arr[high] - arr[mid]) >= 0) //if the mid index is the closest to the median
	{
        return mid;
    } 
	else //if the high median is the closest
	{
        return high;
    }
}

int Lowpartition(int arr[], int low, int high) //First index will be taken as pivot
{
    int pivotIndex = median(arr, low, high); //median function used
    swap(arr[pivotIndex], arr[low]); //swapping function used
    int pivot = arr[low]; //first index taken as pivot
    int i = low; //starts from lowest index
    for (int j = low + 1; j <= high; j++) 
	{
        if (arr[j] < pivot) //pivot comparision
		{
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[low]); 
    return i;
}

int Highpartition(int arr[], int low, int high) //Pivot will be last element 
{
    int pivotIndex = median(arr, low, high); //median function used
    swap(arr[pivotIndex], arr[low]); //swapping function used
    int pivot = arr[high]; //last element taken as pivot
    int i = low - 1; //i starts from what low-1 is
    for (int j = low; j < high; j++) 
	{
        if (arr[j] < pivot) //pivot comparision
		{
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int Midpartition(int arr[], int low, int high) //Pivot will be at Mid
{
    int mid = (low + high) / 2; //Mid calculation
    int pivotIndex = median(arr, low, high); //Median found of the Array
    swap(arr[pivotIndex], arr[low]); //the median and the lowest element is swapped
    int pivot = arr[mid]; //now the pivot is of the mid element since its a mid partition
    int i = low - 1; //i is one behind first element
    for (int j = low; j <= high; j++) 
	{
        if (arr[j] < pivot) //pivot comparision
		{
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[mid]);
    return i + 1;
}

int Medianpartition(int arr[], int low, int high) 
{
    int pivotIndex = median(arr, low, high); //Median found of the array
    swap(arr[pivotIndex], arr[low]); //median and lowest element swapped
    int pivot = arr[low]; //pivot taken is the low element
    int i = low; //i is first element
    for (int j = low + 1; j <= high; j++) 
	{
        if (arr[j] < pivot) //pivot comparision
		{
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[low]);
    return i;
}

void quickSort(int arr[], int low, int high, int choice) 
{
    if (low < high) //basecase kinda
	{
        int pi;
        switch (choice) 
		{
            case 1:
                pi = Lowpartition(arr, low, high);
                break;
            case 2:
                pi = Highpartition(arr, low, high);
                break;
            case 3:
                pi = Midpartition(arr, low, high);
                break;
            case 4:
                pi = Medianpartition(arr, low, high);
                break;
            default:
                cout << "Invalid choice." << endl;
                return;
        }
        quickSort(arr, low, pi - 1, choice); //first recursion of the function, of the array being sorted from high to low
        quickSort(arr, pi + 1, high, choice); //second recursion of the function, of the array being sorted from low to high
    }
}

int main() 
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << "Choose a pivot selection strategy:" << endl;
    cout << "1. Low (First element as pivot)" << endl;
    cout << "2. High (Last element as pivot)" << endl;
    cout << "3. Middle" << endl;
    cout << "4. Median of Three" << endl;

    int choice;
    cin >> choice;

    if (choice < 1 || choice > 4) 
	{
        cout << "Invalid choice." << endl;
        return 1;
    }

    quickSort(arr, 0, N - 1, choice);

    cout << "Sorted array: " << endl;
    for (int i = 0; i < N; i++) 
	{
        cout << arr[i] << " ";
    }

}
