// Represent a givne graph using adjacency matrix  to find the length
// of shortest path between every pair of vertices. Use Floyd warhshalls
// algorithm to implement it.

#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int MAX = 10;

class Graph
{
private:
    int graph[MAX][MAX];
    int n, m;

public:
    Graph(int vertices, int edges)
    {
        n = vertices;
        m = edges;
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                if (i == j)
                    graph[i][j] = 0;
                else
                    graph[i][j] = INF;
            }
        }
    }

    void input()
    {
        int i, j, weight;
        cout << "Enter the edges for the graph (i j weight):" << endl;
        for (int k = 0; k < m; k++)
        {
            cin >> i >> j >> weight;
            if (i < n && j < n)
            {
                graph[i][j] = weight;
                // graph[j][i] = weight; // Uncomment for undirected graph
            }
            else
            {
                cout << "Invalid edge: vertex index out of range." << endl;
            }
        }
    }

    void display()
    {
        cout << "Adjacency Matrix:" << endl;
        cout << "   ";
        for (int i = 0; i < n; i++)
            cout << i << "\t";
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i << "| ";
            for (int j = 0; j < n; j++)
            {
                if (graph[i][j] == INF)
                    cout << "INF\t";
                else
                    cout << graph[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void floydWarshall()
    {
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (graph[i][k] < INF && graph[k][j] < INF)
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
};

int main()
{
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    if (vertices > 10)
    {
        cout << "Maximum allowed vertices is 10." << endl;
        return 1;
    }

    Graph g(vertices, edges);
    g.input();
    cout << "Before applying Floyd-Warshall algorithm:" << endl;
    g.display();

    g.floydWarshall();

    cout << "After applying Floyd-Warshall algorithm:" << endl;
    g.display();

    return 0;
}
