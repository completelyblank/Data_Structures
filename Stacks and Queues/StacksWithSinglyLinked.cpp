#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size for the stack

class Node 
{
	public:
	    int data;
	    Node* next;
	
	    Node(int value) //parameterized constructor
		{
	        data = value;
	        next = NULL;
	    }
};
class Stack 
{
	private:
	    Node* top; //all elements are in nodes and the top node is like the head node of a linked list
	
	public:
	    Stack() //default constructor
		{
	        top = NULL; //top/head node has no element at the beginning
	    }
	
	    void push(int value) 
		{
	        Node* newNode = new Node(value); //node made which has the value in it
	        newNode->next = top; //node pushed at top node
	        top = newNode; //top node is now the new node
	        cout << "Pushed " << value << " onto the stack." << endl;
	    }
	
	    void pop() 
		{
	        if (isEmpty()) //if there is nothing at the top, meaning the list is empty
			{
	            cout << "Stack is empty. Cannot pop." << endl;
	            return;
	        }
	        Node* temp = top; //temp node made at top
	        top = top->next; //top is now the second last element //first in last out concept
	        cout << "Popped " << temp->data << " from the stack." << endl;
	        delete temp; //temp node which was the temporary top node, is now popped
	    }
	
	    bool isEmpty() 
		{
	        return top == NULL; //there is nothing at the top meaning the list/stack is empty
	    }
	
	    int peek() 
		{
	        if (isEmpty()) //if there is nothing at the top //list/stack is empty
			{
	            cout << "Stack is empty." << endl;
	            return -1;
	        }
	        return top->data; //we can look at the top most data 
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

