#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(auto &it:arr) cin >> it;

    // cout<<n<<" "<<q<<endl;

    // for(int i = 0; i < n; i++){
    //    cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    vector<long long> prefixSum(n);

    prefixSum[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
    // for(int i = 0; i < n; i++){
    //    cout<<prefixSum[i]<<" ";
    // }
    // cout<<endl;

    while(q--){
        int l, r;
        cin >> l >> r;
        long long sum = 0;
        if(l == 0) sum = prefixSum[r];
       
        else sum = prefixSum[r-1] - prefixSum[l-1] + arr[l-1];
        //  cout << "l: " << l << " r: " << r << endl;
        //  cout<<prefixSum[r-1]<<" "<<prefixSum[l-1]<<endl;
        cout << sum << endl;
    }

    return 0;   
}