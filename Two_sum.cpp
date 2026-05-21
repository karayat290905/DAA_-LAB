#include<bits/stdc++.h>
using namespace std;
pair<int,int> twosum(vector<int>&arr,int n,int target){
    unordered_map<int,int>mpp;
    pair<int,int>pp;
    for(int i=0;i<n;i++){
        int k = arr[0];
        if(mpp.find(target-k)!= mpp.end()){
            pp.first = k;
            pp.second = target-k;
        }
        else mpp[arr[i]]++;
    }
    return pp;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    pair<int,int>ans = twosum(arr,n,k);
    cout<<ans.first<<" + "<<ans.second<<" = "<<k<<endl;
    return 0;
}
