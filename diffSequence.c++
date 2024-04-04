#include<iostream>
using namespace std;

int main(){
    int arr[100];
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int element;
    cout<<"Enter the element: ";
    cin>>element;

    int i, j, count = 0, difference;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            difference = arr[i] - arr[j];
            if(difference == element){
                count++;
            }
        }
    }
    cout<<"The total number of pairs: "<<count;
}