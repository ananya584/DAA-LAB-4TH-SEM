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

    int i, j , k, sum, index, flag = 0;
    for(k = n - 1; k >= 0; k--){
        i = 0, j = k - 1;
        while(i < j){
            if(arr[i] + arr[j] == arr[k]){
                cout<<"Indices are: "<<i + 1<<", "<< j + 1 <<", "<<k + 1;
                flag = 1;
                break;
            }
            else if(arr[i] + arr[j] < arr[k]){
                i++;
            }
            else{
                j--;
            }
        }
    }
    if(flag == 0){
        cout<<"No sequence found";
    }
}