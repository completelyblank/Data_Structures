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
 
// Printing the array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++) 
    {
        cout << arr[i] << "";
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
    bubbleSort(arr, num_elements);
    cout << "Sorted array: \n";
    printArray(arr, num_elements);
}
