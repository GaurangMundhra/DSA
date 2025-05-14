#include <bits/stdc++.h>

using namespace std;

int BinarySearch(int a[], int left, int right, int target)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;

        if (a[mid] == target)
            return mid;
        if (a[mid] < target)
        {
            left = mid + 1;
            return BinarySearch(a, left, right, target);
        }
        if (a[mid] > target)
        {
            right = mid - 1;
            return BinarySearch(a, left, right, target);
        }
    }
    return -1;
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

    int target;
    cout << "Enter the target: ";
    cin >> target;
    int ans = BinarySearch(a, 0, n - 1, target);
    if (ans != -1)
        cout << "Target found at index: " << ans << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}