#include <bits/stdc++.h>

using namespace std;

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int k = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > k)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = k;
    }
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the elements of array:" << endl;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    insertionSort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}