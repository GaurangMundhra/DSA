#include <iostream>
#include <vector>
#define TABLE_SIZE 11

using namespace std;

class CuckooHash
{
private:
    vector<int> table1, table2;
    int size;

    int hash1(int key)
    {
        return key % size;
    }

    int hash2(int key)
    {
        return (key / size) % size;
    }

public:
    CuckooHash(int size = TABLE_SIZE)
    {
        this->size = size;
        table1.assign(size, -1);
        table2.assign(size, -1);
    }

    bool place(int key, int count, int tableId)
    {
        if (count >= size)
        {
            cout << "Cycle detected! Rehash needed for key: " << key << endl;
            return false;
        }

        int pos = (tableId == 1) ? hash1(key) : hash2(key);

        if (tableId == 1)
        {
            if (table1[pos] == -1)
            {
                table1[pos] = key;
                return true;
            }
            else
            {
                int displaced = table1[pos];
                table1[pos] = key;
                return place(displaced, count + 1, 2);
            }
        }
        else
        {
            if (table2[pos] == -1)
            {
                table2[pos] = key;
                return true;
            }
            else
            {
                int displaced = table2[pos];
                table2[pos] = key;
                return place(displaced, count + 1, 1);
            }
        }
    }

    void insert(int key)
    {
        if (!search(key))
        {
            if (!place(key, 0, 1))
            {
                cout << "Rehashing required. Could not insert key: " << key << endl;
            }
        }
        else
        {
            cout << "Key already exists in the table.\n";
        }
    }

    bool search(int key)
    {
        int pos1 = hash1(key);
        int pos2 = hash2(key);
        return table1[pos1] == key || table2[pos2] == key;
    }

    void remove(int key)
    {
        int pos1 = hash1(key);
        int pos2 = hash2(key);

        if (table1[pos1] == key)
        {
            table1[pos1] = -1;
            cout << "Key " << key << " deleted from Table 1\n";
        }
        else if (table2[pos2] == key)
        {
            table2[pos2] = -1;
            cout << "Key " << key << " deleted from Table 2\n";
        }
        else
        {
            cout << "Key not found\n";
        }
    }

    void display()
    {
        cout << "\nTable 1:\n";
        for (int i = 0; i < size; i++)
            cout << i << " --> " << (table1[i] == -1 ? "NULL" : to_string(table1[i])) << endl;

        cout << "Table 2:\n";
        for (int i = 0; i < size; i++)
            cout << i << " --> " << (table2[i] == -1 ? "NULL" : to_string(table2[i])) << endl;
    }
};

int main()
{
    CuckooHash hashTable;
    int choice, key;

    cout << "=== Cuckoo Hashing ===\n";

    do
    {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            hashTable.insert(key);
            break;

        case 2:
            cout << "Enter key to delete: ";
            cin >> key;
            hashTable.remove(key);
            break;

        case 3:
            cout << "Enter key to search: ";
            cin >> key;
            if (hashTable.search(key))
                cout << "Key found!\n";
            else
                cout << "Key not found!\n";
            break;

        case 4:
            hashTable.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
