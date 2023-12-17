#include <iostream>
#include <vector> //have used vectors more cuz of leetcode
using namespace std;

const int INT_MAX_CUSTOM = 2147483647; //aise hi koi maximum set karliya 

class Graph 
{
	private:
	    int V;
	    vector<vector<int> > adjMatrix; //2d matrix made using vectors
	
	public:
	    Graph(int vertices) : V(vertices) //vertices set in constructor
		{
	        adjMatrix.resize(V, vector<int>(V, 0)); //will adjust the 2d matrix for how many vertices there are
	    }
	
	    void addEdge(int source, int destination, int weight) 
		{
	        adjMatrix[source][destination] = weight; // if the edge has weight 4 then the matrix will have 4 there
	        adjMatrix[destination][source] = weight; // For undirected graph
	    }
	
	    int findMinKey(vector<int> &key, vector<bool> &mstSet) 
		{
	        int min = INT_MAX_CUSTOM, minIndex = -1; 
	
	        for (int v = 0; v < V; ++v) 
			{
	            if (!mstSet[v] && key[v] < min) //if not visited and the edge is smaller than the min
				{
	                min = key[v]; //new min
	                minIndex = v; //index is now the index at which the edge is 
	            }
	        }
	
	        return minIndex;
	    }
	
	    void primMST() 
		{
	        vector<int> parent(V, -1); //parent vector made
	        vector<int> key(V, INT_MAX_CUSTOM); //key vector made
	        vector<bool> mstSet(V, false); //mstSet vector made
	
	        key[0] = 0; // Start from vertex 0
	
	        for (int count = 0; count < V - 1; ++count) 
			{
	            int u = findMinKey(key, mstSet); //will find smallest edge
	            mstSet[u] = true; //will set the edge to true as visited
	
	            for (int v = 0; v < V; ++v) 
				{
	                if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v]) //if there is a weight in the 2d matrix and is not visited and the weight is less than the minimum
					{
	                    parent[v] = u; //now that index becomes the parent
	                    key[v] = adjMatrix[u][v]; //new minimum weight 
	                }
	            }
	        }
	
	        cout << "Edges in MST using Prim's algorithm:" << endl; //display
	        for (int i = 1; i < V; ++i) 
			{
	            cout << parent[i] << " - " << i << " : " << adjMatrix[i][parent[i]] << endl;
	        }
	    }
};

int main() 
{
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
	g.addEdge(3, 4, 7);
    g.primMST();
}

