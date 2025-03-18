// You have a business with several offices; you want to lease phone lines to connect them
// up with each other; and the phone company charges different amounts of money to
// connect different pairs of cities. You want a set of lines that connects all your offices
// with a minimum total cost. Solve the problem by suggesting appropriate data structures.


#include <iostream>
#include <climits> 
using namespace std;

class Graph {
private:
    int graph[10][10]; 
    int n;
    int minCost = 0;

public:
    Graph(int nodes = 0) {
        n = nodes;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = 0;
            }
        }
    }

    void create() {
        int edges;
        cout << "Enter the number of edges: ";
        cin >> edges;
        
        for (int k = 0; k < edges; k++) {
            int i, j, weight;
            cout << "Enter edge (node1 node2 weight): ";
            cin >> i >> j >> weight;
            graph[i][j] = weight;
            graph[j][i] = weight; 
        }
    }

    void display() {
        cout << "Graph (Adjacency Matrix Representation):" << endl;
        cout << "EDGE  | WEIGHT" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] != 0) {
                    cout << i << " - " << j << " : " << graph[i][j] << endl;
                }
            }
        }
    }

    void primsAlgorithm() {
        bool visited[10] = {false}; 
        int parent[10];  
        int key[10];     

        for (int i = 0; i < n; i++)
            key[i] = INT_MAX, parent[i] = -1;

        key[0] = 0;
        minCost = 0;

        for (int count = 0; count < n - 1; count++) {
            int minWeight = INT_MAX, u = -1;

            for (int v = 0; v < n; v++) {
                if (!visited[v] && key[v] < minWeight) {
                    minWeight = key[v];
                    u = v;
                }
            }

            visited[u] = true; 
            minCost += minWeight;

            for (int v = 0; v < n; v++) {
                if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                    key[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }

        cout << "\nMinimum Spanning Tree (MST) using Prim's Algorithm:\n";
        for (int i = 1; i < n; i++) {
            cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
        }
        cout << "Total Cost of MST: " << minCost << endl;
    }
};

int main() {
    int nodes;
    cout << "Enter the number of nodes: ";
    cin >> nodes;
    
    Graph g(nodes);
    g.create();
    g.display();
    g.primsAlgorithm();

    return 0;
}
