// Represent a given graph using adjacency matrix/list to perform DFS and using adjacency
// list to perform BFS. Use the map of the area around the college as the graph. Identify
// the prominent land marks as nodes and perform DFS and BFS on that.

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int i, j, k, m, n;
int cost[10][10];

void input()
{
    cout << "Enter the number of nodes: ";
    cin >> m;

    cout << "Enter the number of edges: ";
    cin >> n;

    cout << "Enter the relation between edges: " << endl;

    for (k = 1; k <= n; k++)
    {
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;
    }
}

void displayAdjMat()
{
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }
}

void bfs(int start)
{
    bool visited[10] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int v = 0; v < m; v++)
        {
            if (cost[node][v] == 1 && !visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

void dfs(int start)
{
    bool visited[10] = {false};
    stack<int> st;

    st.push(start);
    visited[start] = true;

    cout << "DFS Traversal: ";

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        cout << node << " ";

        for (int d = 0; d < m; d++)
        {
            if (cost[node][d] == 1 && !visited[d])
            {
                st.push(d);
                visited[d] = true;
            }
        }
    }
    cout << endl;
}

int main()
{
    input();
    displayAdjMat();

    int start;
    cout << "Enter the starting node for BFS and DFS: ";
    cin >> start;
    bfs(start);
    dfs(start);

    return 0;
}