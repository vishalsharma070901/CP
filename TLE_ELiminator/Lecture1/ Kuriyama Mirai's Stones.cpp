#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>> n;

    vector<long long> arr(n);

    for(int i  = 0;i<n;i++){
        cin>>arr[i];
    }
    
    vector<long long> prefixSum(n);
    prefixSum[0] = arr[0];

    for(int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    sort(arr.begin(), arr.end());
    vector<long long> sortedPrefixSum(n);
    sortedPrefixSum[0] = arr[0];
    for(int i = 1; i < n; i++){
        sortedPrefixSum[i] = sortedPrefixSum[i-1] + arr[i];
    }


    int q;
    cin>> q;

    while(q--){
        long long  ans = 0;
        int t, l, r;
        cin>> t >> l >> r;
        if(t == 1){
            if (l-1 == 0)  ans = prefixSum[r-1];
            else ans = prefixSum[r-1] - prefixSum[l-2];
        }else{
            if(l-1 == 0) ans = sortedPrefixSum[r-1];
            else ans = sortedPrefixSum[r-1] - sortedPrefixSum[l-1] + arr[l-1];
        }
        cout<< ans << endl;
    }
    return 0;
}