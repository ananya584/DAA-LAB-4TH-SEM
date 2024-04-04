//time complexity O(n log n)
#include <iostream>
#include <algorithm> // For std::sort
using namespace std;

//time complexity:O(log n)
void binarySearch(int arr[], int n, int element, int& count) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        count++;
        if (arr[mid] == element)
            return;
        if (arr[mid] < element)
            left = mid + 1;
        else
            right = mid - 1;
    }
}

void searchAndCount(int arr[], int n, int element) {
    int count = 0;
    binarySearch(arr, n, element, count);
    cout << "Number of comparisons for element " << element << ": " << count << endl;
}

int main() {
    int arr[100];
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Sort the array to ensure binary search works correctly
    sort(arr, arr + n);
    int element;
    cout << "Enter the element you want to search: ";
    cin >> element;

    //time complexity:O(n)
    for (int i = 0; i < n; i++) {
        searchAndCount(arr, n, element);
    }
    return 0;
}