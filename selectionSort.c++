#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int i, j, minIndex, countShifts = 0, comparisons = 0;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        countShifts++;
        swap(arr[j], arr[minIndex]);
    }
    cout << "The total number of comparisons to sort the array: " << comparisons << endl
         << "The total number of swaps made are: " << countShifts;
}