#include <bits/stdc++.h>

using namespace std;

#define MOD 11

vector<vector<int>> adj;

int nodes;
int arr[MOD][2];

// BFS traversal
vector<int> bfs(int start)
{
    vector<int> res;
    vector<bool> visited(nodes, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        for (int x : adj[curr])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
    return res;
}

// DFS traversal (iterative using stack)
vector<int> dfs(int start)
{
    vector<int> res;
    vector<bool> visited(nodes, false);
    stack<int> st;
    st.push(start);
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        if (!visited[curr])
        {
            visited[curr] = true;
            res.push_back(curr);
            for (int i = adj[curr].size() - 1; i >= 0; i--)
            {
                int neighbor = adj[curr][i];
                if (!visited[neighbor])
                {
                    st.push(neighbor);
                }
            }
        }
    }
    return res;
}

// Hash table insert
void insertIntoHashTable()
{
    int n;
    cout << "\nEnter the number of data to input: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (i >= 2 * MOD)
        {
            cout << "NO operation performed. Hash Table is Full" << endl;
            break;
        }
        int m = a % MOD;
        bool flag = false;
        for (int i = m; i < MOD; i++)
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
        }
    }
}

// Main
int main()
{
    for (int i = 0; i < MOD; i++)
        arr[i][0] = arr[i][1] = -1;

    int ch;
    while (true)
    {
        cout << "\n================= MENU =================\n";
        cout << "1. Enter Graph\n";
        cout << "2. BFS Traversal\n";
        cout << "3. DFS Traversal\n";
        cout << "4. Insert into Hash Table\n";
        cout << "5. Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter number of vertices: ";
            cin >> nodes;
            cin.ignore();
            adj.clear();
            adj.resize(nodes);
            cout << "Enter Graph edges: " << endl;
            for (int i = 0; i < nodes; i++)
            {
                cout << i << " -> ";
                string s;
                getline(cin, s);
                vector<int> temp;
                int num = 0;
                bool buildingNum = false;
                for (char ch : s)
                {
                    if (isdigit(ch))
                    {
                        num = num * 10 + (ch - '0');
                        buildingNum = true;
                    }
                    else if ((ch == ',' || ch == ' ') && buildingNum)
                    {
                        temp.push_back(num);
                        num = 0;
                        buildingNum = false;
                    }
                }
                if (buildingNum)
                    temp.push_back(num);
                adj[i] = temp;
            }
            cout << "Graph entered successfully.\n";
            break;
        }
        case 2:
        {
            int start;
            cout << "Enter starting vertex for BFS: ";
            cin >> start;
            if (start < 0 || start >= nodes)
                cout << "Invalid node.\n";
            else
            {
                vector<int> result = bfs(start);
                cout << "BFS Traversal: ";
                for (int x : result)
                    cout << x << " ";
                cout << endl;
            }
            break;
        }
        case 3:
        {
            int start;
            cout << "Enter starting vertex for DFS: ";
            cin >> start;
            if (start < 0 || start >= nodes)
                cout << "Invalid node.\n";
            else
            {
                vector<int> result = dfs(start);
                cout << "DFS Traversal: ";
                for (int x : result)
                    cout << x << " ";
                cout << endl;
            }
            break;
        }
        case 4:
        {
            insertIntoHashTable();
            cout << "Hash Table: \n\n";
            cout << "Rem\tslot 1\tslot 2\n";
            for (int i = 0; i < MOD; i++)
                cout << i << "\t" << arr[i][0] << "\t" << arr[i][1]
                     << endl;
            break;
        }
        case 5:
            cout << "Exiting..." << endl;
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}