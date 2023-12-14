#include <iostream>
using namespace std;

class Node 
{
	public:
	    int data;
	    Node* next;
	    Node* prev;
	    
	Node()
	{
		data=0;
		next=NULL;
		prev=NULL;	
	}    
	
	
	Node* createNode(int data) 
	{
		//setting newNode's elements to null at start
	    Node* newNode = new Node;
	    newNode->data = data;
	    newNode->next = NULL;
	    newNode->prev = NULL;
	    return newNode;
	}
	
	Node* insertAtBeginning(int data) 
	{
	    Node* newNode = createNode(data); //Node created
	    if (this != NULL)  //if head is not at end
		{
	        newNode->next = this; //newNode's next pointer is at head
	        this->prev = newNode; //head's previous pointer is at newNode //this pushes the head ahead of the newNode, making newNode the head
	    }
	    return newNode;
	}
	
	Node* insertBefore(Node* head, int dataToInsert, int dataToFind) 
	{
	    Node* newNode = createNode(dataToInsert); //Node created
	
	    if (head == NULL) //if there is no node
		{
	        return newNode;
	    }
	
	    Node* current = head; //current Node created which points at the start (head)
	    while (current != NULL && current->data != dataToFind) //until current reaches the end, and the current data is not the data we want to insert before
		{
	        current = current->next; //current node traverses
	    }
	
	    if (current != NULL) //if current is not at the end of the list
		{
	        newNode->next = current; //the newnode pointing at next stores current 
	        newNode->prev = current->prev; //the newnode pointing at prev stores current (which is pointing at prev)
	        current->prev = newNode; //current pointing at prev stores the newNode
	        if (newNode->prev != NULL) //if the prev newNode is not at the end
			{
	            newNode->prev->next = newNode; //the next pointer of the node before the newNode will store the newNode (Bi-directional)
	        } 
			else 
			{
	            head = newNode;
	        }
	    }
	
	    return head;
	}
	
	Node* insertAfter(Node* head, int dataToInsert, int dataToFind) 
	{
	    Node* newNode = createNode(dataToInsert); //Node created
	
	    if (head == NULL) //if no head
		{
	        return newNode;
	    }
	
	    Node* current = head; //current node stores head
	    while (current != NULL && current->data != dataToFind) //until current doesn't reach the end and current data is not the same as data we want to find
		{
	        current = current->next; //curent traverses
	    }
	
	    if (current != NULL) //if current is not at end
		{
	        newNode->prev = current; //prev pointer of newNode points to current node
	        newNode->next = current->next; //next pointer of newNode points to current node's next pointer
	        current->next = newNode; //next pointer of current node points to newNode
	        if (newNode->next != NULL) //if the next pointer of the newNode is not at the end
			{
	            newNode->next->prev = newNode; //the next pointer of the node before the newNode will store the newNode (Bi-directional)
	        }
	    }
	
	    return head;
	}
	
	
	Node* insertAtPosition(Node* head, int data, int position) 
	{
	    if (position < 1) //position cant be less than 1 as linked lists start from 1 (unlike arrays which start from 0)
		{
	        cout << "Invalid position." << endl;
	        return head;
	    }
	
	    if (position == 1 || head == NULL) //if there is no head or the position entered is the head itself
		{
	        return insertAtBeginning(data);
	    }
	
	    Node* current = head; //current node will be at head
	    int currentPosition = 1; 
	
	    while (currentPosition < position - 1 && current->next != NULL) //until the current position is at the position given and the current node's next pointer is at the end
		{
	        current = current->next; //current node traverses
	        currentPosition++; //currentPosition increments
	    }
	
	    if (currentPosition < position - 1)  
		{
	        cout << "Position is out of bounds." << endl;
	        return head;
	    }
	
	    Node* newNode = createNode(data); //Node created
	    newNode->next = current->next; //newNode next pointer has current's next pointer
	    newNode->prev = current; //newNode prev pointer has current
	    current->next = newNode; //current's next pointer has newNode //switched places with the newNode
	
	    if (newNode->next != NULL) //if newNode's next pointer doesn't reach end
		{
	        newNode->next->prev = newNode; //the next pointer of the node before the newNode will store the newNode (Bi-directional)
	    }
	
	    return head;
	}
	
	Node* insertAtEnd(Node* head, int data) 
	{
	    Node* newNode = createNode(data); //Node created
	
	    if (head == NULL) //if no head
		{
	        return newNode;
	    }
	
	    Node* current = head; //current Node will store head
	    while (current->next != NULL) //until current's next pointer reaches the end
		{
	        current = current->next; //current traverses
	    }
	
	    current->next = newNode; //current's next pointer stores newNode
	    newNode->prev = current; //newNode's prev pointer will store current //switching places
	    return head;
	}
	
