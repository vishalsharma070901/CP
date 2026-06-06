#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main (){
    long long n, q;
    cin>> n >> q;

    vector<long long >v(n);
    for(auto &x : v) cin >> x;

    vector<long long >diff(n + 2, 0);

    
    while(q--){
        long long l, r;
        cin>> l >> r;
        
        diff[l] += 1;
        diff[r+1] -= 1;  
    }

    for(int i = 1; i <= n; i++){
        diff[i] += diff[i-1];
    }

    sort(diff.begin()+1, diff.begin()+n+1);
    sort(v.begin(), v.end());
 
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans+= diff[i+1] * v[i];
    }
    cout<< ans;

    return 0;

}