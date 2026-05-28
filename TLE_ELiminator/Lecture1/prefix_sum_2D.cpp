#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<long long>> prefixSum(n, vector<long long>(m));

    // Build prefix sum
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            prefixSum[i][j] = arr[i][j];

            if(i > 0)
                prefixSum[i][j] += prefixSum[i-1][j];

            if(j > 0)
                prefixSum[i][j] += prefixSum[i][j-1];

            if(i > 0 && j > 0)
                prefixSum[i][j] -= prefixSum[i-1][j-1];
        }
    }

    // Print prefix matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << prefixSum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}