#include <iostream>
#include <string>

using namespace std;

class HashNode 
{
    public:
        int key;
        HashNode* next;

        HashNode(int k)
        {
            key=k;
            next=NULL; 
        } 
};

class HashTable 
{
    private:
        HashNode** buckets; //pointer to Array 
        int numBuckets;

        int hashFunction(int k) 
        {
            return k % numBuckets; //modulus will find last digit of k like 58 has 8 and will be used in function to calculate hash table placement
        }

    public:
        HashTable(int size) : numBuckets(size) 
        {
            buckets = new HashNode*[numBuckets](); //new node created
        }

        void insert(int k) 
        {
            int index = hashFunction(k); //index will have a new hash function created which will calculate sum 
            HashNode* newNode = new HashNode(k); //node created

            if (buckets[index] == NULL)  //if there is no node at the index
            {
                buckets[index] = newNode; //we can enter the hashnode there
            } 
            else 
            {
                HashNode* temp = buckets[index]; //temp node created at the index
                while (temp->next != NULL)  //until node reaches the end
                {
                    temp = temp->next; //temp traverses
                }
                temp->next = newNode; //temp will have node adjacent
            }
        }

        void wordSearch(int k) 
        {
            int index = hashFunction(k);
            HashNode* current = buckets[index];
            while (current != NULL) 
            {
                if (current->key == k) 
                {
                    cout << "Search successful" << endl;
                    return; //void
                }
                current = current->next;
            }
            cout << "Search unsuccessful!" << endl;
        }

        void display() 
        {
            for (int i = 0; i < numBuckets; i++) 
            {
                cout << "Bucket: " << i << ": ";
                HashNode* temp = buckets[i];
                while (temp != NULL) 
                {
                    cout << temp->key << " => ";
                    temp = temp->next;
                }
                cout << "NULL!" << endl;
            }
        }

        void deleteWord(int ID) 
		{
			int index = hashFunction(ID);
			if(buckets[index] == 0) 
			{
				cout << "Item not found";
			} 
			
			else 
			{
				HashNode* current = buckets[index];
				HashNode* prev = NULL;
				while(current != NULL && current->key != ID) 
				{
					prev = current;
					current = current->next;
				}
				
				if(current == NULL) 
				{
					cout << "Item not found";
				} 
				else 
				{
					if(prev == NULL) 
					{
						buckets[index] = current->next;
					} 
					
					else 
					{
						prev->next = current->next;
					}
					
					delete current;
					cout << ID << " Deleted." << endl;
				}
			}
	}

        ~HashTable() //loops through buckets and deletes them one by one 
        {
            for (int i = 0; i < numBuckets; ++i) //looping
            {
                HashNode* current = buckets[i]; //pointer current pointing at bucket[i]
                while (current != NULL) //until current reaches the end
                {
                    HashNode* temp = current; //temp pointer made at current 
                    current = current->next; //current traverses
                    delete temp; //deletes temp so current will be at the place we want without breaking the linked list 
                }
                buckets[i] = NULL;
            }
            delete[] buckets;
        }
};

int main()
{
    int bucketSize = 10; 
    HashTable hashTable(bucketSize);
    hashTable.insert(1);
    hashTable.insert(2);
    hashTable.insert(3);
    hashTable.insert(4);
    hashTable.display();
    hashTable.deleteWord(5);
    hashTable.display();
}
