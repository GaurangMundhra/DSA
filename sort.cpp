#include <iostream>
using namespace std;

class Sort {
public:
    void SelectionSort(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            int miniIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[miniIndex] > arr[j]) {
                    miniIndex = j;
                }
            }
            int temp = arr[miniIndex];
            arr[miniIndex] = arr[i];
            arr[i] = temp;
        }
    }

    void bubbleSort(int arr[] , int n){
        for(int i = 0; i < n - 1 ; i++){
            for(int j = 0 ; j < n - i - 1; j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    void insertionSort(int arr[], int n) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};

void takeInput(int arr[], int &length) {
    cout << "Enter the length of array: ";
    cin >> length;

    cout << "Enter the elements: ";
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }
}

int main() {
    int n = 0;
    int arr[100];  

    int choice = 0;
    Sort s;

    while (choice != 5) {
        cout << "\nMenu:\n1. Take Input\n2. Selection Sort\n3. Insertion Sort\n 4.Bubblesort\n 5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                takeInput(arr, n);
                break;

            case 2:
                s.SelectionSort(arr, n);
                cout << "Array after Selection Sort: ";
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;

            case 3:
                s.insertionSort(arr, n);
                cout << "Array after Insertion Sort: ";
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;

            case 4:
                s.bubbleSort(arr, n);
                cout << "Array after Bubble Sort: ";
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
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
