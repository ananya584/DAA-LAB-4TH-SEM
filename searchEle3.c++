//time complexity O(root n):->jump search 
#include<iostream>
using namespace std;

int min(int steps, int size){
    if(size > steps){
        return size;
    }
    else{
        return steps;
    }
}

void jumpSearch(int arr[], int element, int size){
    int steps = sqrt(size);

    int prev = 0, flag = 0, index, count = 0;

    //for the block
    while(arr[min(steps, size) - 1] < element){
        prev = steps;
        steps += sqrt(size);
        count++;
        if(prev >= size){
            flag = 0;
            break;
        }
    }

    //for linear search
    while(arr[prev] < element){
        prev++;
        count++;
        if(prev == min(steps, size)){
            flag = 0;
            break;
        }
    }

    if(arr[prev] == element){
        flag = 1;
        index = prev;
    }

    if(flag == 0){
        cout<<"Element "<<element<<" is not present!";
    }
    else{
        cout<<"Element "<<element<<" is present at "<<index + 1<<" index"<<endl
        <<"Total number of comparisons are: "<<count;
    }
}

int main(){
    int arr[100];
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int element;
    cout<<"Enter the element you want to search: ";
    cin>>element;
    jumpSearch(arr, element, n);   
}