#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MOD 11

vector<int> bfs(vector<vector<int>> &adj, int s)
{
    int V = adj.size();
    vector<int> vis(V, 0);
    queue<int> q;
    q.push(s);
    vis[s] = 1;

    vector<int> ls;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ls.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return ls;
}

void dfsHelper(int node, vector<vector<int>> &adj, vector<int> &res, vector<int> &vis)
{
    vis[node] = 1;
    res.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfsHelper(it, adj, res, vis);
        }
    }
}

vector<int> dfs(int s, vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<int> vis(V, 0);
    vector<int> res;
    dfsHelper(s, adj, res, vis);
    return res;
}

void hashTable()
{
    int arr[11][2];
    for (int i = 0; i < 11; i++)
        arr[i][0] = arr[i][1] = -1;

    int n;
    cout << "Enter number of elements to insert (Max 22): ";
    cin >> n;

    if (n > 22)
    {
        cout << "Only 22 elements allowed due to bucket size limit.\n";
        return;
    }

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        bool flag = false;
        int m = a % MOD;

        for (int i = m; i < 11; i++)
        {
            if (arr[i][0] == -1)
            {
                arr[i][0] = a;
                flag = true;
                break;
            }
            else if (arr[i][1] == -1)
            {
                arr[i][1] = a;
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            for (int i = 0; i < m; i++)
            {
                if (arr[i][0] == -1)
                {
                    arr[i][0] = a;
                    break;
                }
            }
        }
    }

    cout << "Hash Table:\n";
    for (int i = 0; i < 11; i++)
    {
        cout << i << " => " << arr[i][0] << " , " << arr[i][1] << endl;
    }
}

int main()
{

    vector<vector<int>> adj;
    int choice;

    do
    {
        cout << "========= MENU =========\n";
        cout << "1. BFS Traversal\n";
        cout << "2. DFS Traversal\n";
        cout << "3. Insert into Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2)
        {
            int V, E;
            cout << "Enter number of vertices: ";
            cin >> V;
            adj.assign(V, vector<int>());

            cout << "Enter number of edges: ";
            cin >> E;
            cout << "Enter edges (u v):\n";
            for (int i = 0; i < E; i++)
            {
                int u, v;
                cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u); // remove if directed graph
            }

            int start;
            cout << "Enter starting node: ";
            cin >> start;

            if (choice == 1)
            {
                vector<int> res = bfs(adj, start);
                cout << "BFS Traversal: ";
                for (int node : res)
                    cout << node << " ";
                cout << "\n";
            }
            else
            {
                vector<int> res = dfs(start, adj);
                cout << "DFS Traversal: ";
                for (int node : res)
                    cout << node << " ";
                cout << "\n";
            }
        }
        else if (choice == 3)
        {
            hashTable();
        }
        else if (choice == 4)
        {
            cout << "Exiting program.\n";
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
