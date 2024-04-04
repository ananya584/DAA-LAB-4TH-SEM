//Given an unsorted array of alphabets containing duplicate elements. Design an algorithm
//and implement it using a program to find which alphabet has maximum number of
//occurrences andprint it. (Time Complexity = O(n)) (Hint: Use counting sort)

#include<iostream>
using namespace std;

int countingSort(char arr[], int n, int &frequency){
    int range = 26;

    //count array
    int count[range];
    for(int i = 0; i < range; i++){
        count[i] = 0;
    }

    //for frequency in count array
    for(int j = 0; j < n; j++){
        count[arr[j] - 97]++;
    }

    frequency = count[0];
    int index;
    for(int i = 0; i < range; i++){
        if(count[i] > frequency){
            frequency = count[i];
            index = i;
        }
    }

    return index;
}

int main(){
    char arr[100];
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int frequency = 0;
    int element = countingSort(arr, n, frequency);

    cout<<"The frequency of "<<char(element + 97)<<" is: "<<frequency;
}