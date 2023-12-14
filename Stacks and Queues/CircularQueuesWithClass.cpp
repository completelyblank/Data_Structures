#include <iostream>

using namespace std;

const int MAX_SIZE = 5; // Maximum size for the queue

class CircularQueue 
{
	private:
	    int arr[MAX_SIZE];
	    int front, rear;
	
	public:
	    CircularQueue() //default constructor
		{
	        front = rear = -1; //no elements at start
	    }
	
	    bool isEmpty() //if there is no element at the front
		{
	        return front == -1;
	    }
	
	    bool isFull() 
		{
	        return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1); //if the front has reached the left most space and rear has reached the rightmost space or the front has reached the rear
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
	            front = rear = 0; //the front and rear are connected and the space to add the element is the 0th index
	        } 
			else if (rear == MAX_SIZE - 1) //if the rear has reached the end
			{
	            rear = 0; //rear now connects with the front
	        } 
			else 
			{
	            rear++; //rear moves on
	        }
	        arr[rear] = value; //we add the value at the rear index
	        cout << "Enqueued " << value << " into the queue." << endl;
	    }
	
	    void dequeue() 
		{
	        if (isEmpty()) //if true
			{
	            cout << "Queue is empty. Cannot dequeue." << endl;
	            return;
	        }
			else if (front == rear) //if only one element
			{
	            front = rear = -1; //empty the queue
	        } 
			else if (front == MAX_SIZE - 1) //if front reaches the rightmost index
			{
	            front = 0; //front connects with the left most index
	        } 
			else 
			{
	            front++; //front moves on
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
	            if (rear >= front) //if rear is more than the front //right index should be more than the left index
				{
	                for (int i = front; i <= rear; i++) //from front to rear
					{
	                    cout << arr[i] << " ";
	                }
	            } 
				else 
				{
	                for (int i = front; i < MAX_SIZE; i++) //from front to right most index //incase front is greater than the rear
					{
	                    cout << arr[i] << " ";
	                }
	                for (int i = 0; i <= rear; i++) //from left most index to rear
					{
	                    cout << arr[i] << " ";
	                }
	            }
	            cout << endl;
	        }
	    }
};

int main() 
{
    CircularQueue myQueue;
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

