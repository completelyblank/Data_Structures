#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) //first element loop
    {
		key = arr[i]; //temp value given to i index at start
		j = i - 1; //j is the index which is left to the i index

		while (j >= 0 && arr[j] > key) // when the (being compared) array is greater than the temp value
        {
			arr[j + 1] = arr[j]; //the (being compared) array will be sent up the array index (i.e: from 0 index to 1 index)
			j = j - 1; //j will now be decremented to be compared down the array (i.e: from 1 to 0 index)
		}
		arr[j + 1] = key; //now the next element will be assigned the temp value
	}
}

//print the array
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Driver code
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
	insertionSort(arr, num_elements);
	printArray(arr, num_elements);

	return 0;
}

