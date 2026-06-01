#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)cin >> v[i]; //n
    
    int q;
    cin >> q;

    vector<int>diff(n + 1, 0);

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x; //O-based indexing
        diff[l] += x;
        diff[r + 1] -= x;
    }
    //take prefix sum of diff array
    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] + diff[i+1] << " ";
    }
    cout << endl;

}