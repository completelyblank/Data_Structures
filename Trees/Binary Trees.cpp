#include <iostream>
using namespace std;

class TreeNode
{
	public:
	    int data;
	    TreeNode* left;
	    TreeNode* right;
	
	    TreeNode(int value)
	    {
	        data = value;
	        left = NULL;
	        right = NULL;
	    }
};

class BinaryTree
{
public:
    TreeNode* root;

    BinaryTree()
    {
        root = NULL; //there shall be no root at the start
    }

    void insert(int value) //inserting new node
    {
        root = insertRec(root, value); //uses insert rec function to check where to insert node then inserts
    }

    TreeNode* insertRec(TreeNode* root, int value) //checkinf function for insertion
    {
        if (root == NULL) //if no root
        {
            return new TreeNode(value); //insert at root area
        }

        if (value < root->data) //if the node is smaller
        {
            root->left = insertRec(root->left, value); //node will go to left of the root
        }
        else if (value > root->data)//if the node is larger
        {
            root->right = insertRec(root->right, value); //node will go to the right of the root
        }

        return root;
    }

    void displayInOrder() //displaying in order
    {
        inOrder(root);
    }

    void displayPreOrder() //displaying pre order
    {
        preOrder(root);
    }

    void displayPostOrder() //displaying post order
    {
        postOrder(root);
    }

    void displayLevelOrder() //displaying level order
    {
        int height = getHeight(root); //we get the height of the tree
        for (int i = 1; i <= height; i++) //loop from start to height
        {
            printGivenLevel(root, i); 
        }
    }

    TreeNode* search(int value) //searching function
    {
        return searchRec(root, value);
    }

    TreeNode* searchRec(TreeNode* root, int value) //helper function for the searching function
    {
        if (root == NULL || root->data == value) //if root is null or data is the same as the value we want //base case
        {
            return root;
        }

        if (value < root->data) //if value is smaller
        {
            return searchRec(root->left, value); //recursion to the left
        }

        return searchRec(root->right, value); //else recursion to the right
    }

    void update(int oldValue, int newValue) //update function
    {
        root = updateRec(root, oldValue, newValue);
    }

    TreeNode* updateRec(TreeNode* root, int oldValue, int newValue) //update helper function
    {
        if (root == NULL) //if no root
        {
            return root;
        }

        if (oldValue < root->data) //if old value is smaller 
        {
            root->left = updateRec(root->left, oldValue, newValue); //we go to the left to find the value to update
        }
        else if (oldValue > root->data) //if old value is greater
        {
            root->right = updateRec(root->right, oldValue, newValue); //we go to the right to find the value to update
        }
        else
        {
            root->data = newValue; //else we just update the root
        }

        return root;
    }

    int getHeight(TreeNode* node) //finding the height of the tree
    {
        if (node == NULL) //if no root
        {
            return 0;
        }
        int leftHeight = getHeight(node->left); //we find how many levels we go in left
        int rightHeight = getHeight(node->right); //we find how many levels we go in right
        return max(leftHeight, rightHeight) + 1; //we take the maximum of the levels we have gone as taught in discrete 
	/*
       	50
      /  \
     30   70 //we take the max, which is the left here, and return the left's height + 1 to account for the root
    / \   
   20 40 
	*/
    }

    void printGivenLevel(TreeNode* node, int level)
    {
        if (node == NULL) //no nodes at the level
        {
            return;
        }
        if (level == 1) //basecase
        {
            cout << node->data << " "; //print the nodes at the level
        }
        else if (level > 1)
        {
            printGivenLevel(node->left, level - 1); //recursion to reach the level so as to get to the basecase
            printGivenLevel(node->right, level - 1); //recursion to reach the level so as to get to the basecase
        }
    }

    void inOrder(TreeNode* node) //In Order Traversal //left subtree ->current node ->right subtree
    {
        if (node == NULL) //if no nodes
        {
            return;
        }
        inOrder(node->left); //left subtree traversal
        cout << node->data << " "; //current node printing
        inOrder(node->right);//right subtree traversal
    }

    void preOrder(TreeNode* node) //Pre Order Traversal //current node ->left subtree ->right subtree
    {
        if (node == NULL) //if no nodes
        {
            return;
        }
        cout << node->data << " "; //current node printing 
        preOrder(node->left); //left subtree traversal
        preOrder(node->right); //right subtree traversal
    }

    void postOrder(TreeNode* node) //Post Order Traversal //left subtree -> right subtree ->current node
    {
        if (node == NULL) //if no nodes
        {
            return;
        }
        postOrder(node->left); //left subtree traversal
        postOrder(node->right); //right subtree traversal
        cout << node->data << " "; //current node printing
    }
};

void displayMenu()
{
    cout << "Binary Search Tree Menu:" << endl;
    cout << "1. Insert an element: " << endl;
    cout << "2. Display In-Order Traversal: " << endl;
    cout << "3. Display Pre-Order Traversal: " << endl;
    cout << "4. Display Post-Order Traversal: " << endl;
    cout << "5. Display Level-Order Traversal: " << endl;
    cout << "6. Search for a value: " << endl;
    cout << "7. Update a value: " << endl;
    cout << "8. Exit: " << endl;
    cout << "Enter your choice: ";
}

int main()
{
    BinaryTree tree;
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
                tree.displayInOrder();
                cout << endl;
                break;

            case 3:
                cout << "Pre-Order Traversal: ";
                tree.displayPreOrder();
                cout << endl;
                break;

            case 4:
                cout << "Post-Order Traversal: ";
                tree.displayPostOrder();
                cout << endl;
                break;

            case 5:
                cout << "Level-Order Traversal: ";
                tree.displayLevelOrder();
                cout << endl;
                break;

             case 6:
            {
                int searchValue;
                cout << "Enter a value to search: ";
                cin >> searchValue;
                TreeNode* result = tree.search(searchValue);
                if (result)
                {
                    cout << "Value " << searchValue << " found in the tree." << endl;
                }
                else
                {
                    cout << "Value " << searchValue << " not found in the tree." << endl;
                }
                break;
            }

            case 7:
            {
                int oldValue, newValue;
                cout << "Enter the old value to update: ";
                cin >> oldValue;
                cout << "Enter the new value: ";
                cin >> newValue;
                tree.update(oldValue, newValue);
                cout << "Value updated successfully." << endl;
                break;
            }

            case 8:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (choice != 8);
    
}
