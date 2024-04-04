//find minimum in rotated sorted array
#include<iostream>
using namespace std;

int main(){
    int arr[100];
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int i, lastIndexElement, timesToRotate, count = 0;
    cout<<"Enter the number of times you want to rotate the array: ";
    cin>>timesToRotate;

    while(count < timesToRotate){
        lastIndexElement = arr[n - 1];
        count++;
        for(i = n - 1; i >= 0; i--){
            arr[i] = arr[i - 1];
        }
        arr[0] = lastIndexElement;
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<endl;
    }
    int* element = min_element(arr, arr + n);
    cout<<"The minimum element in the rotated array is: "<<*element;
}