//time complexity of  O(n):->linear search
#include<iostream>
using namespace std;

void linearSearch(int arr[], int element, int size){
    int count = 0, flag = 0, index;
    for(int i = 0; i < size; i++){
        count++;
        if(arr[i] == element){
            index = i;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout<<"Element "<<element<<" is not present!";
    }
    else{
        cout<<"Element "<<element<<" is present at "<<index + 1<<" index"<<endl<<"Total number of comparisons are: "<<count;
    }
}

int main(){
    int arr[100];
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Enter "<<n<<" sorted elements:\n";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int element;
    cout<<"Enter the element you want to search: ";
    cin>>element;
    linearSearch(arr, element, n);
}