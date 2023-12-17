#include <iostream>
using namespace std;

const int MAX_V = 100;

class Graph 
{
	private:
	    int vertices;
	    int adjMatrix[MAX_V][MAX_V];
	    static const int INFINITY = 1000000;
	
	public:
	    Graph(int V) //constructor
		{
			vertices=V;  
			
	        for (int i = 0; i < V; ++i) 
			{
	            for (int j = 0; j < V; ++j) 
				{
	                if (i == j)
	                {
	        			adjMatrix[i][j] = 0;        	
					}
	        
	                else
	                {
	                	adjMatrix[i][j] = INFINITY;	
					}
	            }
	        }
	    }
	
	    void addEdge(int u, int v, int weight) //undirected
		{
	        adjMatrix[u][v] = weight;
	        adjMatrix[v][u] = weight;
	    }
	
	    int* dijkstra(int source, int target) 
		{
	        int visited[MAX_V] = {0}; //populate all of the matrix with 0 as no vertex visited
	        int distance[MAX_V]; //every edge has their distance
	        int* previous = new int[MAX_V]; //if there is a previous vertex
	
	        for (int i = 0; i < vertices; ++i) //initialized
			{
	            distance[i] = INFINITY;
	            previous[i] = -1;
	        }
	
	        distance[source] = 0; //no vertex visited so no distance covered
	
	        while (!visited[target]) 
			{
	            int selected_node = -1;
	            int min_distance = INFINITY;
	
	            for (int v = 0; v < vertices; ++v) 
				{
	                if (!visited[v] && distance[v] < min_distance) //if not visited and the distance needed to cover is lesser than minimum distance
					{
	                    min_distance = distance[v]; //now min distance updated
	                    selected_node = v; 
	                }
	            }
	
	            if (selected_node == -1) //covered all vertices
				{
					break;	
				}
	
	            visited[selected_node] = 1; //visited
	
	            for (int v = 0; v < vertices; ++v) 
				{
	                if (adjMatrix[selected_node][v] != INFINITY) //edge not covered
					{
	                    int alt = distance[selected_node] + adjMatrix[selected_node][v]; //alternative distance
	                    if (alt < distance[v]) 
						{
	                        distance[v] = alt; //distance changed
	                        previous[v] = selected_node; //node covered
	                    }
	                }
	            }
	        }
	
	        return previous;
	    }
};

int main() 
{
    int V = 6;
    Graph g(V);

    g.addEdge(1, 0, 4);
    g.addEdge(1, 2, 9);
    g.addEdge(3, 0, 8);
    g.addEdge(3, 2, 6);
    g.addEdge(3, 5, 4);
    g.addEdge(5, 4, 3);
    g.addEdge(4, 2, 14);

    int source = 1;
    int target = 4;

    int* result = g.dijkstra(source, target);

    cout << "The Shortest path from " << source << " to " << target << " is: ";

    int* path = result;
    int pathArray[MAX_V];
    int pathLength = 0;
    int current = target;

    while (current != -1) 
	{
        if (current != source || pathLength == 0) 
		{
            pathArray[pathLength++] = current;
        }
        current = path[current];
    }

    cout << source << " ";
    for (int i = pathLength - 1; i >= 0; --i) 
	{
        cout << pathArray[i] << " ";
    }
    cout << endl;

    delete[] result;
}

