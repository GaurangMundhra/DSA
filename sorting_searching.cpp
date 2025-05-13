#include <iostream>
using namespace std;

class Sort
{
public:
    void merge(int arr[], int low, int mid, int high)
    {
        int left = low;
        int right = mid + 1;
        int temp[high - low + 1];
        int i = 0;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp[i++] = arr[left++];
            }
            else
            {
                temp[i++] = arr[right++];
            }
        }

        while (left <= mid)
        {
            temp[i++] = arr[left++];
        }
        while (right <= high)
        {
            temp[i++] = arr[right++];
        }

        for (int i = 0; i < high - low + 1; i++)
        {
            arr[low + i] = temp[i];
        }
    }

    void insertionSort(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int j = i;
            while (j > 0 && arr[j - 1] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                j--;
            }
        }
    }

    void mergeSort(int arr[], int l, int r)
    {
        int mid = (l + r) / 2;
        if (l >= r)
            return;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
};

void takeInput(int arr[], int &length)
{
    cout << "Enter the length of array: ";
    cin >> length;

    cout << "Enter the elements: ";
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }
}

int binarySearch(int arr[], int low, int high, int target)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            return binarySearch(arr, low, mid - 1, target);
        }
        else
        {
            return binarySearch(arr, mid + 1, high, target);
        }
    }
    return -1;
}

int main()
{
    int n = 0;
    int arr[100];
    int ans;

    int choice = 0;
    Sort s;

    while (choice != 5)
    {
        cout << "\nMenu:\n1. Take Input\n2. Insertion Sort\n3. Merge Sort\n 4.Binary Search\n 5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            takeInput(arr, n);
            break;

        case 2:
            s.insertionSort(arr, n);
            cout << "Array after Insertion Sort: ";
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;

        case 3:

            s.mergeSort(arr, 0, n - 1);
            cout << "Array after Merge Sort: ";
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;

        case 4:
            int target;
            cout << " Enter the target" << endl;
            cin >> target;
            ans = binarySearch(arr, 0, n - 1, target);
            if (ans != -1)
            {
                cout << "Target found at index" << ans << endl;
            }
            else
            {
                cout << "Target not found" << endl;
            }
            break;
        case 5:
            cout << "Exiting Program." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}