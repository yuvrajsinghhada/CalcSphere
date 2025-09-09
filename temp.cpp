/*
author: satyammthakur   
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define mod 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long t=0;
    cin>>t;
    while(t--){
        long long n=0;
        cin>>n;
        vector<long long>a(n);
        // unordered_map<long long , int>mpp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            // mpp[a[i]]++;
        }
        int flag=0;
        sort(a.begin(),a.end());
        long long score=0;
        if(n%2==0){
            for(int i=1;i<n;i+=2){
                score+=a[i];
            }
        }
        else{
            for(int i=0;i<n;i+=2){
                score+=a[i];
            }
        }
        cout<<score<<endl;
        // for(auto &it:mpp){
        //     if(it.second>=2){
        //         flag=1;
        //         break;
        //     }
        // }
        // if(flag) cout<<"YES"<<endl;
        // else cout<<"NO"<<endl;
    }
    return 0;
}