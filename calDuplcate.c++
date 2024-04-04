#include <iostream>
#include <algorithm> 
using namespace std;

int binarySearch(int arr[], int n, int element)
{
    int left = 0;
    int right = n - 1;
    int count = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == element)
        {
            count++; 
            int i = mid - 1;
            while (i >= left && arr[i] == element)
            {
                count++;
                i--;
            }
           
            i = mid + 1;
            while (i <= right && arr[i] == element)
            {
                count++;
                i++;
            }
            return count; 
        }
        else if (arr[mid] < element)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return count; 
}

int main()
{
    int arr[100];
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int element;
    cout << "Enter the element you want to search: ";
    cin >> element;

    int count = binarySearch(arr, n, element);
    if (count > 0)
    {
        cout << "Number of copies of " << element << " are: " << count;
    }
    else
    {
        cout << "Element " << element << " is not present";
    }
    return 0;
}
