#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int n, x;
    cin>> n >> x;
    vector<long long> arr(n);
    for(auto&it:arr) cin>> it;
    
    vector<long long>prefixSum(n);
    prefixSum[0] = arr[0];

    for(int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    // for(int i = 0; i < n; i++){
    //     cout<<prefixSum[i]<<" ";
    // }
    // cout<<endl;
    map<long long ,long long >mp;
    
    long long sum = 0;
    mp[0] = 1;
    long long count = 0;
    for(int i = 0;i<n;i++){
        sum += arr[i];
        if(mp.find(sum-x) != mp.end()){
            count += mp[sum-x];
        }
        mp[sum]++;
    }

    cout<<count<<endl;
    return 0;
};
