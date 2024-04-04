#include <iostream>
using namespace std;

int partition(int arr[], int low, int high, int &comparisons, int &swaps)
{
    int pivot = arr[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {

            swap(arr[i], arr[j]);
            swaps++;
            i++;
        }
    }

    swap(arr[low], arr[i - 1]);
    swaps++;

    return (i - 1);
}

void quickSort(int arr[], int low, int high, int &comparisons, int &swaps)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high, comparisons, swaps);

        quickSort(arr, low, pivotIndex - 1, comparisons, swaps);
        quickSort(arr, pivotIndex + 1, high, comparisons, swaps);
    }
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int comparisons = 0, swaps = 0;
    quickSort(arr, 0, n - 1, comparisons, swaps);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << "Number of comparisons made are: " << comparisons << endl
         << "Number of swaps made are: " << swaps;
}