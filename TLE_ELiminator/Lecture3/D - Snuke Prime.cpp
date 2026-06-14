#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    long long n, c;
    cin >> n >> c;

    vector<long long> start(n), endd(n), cost(n);

    for (int i = 0; i < n; i++)
    {
        cin >> start[i] >> endd[i] >> cost[i];
    }

    set<long long> s;

    // Coordinate compression points
    for (int i = 0; i < n; i++)
    {
        s.insert(start[i]);
        s.insert(endd[i] + 1);
    }

    map<long long, int> mp;
    int idx = 0;

    for (auto x : s)
    {
        mp[x] = idx++;
    }

    vector<long long> diff(idx + 1, 0);

    // Difference array on compressed coordinates
    for (int i = 0; i < n; i++)
    {
        diff[mp[start[i]]] += cost[i];
        diff[mp[endd[i] + 1]] -= cost[i];
    }

    // Prefix sum to get active cost on each segment
    for (int i = 1; i < idx; i++)
    {
        diff[i] += diff[i - 1];
    }

    vector<long long> coord(s.begin(), s.end());

    long long ans = 0;

    for (int i = 1; i < coord.size(); i++)
    {
        long long span = coord[i] - coord[i - 1];
        ans += min(diff[i - 1], c) * span;
    }

    cout << ans << '\n';

    return 0;
}