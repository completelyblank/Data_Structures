#include <iostream>
using namespace std;

class Graph 
{
    int V; // Number of vertices
    int** adjList; // Adjacency list

public:
    Graph(int vertices) //create a graph
	{
		V=vertices;
        adjList = new int*[V]; //adjacency list has as many elements as verticees
        for (int i = 0; i < V; ++i) 
		{
            adjList[i] = new int[V](); //put the vertices in the list
        }
    }

    void addEdge(int u, int v) 
	{
        adjList[u][v] = 1; //undirected
    }

    // Depth-First Search (DFS)
    void DFSUtil(int v, bool* visited) 
	{
        visited[v] = true; //all visited
        cout << v << " ";

        for (int u = 0; u < V; ++u) 
		{
            if (adjList[v][u] && !visited[u]) //if the vertice has not been visited
			{
                DFSUtil(u, visited); //will recusively go to the vertice
            }
        }
    }

    void DFS(int startVertex) 
	{
        bool* visited = new bool[V](); //visited array created for number of vertices
    	cout << "Depth-First Traversal from vertex " << startVertex << ": "; 
        DFSUtil(startVertex, visited); //will recursively visit all vertices
        cout << endl;
        delete[] visited; //all visited
    }

    // Breadth-First Search (BFS)
    void BFS(int startVertex) 
	{
        bool* visited = new bool[V](); //visited array created for number of vertices
    	cout << "Breadth-First Traversal from vertex " << startVertex << ": "; 

        int* queue = new int[V]; //queue stores number of vertices
        int front = 0, rear = 0; //initialized
        visited[startVertex] = true; //start vertice has been visited
        queue[rear++] = startVertex; //pushing start vertice in queue

        while (front != rear) //until queue has reached end
		{
            int v = queue[front++]; //queue top/front which can be printed
        	cout << v << " ";

            for (int u = 0; u < V; ++u)  //from first vertice to last
			{
                if (adjList[v][u] && !visited[u])  //if vertice has not been visited
				{
                    visited[u] = true; //vertice has been visited
                    queue[rear++] = u; //queue moves on 
                }
            }
        }
        cout << endl;

        delete[] visited; //all visited so now new will initialize with function scope
        delete[] queue; //queue stored bfs so now we will have new queue for function scope
    }

    // Topological Sorting using DFS
    void topologicalSortUtil(int v, bool* visited, int* stack, int& stackIndex) 
	{
        visited[v] = true; //all visited at first

        for (int u = 0; u < V; ++u) 
		{
            if (adjList[v][u] && !visited[u]) //if vertice has not been visited
			{
                topologicalSortUtil(u, visited, stack, stackIndex); //will go to vertice recursively 
            }
        }

        stack[stackIndex++] = v; //stack stores vertice at stop
    }

    void topologicalSort() 
	{
        bool* visited = new bool[V](); //visted array 
        int* stack = new int[V]; //stack using array
        int stackIndex = 0; //stack has nothing at front

        for (int i = 0; i < V; ++i) 
		{
            if (!visited[i]) //if not visited
			{
                topologicalSortUtil(i, visited, stack, stackIndex); //will go to vertice recursively
            }
        }

        cout << "Topological Sorting: ";
        while (stackIndex > 0) //until stack has pushed out all
		{
            cout << stack[--stackIndex] << " ";
        }
        cout << endl;

        delete[] visited; //all visited so now new will initialize with function scope
        delete[] queue; //queue stored bfs so now we will have new queue for function scope
    }

    ~Graph() 
	{
        for (int i = 0; i < V; ++i) 
		{
            delete[] adjList[i]; //all vertices deleted from adjacency list
        }
        delete[] adjList;
    }
};

int main() 
{
    int vertices, edges;
	cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    Graph graph(vertices);

    cout << "Enter edges (from to):" << endl;
    for (int i = 0; i < edges; ++i) 
	{
        int from, to;
    	cin >> from >> to;
        graph.addEdge(from, to);
    }

    int startVertex;
    cout << "Enter the starting vertex for traversal: ";
    cin >> startVertex;

    graph.DFS(startVertex);
    graph.BFS(startVertex);
    graph.topologicalSort();
}

