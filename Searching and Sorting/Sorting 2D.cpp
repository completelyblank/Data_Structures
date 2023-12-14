#include <iostream>
using namespace std;

// Function to perform Insertion Sort 
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
                	swapped=true; //swapped is true for the loop checking
				}
        }
 
        if (swapped=false) //if there is no need for swapping anymore, the loop will end //the elements have been swapped
        {
        	break;	
		}
    }
}

// Function for Selection sort
void selectionSort(int arr[], int n)
{
    int i, j, min_index;
 
    for (i = 0; i < n - 1; i++) //first elemnt loop
    {
        min_index = i; //we keep one aray as the comparator
        for (j = i + 1; j < n; j++) //j loop for checking ahead of the comparator
        {
            if (arr[j] < arr[min_index]) //comparision
            {
            	min_index = j; //new comparator
			}     
        }
        
        if (min_index != i) //if the minimum index is not the first element //usecase
        {
        	swap(arr[min_index], arr[i]); //swap the first place element with the minimum element
		}
			
    }
}

// Function to perform Comb Sort 
void combSort(int arr[], int size) 
{
    int gap = size; //gap is the size of the array
    bool swapped = true; //swapped is true to ensure loop runs

    while (gap > 1 || swapped) //until gap is greater than one or elements are swapped
	{
        gap = (gap * 10) / 13; //gap formula
        if (gap < 1) //if gap goes less than one // the gap between the elements goes into neg or 0
		{
            gap = 1; //gap will automatically be 1 to ensure the loop will run
        }

        swapped = false; //no swapping has occured so swap is false
        for (int i = 0; i < size - gap; i++) // i starts from 1, and goes until until the second last element
		{
            if (arr[i] > arr[i + gap]) //if the left element is greater than the right element
			{
                swap(arr[i], arr[i + gap]); //swapped
                swapped = true; //swapped is true
            }
        }
    }
}

//Function for Shell sort
void shellSort(int arr[], int n)
{
    for (int gap=n/2; gap>0; gap/=2) //gap is half the number of elements in the array, which is halved in every iteration
    {
    	for (int i=gap; i<n; i++) //i will be iterated from the gap to the number of elements
    	{
    		int temp=arr[i]; //temp wll be assigned the array element and will make a hole in that position
    		int j;
    		
    		for (j=i; j>=gap && arr[j-gap]>temp; j-=gap) //the elements sorted will be shifted until array i index is found
    		{
    			arr[j]=arr[j-gap]; //
			}
			arr[j]=temp; //hole from earlier will now be filled
		}
	}
}
int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    // Input the 2D array
    cout << "Enter the elements of the 2D array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    int choice;
    cout << "Select a sorting technique:" << endl;
    cout << "1. Insertion Sort" << endl;
    cout << "2. Bubble Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Comb Sort" << endl;
    cout << "5. Shell Sort" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) 
	{
        case 1:
        	//Insertion
            for (int i = 0; i < rows; i++) 
			{
                insertionSort(arr[i], cols);
            }
            break;
        case 2:
        	//Bubble
            for (int i = 0; i < rows; i++) 
			{
                bubbleSort(arr[i], cols);
            }
            break;
        case 3:
        	//Selection
            for (int i = 0; i < rows; i++) 
			{
                selectionSort(arr[i], cols);
            }
            break;
        case 4:
        	//Comb
            for (int i = 0; i < rows; i++) 
			{
                combSort(arr[i], cols);
            }
            break;
        case 5:
        	//Shell
            for (int i = 0; i < rows; i++) 
			{
                shellSort(arr[i], cols);
            }
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
    }

    //Display the sorted 2D array
    cout << "Sorted 2D array:" << endl;
    for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < cols; j++) 
		{
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory
    for (int i = 0; i < rows; i++) 
	{
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
