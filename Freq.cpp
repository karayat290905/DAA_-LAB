#include<bits/stdc++.h>
using namespace std;

pair<int,int> maxfreq(string s,int n){

    vector<int>hash(256,0);
    for(int i=0;i<n;i++){
        hash[s[i]]++;
    }
    int maxi = INT_MIN;
    int x;
    for(int i=0;i<256;i++){
        if(hash[i]>maxi){
            maxi = hash[i];
            x = i;
        }
        
    }
    return {maxi,x};
}

int main(){
    string s;
    cin>>s;
    int n = s.size();
    for(int i=0;i<n;i++){
        s[i] =   tolower(s[i]);
    }
    pair<int,int> ans = maxfreq(s,n);
    cout<<"MAX frequency is "<<ans.first<<" max frequency element is "<<s[ans.second-'a']<<endl;
    return 0;
}
