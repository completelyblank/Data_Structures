#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* back;
		Node* left;
		Node* right;
		
		Node()
		{
			data=0;
			back=NULL;
			right=NULL;
			left=NULL;
		}
		
		Node(int d)
		{
			data=d;
			back=NULL;
			right=NULL;
			left=NULL;
		}
};

class BST 
{
	private:
	    Node* root;
	
	public:
	    BST() 
		{
	        root = NULL;
	    }
	
	    void insert(int n) 
		{
	        root = insertRec(root, n);
	        cout<<"Inserted "<<n<<endl;
	    }
	
	    Node* insertRec(Node* r, int n) 
		{
	        if (r == NULL) 
			{
	            return new Node(n);
	        }
	
	        if (n > r->data) 
			{
	            r->right = insertRec(r->right, n);
	        } 
			
			else if (n < r->data) 
			{
	            r->left = insertRec(r->left, n);
	        }
			
			else 
			{
	            cout << "Duplicate Value" << endl;
	        }
	
	        return r;
	    }
	    
	    void inOrderWithBacktrack(Node* node) 
		{
		    if (node == NULL) 
			{
		        return;
		    }
		
		    inOrderWithBacktrack(node->left); 
		
		    if (node->left == NULL && node->right == NULL) 
			{
		        cout << node->data << " ";
		        return; 
		    }
		
		    inOrderWithBacktrack(node->right);
		
		    cout << node->data << " ";
		}	

    	
    	 void displayInOrder() //displaying in order
    	{
        	inOrderWithBacktrack(root);
    	}

};


int main()
{
	BST b;
    b.insert(5);
    b.insert(3);
    b.insert(2);
    b.insert(1);
    b.insert(6);
    b.insert(4);
    b.insert(7);
    b.insert(8);
    b.insert(6);
    b.displayInOrder();
}
