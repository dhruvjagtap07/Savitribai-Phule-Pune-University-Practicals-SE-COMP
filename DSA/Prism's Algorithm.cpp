// You have a business with several offices; you want to lease phone lines to connect them
// up with each other; and the phone company charges different amounts of money to
// connect different pairs of cities. You want a set of lines that connects all your offices
// with a minimum total cost. Solve the problem by suggesting appropriate data structures.

#include <iostream>
#include <climits>
using namespace std;

const int INF = 1e9;

class Graph
{
private:
    int graph[10][10];
    int n, m;
    int minCost = 0;

public:
    Graph(int vertices, int edges)
    {
        n = vertices;
        m = edges;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (i == j)
                    graph[i][j] = 0;
                else
                    graph[i][j] = INF;
            }
        }
    }

    void create()
    {

        for (int k = 0; k < m; k++)
        {
            int i, j, weight;
            cout << "Enter edge (node1, node2, weight): ";
            cin >> i >> j >> weight;
            graph[i][j] = weight;
            graph[j][i] = weight;
        }
    }

    void display()
    {
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

    void primsAlgorithm()
    {
        bool visited[10] = {false};
        int parent[10];
        int key[10];

        for (int i = 0; i < n; i++)
            key[i] = INF, parent[i] = -1;

        key[0] = 0;

        for (int count = 0; count < n - 1; count++)
        {
            int minWeight = INF, u = -1;

            for (int v = 0; v < n; v++)
            {
                if (!visited[v] && key[v] < minWeight)
                {
                    minWeight = key[v];
                    u = v;
                }
            }

            if (u == -1)
                break; // Handles disconnected graphs

            visited[u] = true;

            for (int v = 0; v < n; v++)
            {
                if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
                {
                    key[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }

        // ✅ Now calculate total cost using the final MST
        minCost = 0;
        cout << "\nMinimum Spanning Tree (MST) using Prim's Algorithm:\n";
        for (int i = 1; i < n; i++)
        {
            if (parent[i] != -1)
            {
                cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
                minCost += graph[i][parent[i]];
            }
        }
        cout << "Total Cost of MST: " << minCost << endl;
    }
};

int main()
{
    int nodes;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph g(nodes, edges);
    g.create();
    g.display();
    g.primsAlgorithm();

    return 0;
}
