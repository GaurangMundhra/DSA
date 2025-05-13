#include <iostream>
#include <vector>
using namespace std;

class FibonacciSearch
{
public:
    // Fibonacci search function
    int fibSearch(const vector<int> &arr, int key)
    {
        int n = arr.size();

        // Initialize fibonacci numbers
        int fibMMm2 = 0;              // (m-2)'th Fibonacci No.
        int fibMMm1 = 1;              // (m-1)'th Fibonacci No.
        int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci

        // fibM is the smallest Fibonacci number >= n
        while (fibM < n)
        {
            fibMMm2 = fibMMm1;
            fibMMm1 = fibM;
            fibM = fibMMm2 + fibMMm1;
        }

        int offset = -1;

        while (fibM > 1)
        {
            int i = min(offset + fibMMm2, n - 1);

            if (arr[i] < key)
            {
                fibM = fibMMm1;
                fibMMm1 = fibMMm2;
                fibMMm2 = fibM - fibMMm1;
                offset = i;
            }
            else if (arr[i] > key)
            {
                fibM = fibMMm2;
                fibMMm1 = fibMMm1 - fibMMm2;
                fibMMm2 = fibM - fibMMm1;
            }
            else
            {
                return i;
            }
        }

        // Check if last element is key
        if (fibMMm1 && offset + 1 < n && arr[offset + 1] == key)
            return offset + 1;

        return -1;
    }
};

int main()
{
    FibonacciSearch fs;
    vector<int> arr;
    int choice, val, key, index;

    cout << "=== Fibonacci Search Menu ===\n";

    do
    {
        cout << "\n1. Enter sorted array\n2. Display array\n3. Search for element\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            arr.clear();
            int n;
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter " << n << " sorted elements:\n";
            for (int i = 0; i < n; i++)
            {
                cin >> val;
                arr.push_back(val);
            }
            break;

        case 2:
            cout << "Array: ";
            for (int i : arr)
                cout << i << " ";
            cout << endl;
            break;

        case 3:
            if (arr.empty())
            {
                cout << "Array is empty. Please input the array first.\n";
                break;
            }
            cout << "Enter key to search: ";
            cin >> key;
            index = fs.fibSearch(arr, key);
            if (index != -1)
                cout << "Key found at index " << index << "\n";
            else
                cout << "Key not found in the array.\n";
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
