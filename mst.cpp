#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int u, int v)
    {
        int pu = find(u), pv = find(v);
        if (pu == pv)
            return false;
        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};

class MST
{
public:
    int primMST(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        pq.push({0, 0});
        int sum = 0;

        while (!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (vis[node])
                continue;
            vis[node] = 1;
            sum += wt;

            for (auto &it : adj[node])
            {
                int adjNode = it[0];
                int edgeW = it[1];
                if (!vis[adjNode])
                {
                    pq.push({edgeW, adjNode});
                }
            }
        }

        return sum;
    }

    int kruskalMST(int V, vector<vector<int>> &edges)
    {
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b)
             { return a[2] < b[2]; });

        DSU dsu(V);
        int sum = 0;
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dsu.unite(u, v))
            {
                sum += w;
            }
        }
        return sum;
    }
};

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj[V];
    vector<vector<int>> edges;

    cout << "Enter edges in format (u v weight):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    MST obj;
    int choice;
    do
    {
        cout << "\nMENU:\n";
        cout << "1. Find MST using Prim's Algorithm\n";
        cout << "2. Find MST using Kruskal's Algorithm\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Prim's MST weight: " << obj.primMST(V, adj) << endl;
            break;
        case 2:
            cout << "Kruskal's MST weight: " << obj.kruskalMST(V, edges) << endl;
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
