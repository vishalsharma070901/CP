// Given an array of N elements, answer the following Q queries
// ● Query: L, R
// ● Result = A[L] + 2 * A[L + 1] + 3 * A[L + 2] + .... (R - L + 1) * A[R]

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    vector<long long> prefixSum(n + 1, 0);
    vector<long long> prefixSum2(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + i * arr[i];
        prefixSum2[i] = prefixSum2[i - 1] + arr[i];
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << prefixSum[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << prefixSum2[i] << " ";
    // }
    // cout << endl;

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << (prefixSum[r] - prefixSum[l - 1]) - (l - 1) * (prefixSum2[r] - prefixSum2[l - 1]) << endl;
    }

    return 0;
}