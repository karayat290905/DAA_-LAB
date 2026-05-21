#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>&arr,int n){
    if(n <= 1)return;
    for(int i=1;i<n;i++){
        int key =arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<"Unsorted array:\n";
    for(int i=0;i<n;i++)cout<<arr[i]<<"  ";
    insertion_sort(arr,n);
    cout<<"\nSorted array:\n";
    for(int i=0;i<n;i++)cout<<arr[i]<<"  ";
    return 0;
}
