#include <iostream>
using namespace std;

/* Factorial
Suppose number is 4 (4! = 4 * 3 * 2 * 1 = 24)

1) First call = factorial(4) --- returns 4 * factorial(3)
2) Second call = factorial(3) --- returns 3 * factorial(2)
3) Third call = factorial(2) --- returns 2 * factorial(1)
4) Fourth call = factorial(1) --- returns 1 * factorial(0)
5) Fifth call = factorial(0) --- returns 1

Go from bottom to top, subsituting each call in the above call:

4) Fourth call returns 1 * fifth call = 1 * 1 = 1
3) Third call returns 2 * fourth call = 2 * 1 = 2
2) Second call returns 3 * third call = 3 * 2 = 6
1) First call returns 4 * second call = 4 * 6 = 24 --- result of factorial

*/
int factorial(int n) 
{
    if (n == 0) //base case
	{
        return 1;
    } 
	else //recursion
	{	
        
        return n * factorial(n - 1); //(n-1) part will be called until n-1 =0
    }
}

int fibonacci(int n) 
{
    if (n <= 1) //base case //fibonacci series for 1 or less numbers can't be created, it starts as 0, 1, 1, 2 ....
	{
        return n; 
    } 
	else 
	{
        return fibonacci(n - 1) + fibonacci(n - 2); //last number + second last number
    }
}

int sumOfNaturalNumbers(int n) 
{
    if (n == 1) 
	{
        return 1;
    } 
	else 
	{
        return n + sumOfNaturalNumbers(n - 1);//last number + (last number -1) + (last number-1) + (last number-1 -1) ......
    }
}

//we assume array is sorted in ascending order
int binarySearch(int arr[], int low, int high, int target) 
{
    if (low > high) 
	{
        return -1; // Element not found
    }
    int mid = (low + high) / 2; //array middle index
    
    if (arr[mid] == target) 
	{
        return mid; // Element found at index mid
    } 
	
	else if (arr[mid] > target) //we are at a higher index than the target
	{
        return binarySearch(arr, low, mid - 1, target); // Search in the left half one at a time until we find the target
    } 
	else //we are at a lower index than the target
	{
        return binarySearch(arr, mid + 1, high, target); // Search in the right half one at a time until we find the target
    }
}

void towerOfHanoi(int n, char first_tower, char middle_tower, char destination_tower) 
{
    if (n == 1) //only one disk so we can move directly from the first tower to the destination tower
	{
        cout << "Move disk 1 from " << first_tower << " to " << destination_tower << endl;
        return;
    }
    towerOfHanoi(n - 1, first_tower, destination_tower, middle_tower); //move top disk from first to middle 
    cout << "Move disk " << n << " from " << first_tower << " to " << destination_tower << endl;
    towerOfHanoi(n - 1, middle_tower, first_tower, destination_tower);  //move top disk from middle to destination tower
    //done until no disks at first tower
    
}

int main() 
{
    int number;
	int array[number];
	int target;
    cout << "Enter the source number for all the recursive function (For how much the recursion will go on): ";
    cin >> number;
    for (int i=0; i<number; i++)
    {
    	cout << "Enter a non-negative integer: ";
    	cin >> array[i];
	}
	cout << "Enter the target: ";
	cin >> target;
    
    

    if (number < 0) 
	{
        cout << "Negative numbers don't have factorials." << endl;
    } 
	
	else 
	{
        int factorial_result = factorial(number);
        cout << "Factorial of " << number << " is: " << factorial_result << endl;
        int sum_result = sumOfNaturalNumbers(number);
        cout << "Sum of numbers up to " << number << " is: " << sum_result << endl;
        int fibonacci_result = fibonacci(number);
        cout << "Fibonacci of " << number << " is: " << fibonacci_result << endl;
        int binarySearch_result = binarySearch(array, 0, number - 1, target);
        if (binarySearch_result != -1) //means not found
		{
            cout << "Binary Search found " << target << " at index " << binarySearch_result << endl;
        } 
		else 
		{
            cout << "Binary Search didn't find: " << target << endl;
        }
        towerOfHanoi(number, 'A', 'B', 'C');
    }
}
