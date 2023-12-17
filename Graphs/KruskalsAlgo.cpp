#include <iostream>
#include <vector>
using namespace std;

class Edge 
{
	public:
		int source, destination, weight;
};

class Graph 
{
private:
    int V;
    vector<Edge> edges; //a vector that stores all the edges //can be made using arrays too

public:
    Graph(int vertices) 
	{
		V=vertices;
	}

    void addEdge(int source, int destination, int weight) //same work as a constructor
	{
        Edge newEdge;
        newEdge.source = source;
        newEdge.destination = destination;
        newEdge.weight = weight;
        edges.push_back(newEdge); //adds the edge to the vector /pushes it in 
    }

    int find(vector<int>& parent, int i) 
	{
        if (parent[i] == -1)
        {
        	return i;	
		}
        return find(parent, parent[i]); //recursion to find parent edge
    }

    void Union(vector<int>& parent, int x, int y) //joining the sets of edges together as in Kruskal
	{
        int xset = find(parent, x); //finds 1 set of parent edge
        int yset = find(parent, y); //finds the other set parent edge
        parent[xset] = yset; //joins both parent set together
    }

    void sortEdges() //bubble sort simple
	{
        for (int i = 0; i < edges.size() - 1; ++i) 
		{
            for (int j = 0; j < edges.size() - i - 1; ++j) 
			{
                if (edges[j].weight > edges[j + 1].weight) 
				{
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }
    }

    void kruskalMST() 
	{
        vector<Edge> result(V - 1); // result vector which will have total number of edges =Vertices-1
        vector<int> parent(V, -1); // parent vector to start off kruskal algorithm with

        sortEdges(); //bubble sort to find min edge first and place them like wise

        int e = 0, i = 0;
        while (e < V - 1 && i < edges.size()) 
		{
            Edge nextEdge = edges[i++]; //acts as a pointer //as in linked list temp or current nodes
            int x = find(parent, nextEdge.source); //finds first parent if exists
            int y = find(parent, nextEdge.destination); //finds second parent

            if (x != y) //if there are multiple parents
			{
                result[e++] = nextEdge;
                Union(parent, x, y);
            }
        }

        cout << "Edges in MST using Kruskal's algorithm:" << endl; //display
        for (i = 0; i < e; ++i) 
		{
            cout << result[i].source << " - " << result[i].destination << " : " << result[i].weight << endl;
        }
    }
};

int main() 
{
    int V = 8;
    Graph g(V);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
	g.addEdge(3, 4, 8);
	g.addEdge(4, 5, 7);
	g.addEdge(5, 6, 2);
	g.addEdge(7, 2, 9);
	g.addEdge(2, 5, 11);
    g.kruskalMST();

}

