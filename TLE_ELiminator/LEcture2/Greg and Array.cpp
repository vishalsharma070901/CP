#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n, m, q;
    cin >> n >> m >> q;

    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    vector<long long> diff(n + 2, 0);
    vector<long long> diff2(m + 2, 0);

    vector<long long> l(m + 1), r(m + 1), d(m + 1);

    for (int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i] >> d[i];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        diff2[l] += 1;
        diff2[r + 1] -= 1;
    }

    for (int i = 1; i <= m; i++)
    {
        diff2[i] += diff2[i - 1];
    }



    for(int i = 1;i<=m;i++){
        diff[l[i]] += diff2[i]*d[i];
        diff[r[i]+1] -= diff2[i]*d[i];
    }

    for (int i = 1; i <= n; i++)
    {
        diff[i] += diff[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] + diff[i] << " ";
    }

    cout << endl;

    return 0;
}