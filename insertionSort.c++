#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key, j, i, countShifts = 0, comparisons = 0;
    for (j = 1; j < n; j++)
    {
        i = j - 1;
        key = arr[j];
        while (i >= 0 && arr[i] > key)
        {
            comparisons++;
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        countShifts++;
        arr[i + 1] = key;
    }
    cout << "The total number of comparisons to sort the array: " << comparisons << endl
         << "The total number of comparisons made are: " << countShifts + comparisons;
}