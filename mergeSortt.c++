#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r, int &comparisons, int &inversions)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1], R[n2];

    int i, j, k;
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
            inversions += (n1 - i);
        }
        comparisons++;
    }
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int l, int r, int &comparisons, int &inversions)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid, comparisons, inversions);
        mergeSort(arr, mid + 1, r, comparisons, inversions);

        merge(arr, l, mid, r, comparisons, inversions);
    }
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int comparisons = 0, inversions = 0;
    mergeSort(arr, 0, n - 1, comparisons, inversions);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Output number of comparisons and inversions
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total inversions: " << inversions << endl;
    return 0;
}
