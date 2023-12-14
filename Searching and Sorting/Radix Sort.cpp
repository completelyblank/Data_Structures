#include <iostream> 
using namespace std; 

int getMax(int arr[], int n) //find the greatest number in the array
{ 
	int mx = arr[0]; //intialize the max as the first element, can do for any element tbh
	for (int i = 1; i < n; i++) 
	{
		if (arr[i] > mx) //comparision to make new max if the other element is greater than the current max
		{
			mx = arr[i]; 
		}
	}
		return mx; 
} 

void countSort(int arr[], int n, int exp) 
{ 
	int output[n]; // Output array made
	int i, count[10] = { 0 }; //count array made to store count of all digits from 0-9 //initialized as 0 for all digits

	for (i = 0; i < n; i++)
	{
		count[(arr[i] / exp) % 10]++; //if a digit is found, like 7, it will increment the 8th index in the count array //as the array starts from 0
	} 
		
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1]; //store the position where elements with digit i should be placed in the output array.	
	} 
		
	for (i = n - 1; i >= 0; i--) 
	{ 
		output[count[(arr[i] / exp) % 10] - 1] = arr[i]; //value of arr[i] assigned to the output array based on the position for the rightmost digit.
		count[(arr[i] / exp) % 10]--; //digit has been used
	} 

	for (i = 0; i < n; i++)
	{
		arr[i] = output[i]; //sorted elements put back in the orignal array
	} 
} 

void radixsort(int arr[], int n) 
{ 

	 
	int m = getMax(arr, n); //greatest number found in the array
 
	for (int exp = 1; m / exp > 0; exp *= 10)
	{
		countSort(arr, n, exp); //count sort done for each digit, so if the max is 100, we will do count sort 3 times
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

    radixsort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

}






