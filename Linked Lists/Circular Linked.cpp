#include <iostream>
using namespace std;

// Define a class for a node in the linked list
class Node 
{
public:
    int data;
    Node* next;

    Node()
    {
        data = 0;
        next = NULL;
    }
};

class Circular
{
public:
    Node* head;
    Node* tail;

    Circular()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(int value)
    {
        Node* node = new Node(); // Create a new node
        node->data = value;

        if (head == NULL) // If there is no data in head
        {
            head = node; // Head now has the node
            tail = node; // Tail now has node
            tail->next = head; // Tail's next node is the head
        }
        else
        {
            tail->next = node; // Tail's next node is the new node
            tail = tail->next; // Tail traverses forward
            tail->next = head; // Head is next to the tail
        }
    }

    void insertAtBeginning(int value)
    {
        Node* node = new Node(); // New node created
        node->data = value;

        if (head == NULL) // If there is no data in head
        {
            head = node; // Head now has the node
            tail = node; // Tail now has node
            tail->next = head; // Tail's next node is the head
        }
        else
        {
            node->next = head; // Node's next node is the head
            head = node; // Head now has node
            tail->next = head; // Head is next to the tail
        }
    }

    void displayList() 
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head; // Current node created which points to head
        do
        {
            cout << current->data << " "; // Outputs the contents of the current data
            current = current->next; // Current traverses
        } while (current != head); // Until current reaches the head again
        cout << endl;
    }

    bool Search(int val)
	{
	    if (head == NULL)
	    {
	        cout << "The list is empty." << endl;
	        return false;
	    }
	
	    Node* temp = tail->next; // Start from the beginning of the list
	
	    do
	    {
	        if (temp->data == val) //if the searched data exists in the list
	        {
	            cout << "The Searched Data exists in the List." << endl; 
	            return true;
	        }
	        temp = temp->next;
	    } while (temp != tail->next); //until the temp node reaches the end of the list 
	
	    cout << "The Searched Data does not exist in the List." << endl;
	    return false;
	}


    void deleteAtFront()
    {
        Node* temp= new Node(); //temp node created
        temp=head; //temp is at head
        tail->next=head->next; //tail's next node is head's next node
        head=head->next; //head moves on meaning that temp is the new head

        delete temp; //temp deleted meaning that head is now the head node again
    }

    void deleteAtEnd()
    {
        Node* curr=new Node(); //current node created
        Node* pre= new Node(); //previous node created
        curr =head; //current is at head
        while(curr!=tail) //until current reaches the tail
        {
            pre=curr; //previous will be at current
            curr=curr->next; //current will traverse one node ahead, making previous remain at a position before
        }
        curr->next=tail->next; //current's next will be tail's next 
        tail=pre; //tail is at previous making current the last node
        delete curr; //current deleted making tail the last node again
    }
    
    void insertAtPosition(int value, int position)
	{
	    if (position < 0)
	    {
	        cout << "Invalid position. Position cannot be negative." << endl;
	        return;
	    }
	
	    Node* newNode = new Node();
	    newNode->data = value;
	
	    if (head == NULL) // If the list is empty, insert at the beginning.
	    {
	        head = newNode; //head now has newNode in its position
	        tail = newNode; //because the head is connected to the head, we put the newNode at the tail too
	        tail->next = head; //tail is connected to head
	    }
	    else if (position == 0) // Insert at the beginning.
	    {
	        newNode->next = head; //newNode's next node is the head
	        head = newNode; //head is now newNode //newNode is also tail
	        tail->next = head; //tail is connected to head
	    }
	    else // Insert at the specified position.
	    {
	        
	        Node* current = head; //current is at head
	        int currentPosition = 0; //the position is 0 //used for traversal 
	
	        while (currentPosition < position - 1 && current->next != head) //while the position reaches the position we want and the current reaches the end
	        {
	            current = current->next; //current traverses
	            currentPosition++; //current position increases
	        }
			//the loop above has ended meaning that we are now at the position we want
	        newNode->next = current->next; //newNode's next is the current's next
	        current->next = newNode; //the node next to current is the newNode
	
	        if (newNode->next == head) //if the head is next to the newNode //at tail
	        {
	            tail = newNode; // Update tail if we inserted at the end.
	        }
	    }
	}
	
	void reverse()
	{
	    if (head == NULL) //no list 
	    {
	        cout << "List is empty. Cannot reverse an empty list." << endl;
	        return; //void returned
	    }
	
	    Node* prev = tail; // Initialize prev to tail.
	    Node* current = head; //current is at head
	    Node* nextNode; //nexNode created
	
	    do
	    {
	        nextNode = current->next; // nexNode is next to the current
	        current->next = prev;     // current's next points to previous one //thus reversing the list
	        prev = current;           // prev is at current
	        current = nextNode;		  //current is now at nextNode
	    } while (current != head); //until current reaches the end
	
	    // Update head and tail pointers after reversing.
	    tail = head; //tail is now the head
	    head = prev; //head is where the previous node is //reversal
	}

};

int main() 
{
    Circular circle;
    int choice;

    while (true) 
    {
        cout << "Your Circular List right now is: ";
        circle.displayList();
        cout << "What do you want to do with this Circular List?" << endl;
        cout << "1: Insert at the beginning." << endl;
        cout << "2: Insert at the end." << endl;
        cout << "3: Delete at the beginning." << endl;
        cout << "4: Delete at the end." << endl;
        cout << "5: Search for value." << endl;
        cout << "6: Display the Linked List." << endl;
        cout << "7: Insert at a specified position." << endl;
        cout << "8: Reverse the Linked List." << endl;
        cout << "9: Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: // Insert at Head
                int data;
                cout << "Enter Data to insert at the Beginning: ";
                cin >> data;
                circle.insertAtBeginning(data);
                break;

            case 2: // Insert at End
                cout << "Enter Data to insert at the End: ";
                cin >> data;
                circle.insertAtEnd(data);
                break;

             case 3: // Delete at Beginning
                circle.deleteAtFront();
                break;    

             case 4: // Delete at End
                circle.deleteAtEnd();
                break;

            case 5: //Search
                cout << "Enter value to search: ";
                cin >> data;
                circle.Search(data);
                break;

            case 6: // Display
                cout << "Circular Linked List: ";
                circle.displayList();
                break;

			case 7: // Insert at Position
			    int position;
			    cout << "Enter position to insert: ";
			    cin >> position;
			    cout << "Enter Data to insert at Position: ";
			    cin >> data;
			    circle.insertAtPosition(data, position);
			    break;

			case 8: // Reverse the List
			    circle.reverse();
			    break;

            case 9: // Exit
                return 0;

            default:
                cout << "Invalid Choice." << endl << "Please try again." << endl;
                break;
        }
    }
}

