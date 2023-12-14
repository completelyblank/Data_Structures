#include <iostream>

using namespace std;

const int MAX_SIZE = 5; // Maximum size for the queue

class Queue 
{
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() //default constructor
	{
        front = -1; //empty
        rear = -1; //empty
    }

    bool isEmpty() //if the front has no element
	{
        return front == -1;
    }

    bool isFull() // the rear has reached the maximum size and there is no space in the front
	{
        return (rear == MAX_SIZE - 1) && (front == 0);
    }

    void enqueue(int value) 
	{
        if (isFull()) //if true
		{
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        } 
		else if (isEmpty()) //if true
		{
            front = 0; //front has no element
        }
        arr[++rear] = value; //value pushed ahead
        cout << "Enqueued " << value << " into the queue." << endl;
    }

    void dequeue() 
	{
        if (isEmpty()) //if true
		{
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
		else if (front == rear) //if there is one one element
		{
            front = rear = -1; //emptied queue
        }
		else 
		{
            cout << "Dequeued " << arr[front] << " from the queue." << endl;
            front++; //front moved on
        }
    }

    void displayQueue() 
	{
        if (isEmpty()) //if true
		{
            cout << "Queue is empty." << endl;
        } 
		else 
		{
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) //from front to rear
			{
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() 
{
    Queue myQueue;
    int choice, value;

    while (true) 
	{
        cout << "Queue Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Display Queue" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                myQueue.enqueue(value);
                break;
            case 2:
                myQueue.dequeue();
                break;
            case 3:
                if (myQueue.isEmpty()) 
				{
                    cout << "Queue is empty." << endl;
                } 
				else 
				{
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 4:
                if (myQueue.isFull()) 
				{
                    cout << "Queue is full." << endl;
                } 
				else 
				{
                    cout << "Queue is not full." << endl;
                }
                break;
            case 5:
                myQueue.displayQueue();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

