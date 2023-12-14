#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size for the stack

class Stack 
{
	private:
	    int arr[MAX_SIZE];
	    int top;
	
	public:
	    Stack() //default constructor
		{
	        top = -1; // Initialize the top of the stack
	    }
	
	    
	    void push(int value) 
		{
	        if (top >= MAX_SIZE - 1) //if there are more elements than capacity
			{
	            cout << "Stack Overflow: Cannot push more elements onto the stack." << endl;
	            return;
	        }
	        arr[++top] = value; //now the value variable is at the top //is the last in 
	    }

	    void pop() 
		{
	        if (isEmpty()) //if there is nothing at the top //stack is empty 
			{
	            cout << "Stack is empty. Cannot pop." << endl;
	            return;
	        }
	        top--; //last out concept //element taken from the top
	    }
	
	    // Check if the stack is empty
	    bool isEmpty() //if the stack is empty //there is nothing at the top
		{
	        return top == -1;
	    }
	
	    int peek() 
		{
	        if (isEmpty()) //if there is nothing at the top //stack is empty 
			{
	            cout << "Stack is empty." << endl;
	            return -1; // Return a default value
	        }
	        return arr[top];
	    }
};

int main() 
{
    Stack myStack;
    int choice, value;

    while (true) 
	{
        cout << "Stack Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                myStack.push(value);
                break;
            case 2:
                myStack.pop();
                break;
            case 3:
                cout << "Top element: " << myStack.peek() << endl;
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

}