	Node* deleteNode(Node* head, int data) 
	{
	    if (head == NULL) //if no head
		{
	        return NULL;
	    }
	
	    if (head->data == data) //if the head data is the data we want to delete
		{
	        Node* temp = head; //temp node created which stores head
	        head = head->next; //head moves on, making temp the new head
	        if (head != NULL) //if head is not at end
			{
	            head->prev = NULL; //the head's prev pointer will be null
	        }
	        delete temp; //temp deleted, head now the head node again
	        return head;
	    }
	
	    Node* current = head;
	    while (current != NULL && current->data != data) //while the current is not at the end and the current data is not the data we want
		{
	        current = current->next; //current traverses
	    }
	
	    if (current != NULL) //if current is not at the end
		{
	        current->prev->next = current->next; //the current nodes's prev pointer pointing at the next point (double pointer) will now store the current's next pointer
	        if (current->next != NULL) 
			{
	            current->next->prev = current->prev;
	        }
	        delete current;
	    }
	
	    return head;
	}
	
	void displayList(Node* head) 
	{
	    Node* current = head; //current node created which points to head
	    while (current != NULL) //until current reaches the end
		{
	        cout << current->data << " "; //outputs the contents of the current data
	        current = current->next; //current traverses
	    }
	    cout << endl;
	}
	
	bool search(int key, Node* head) 
	{
	    Node* temp = head; //temp node created which points at the head node
	    while (temp != NULL) //until the temp node reaches the end
		{
	        if (temp->data == key) //the temp node class data compared to the key
			{
	            cout << "Match Found." << endl;
	            return true;
	        }
	        temp = temp->next; //temp traverses
	    }
	    cout << "Match Not Found." << endl;
	    return false;
	}
	
	Node* reverse(Node* head) 
	{
	    Node* current = head; //Current Node points at the head
	    Node* temp = NULL; //Created a temp Node which currently is Null
	
	    while (current != NULL) //Until Current reaches the end of the list
		{
	        temp = current->prev; //temp holds value of current node which is pointing at previous
	        current->prev = current->next; //current node pointing at prev node now holds next node's value
	        current->next = temp; //current node pointing at next now holds value of temp (holding value of prev)
	        current = current->prev; //now current holds value of prev
	    }
	
	    if (temp != NULL) //Until temp reaches end
		{
	        head = temp->prev; //the head node will contain the temp node which points at the previous node
	    }
	
	    cout << "List has been reversed." << endl;
	    return head;
	}

};

int main() 
{
    Node* head = NULL;
    int position;
    int choice;

    while (true) 
	{
        cout << "Your Doubly Linked List right now is: ";
        head->displayList(head);
        cout << "What do you want to do with this Doubly Linked List?" << endl;
        cout << "1: Insert at the beginning." << endl;
        cout << "2: Insert at the end." << endl;
        cout << "3: Insert at a specified space." << endl;
        cout << "4: Display Linked List." << endl;
        cout << "5: Delete Node." << endl;
        cout << "6: Search for a value." << endl;
        cout << "7: Reverse the linked list." << endl;
        cout << "8: Insert before a value." << endl;
        cout << "9: Insert after a value." << endl;
        cout << "10: Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1: //Insert at Head
                int data;
                cout << "Enter Data to insert at the Beginning: ";
                cin >> data;
                head->insertAtBeginning(data);
                break;

            case 2: //insert at End
                cout << "Enter Data to insert at the End: ";
                cin >> data;
                head->insertAtEnd(head, data);
                break;

            case 3: //Insert 
                cout << "Enter Data to insert: ";
                cin >> data;
                cout << "Enter the Position at which to insert: ";
                cin >> position;
                head->insertAtPosition(head, data, position);
                break;

            case 4: //Display
                cout << "Doubly Linked List: ";
                head->displayList(head);
                break;

            case 5: //Delete Node
                cout << "Enter Data to delete: ";
                cin >> data;
                head->deleteNode(head, data);
                break;

            case 6: //Search
                cout << "Enter value to search: ";
                cin >> data;
                head->search(data, head);
                break;

            case 7: //Reverse
                head->reverse(head);
                head->displayList(head);
                break;
			
			case 8: //Insert before a position
                int dataToInsertBefore, dataToFindBefore;
                cout << "Enter Data to insert before: ";
                cin >> dataToInsertBefore;
                cout << "Enter Data to find before: ";
                cin >> dataToFindBefore;
                head->insertBefore(head, dataToInsertBefore, dataToFindBefore);
                break;

            case 9: //Insert after a position
                int dataToInsertAfter, dataToFindAfter;
                cout << "Enter Data to insert after: ";
                cin >> dataToInsertAfter;
                cout << "Enter Data to find after: ";
                cin >> dataToFindAfter;
                head->insertAfter(head, dataToInsertAfter, dataToFindAfter);
                break;

			
            case 10: //Exit
                while (head != NULL) 
				{
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                }
                return 0;

            default:
                cout << "Invalid Choice." << endl << "Please try again." << endl;
        }
    }
}


