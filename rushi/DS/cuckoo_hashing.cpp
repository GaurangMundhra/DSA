#include <iostream>

#include <vector>

using namespace std;

const int TABLE_SIZE = 11; // prime table size to reduce collisions
const int MAX_LOOP = 20;   // to avoid infinite loops

class CuckooHash
{
    int table1[TABLE_SIZE];
    int table2[TABLE_SIZE];

    // Simple hash functions
    int hash1(int key) { return key % TABLE_SIZE; }
    int hash2(int key) { return (key / TABLE_SIZE) % TABLE_SIZE; }

public:
    CuckooHash()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table1[i] = table2[i] = -1;
    }

    // Insert a key into cuckoo hash
    void insert(int key)
    {
        int pos, tempKey = key;
        for (int i = 0; i < MAX_LOOP; ++i)
        {
            pos = hash1(tempKey);
            if (table1[pos] == -1)
            {
                table1[pos] = tempKey;
                return;
            }

            // Kick out the existing key
            swap(tempKey, table1[pos]);

            pos = hash2(tempKey);
            if (table2[pos] == -1)
            {
                table2[pos] = tempKey;
                return;
            }

            swap(tempKey, table2[pos]);
        }

        cout << "Rehash needed. Couldn't place key " << key << endl;
    }

    // Search for a key
    bool search(int key)
    {
        if (table1[hash1(key)] == key)
            return true;
        if (table2[hash2(key)] == key)
            return true;
        return false;
    }

    // Display both tables
    void display()
    {
        cout << "\nTable 1: ";
        for (int i = 0; i < TABLE_SIZE; ++i)
            cout << (table1[i] == -1 ? -1 : table1[i]) << " ";

        cout << "\nTable 2: ";
        for (int i = 0; i < TABLE_SIZE; ++i)
            cout << (table2[i] == -1 ? -1 : table2[i]) << " ";

        cout << endl;
    }
};

// Driver
int main()
{
    CuckooHash ch;
    int n, val, choice;

    cout << "How many values do you want to insert? ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        ch.insert(val);
    }

    ch.display();

    cout << "\nSearch for a key? (1 for Yes / 0 for No): ";
    cin >> choice;
    while (choice)
    {
        cout << "Enter value to search: ";
        cin >> val;
        if (ch.search(val))
            cout << val << " found in table.\n";
        else
            cout << val << " not found.\n";

        cout << "\nSearch again? (1 for Yes / 0 for No): ";
        cin >> choice;
    }

    return 0;
}

// Cuckoo Hashing is a collision resolution technique used in hash tables that ensures constant-time lookup (O(1)) in the worst case.
// It cleverly uses multiple hash functions and multiple tables to resolve collisions by kicking out existing elements (like a cuckoo bird evicts other birds' eggs from the nest — hence the name).

// Basic Idea:
// Use two (or more) hash functions: h1() and h2().

// Use two tables (or positions) to store each key.

// If a collision happens at the primary position, the existing element is kicked out and moved to its alternate position.

// This can repeat for a few steps (if needed), or trigger a rehash if it loops too many times.
