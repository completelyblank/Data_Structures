#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int i = l; //iterator for first subarray
    int j = m + 1; //iterator for second subarray
    int k = l; //iterator for the array we are going to enter the sorted elements in
    int output[r + 1]; //sorted elements holder

    while (i <= m && j <= r) 
	{
        if (arr[i] < arr[j]) //if the first subarray element is smaller than the second subarray element
		{
            output[k] = arr[i]; //the smaller element is now in the index of the sorted array
            i++; //now we will move on to the next index of the first subarray so we can compare it to the second subarray element
        } 
		else //if the second subarray element is smaller than the first subarray element
		{	
            output[k] = arr[j]; //the smaller element is now in the index of the sorted array
            j++; //now we will move on to the next index of the second subarray so we can compare it to the first subarray element
        }
        k++; //element gone in the array, now we move on to the next comparision
    }

    while (i <= m) //until the iterator reaches the middle
	{
        output[k] = arr[i]; //copy the left sided elements in the array
        i++; //left subarray index increment
        k++; //sorted array index increment
    }

    while (j <= r) //until the iterator reaches the end
	{
        output[k] = arr[j]; //copy the right sided elements in the array
        j++; //right subarray index increment
        k++; //sorted array index increment
    }

    for (int s = l; s <= r; s++) 
	{
        arr[s] = output[s]; //sorted array now entering the sorted elements back into the orignal array
    }
}

void mergeSort(int arr[], int l, int r) 
{
    if (l < r) //if the left index is smaller than the right index //obvious unless mistake made
	{
        int mid = l + (r - l) / 2; //mid index found
        mergeSort(arr, l, mid); //merge sort done until mid
        mergeSort(arr, mid + 1, r); //merge sort done until end
        merge(arr, l, mid, r); //subarrays merged from left to right to finish the code
    }
}

int main() 
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements separated by spaces: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

