// Given an array of N elements, answer the following Q queries
// ● Query: L, R
// ● Result = A[L] + 2 * A[L + 1] + 3 * A[L + 2] + .... (R - L + 1) * A[R]

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n ,q;
    cin>> n >> q;
    vector<long long> arr(n+1);
    for(int i = 1;i<=n;i++) cin >> arr[i];
    
    int ans = 0;

    while(q--){
        int l, r;
        cin>> l >> r;

        for(int i = l; i <= r; i++){
            ans += (i-l+1)*arr[i];
        }
        cout << ans << endl;

    }


    return 0;

}