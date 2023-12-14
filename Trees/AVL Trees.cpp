#include <iostream>
using namespace std;

class TreeNode
{
	public:
	    int data;
	    TreeNode* left;
	    TreeNode* right;
	    int height;  // height of the AVL tree
	
	    TreeNode(int value)
	    {
	        data = value;
	        left = NULL;
	        right = NULL;
	        height = 1;  // Initialize height to 1 for a new node
	    }
};

class AVLTree
{
	public:
	    TreeNode* root; //first node is the root
	
	    AVLTree()
	    {
	        root = NULL; //there wont be any node/root there
	    }
	
	    int getHeight(TreeNode* node)
	    {
	        if (node == NULL) //if there is no node
	        {
	            return 0; //no height to calculate
	        }
	        return node->height; //else return the height from the node we calculate
	    }
	
	    int getBalanceFactor(TreeNode* node)
	    {
	        if (node == NULL) //if there is no node
	        {
	            return 0; //no balancing
	        }
	        return getHeight(node->left) - getHeight(node->right); //BST= left subtree - right subtree
	    }
	
	    TreeNode* rightRotate(TreeNode* y)
	    {
	        TreeNode* x = y->left; //node made at y's left
	        TreeNode* z = x->right; //node made at x's right
	
	        x->right = y; //y now at x's right
	        y->left = z; //z now at y's left
	
	        y->height = max(getHeight(y->left), getHeight(y->right)) + 1; //y's height is the higher of the y right or left subtrees
	        x->height = max(getHeight(x->left), getHeight(x->right)) + 1; //x's height is the higher of the x right or left subtrees
	
	        return x;
	    }
	
	    TreeNode* leftRotate(TreeNode* x)
	    {
	        TreeNode* y = x->right; //node made at x's right
	        TreeNode* z = y->left; //node made at y's left
	
	        y->left = x; //x now at y's left
	        x->right = z; //z now at x's right
	
	        x->height = max(getHeight(x->left), getHeight(x->right)) + 1; //x's height is the higher of the y right or left subtrees
	        y->height = max(getHeight(y->left), getHeight(y->right)) + 1; //y's height is the higher of the y right or left subtrees
	
	        return y;
	    }
	
	    TreeNode* insert(TreeNode* node, int value)
	    {
	        if (node == NULL) //if there is no root node
	        {
	            return new TreeNode(value); //make new node and make it the root
	        }
	
	        if (value < node->data) //if the value is smaller than the root's data
	        {
	            node->left = insert(node->left, value); //we will insert at the root's left
	        }
	        else if (value > node->data) //if the value is greater than the root's data
	        {
	            node->right = insert(node->right, value); //we will insert at the root's right
	        }
	        else
	        {
	            return node;  // Duplicate values not allowed
	        }
	
	        node->height = 1 + max(getHeight(node->left), getHeight(node->right)); //the new node's height will be the greater of its subtrees
	
	        int balance = getBalanceFactor(node); //find balance factor
	
	        // Left-Left Case
	        if (balance > 1 && value < node->left->data) //if the balance factor is greater than 1 and the value is smaller than the node's left data
	        {
	        	 return rightRotate(node); //rotate right
			}
	
	        // Right-Right Case
	        if (balance < -1 && value > node->right->data) //if the balance factor is smaller than -1 and the value is greater than the node's right data
	        {
	        	return leftRotate(node); //rotate left
			}
	
	        return node;
	    }
	
	    void insert(int value) //calling function for the above insert function
	    {
	        root = insert(root, value); //inserts at the root or as sees fit according to the function conditions
	    }
	
	    void inOrder(TreeNode* node) //left subtree -> current ->right subtree
	    {
	        if (node == NULL)
	        {
	            return;
	        }
	        inOrder(node->left); //left subtree
	        cout << node->data << " "; //current 
	        inOrder(node->right); //right subtree
	    }
};

void displayMenu()
{
    cout << "AVL Tree Menu:" << endl;
    cout << "1. Insert an element" << endl;
    cout << "2. Display In-Order Traversal" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    AVLTree tree;
    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
            case 1:
                int val;
                cout << "Enter the element to insert: ";
                cin >> val;
                tree.insert(val);
                break;

            case 2:
                cout << "In-Order Traversal: ";
                tree.inOrder(tree.root);
                cout << endl;
                break;

            case 3:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (choice != 3);

}

