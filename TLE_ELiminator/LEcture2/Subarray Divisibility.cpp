#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<long long> prefixSum(n);



    map<long long, long long> mp;
    long long count = 0;
    long long sum = 0;
    mp[0] = 1;

    for (int j = 0; j < n; j++)
    {

        sum += arr[j];
        
        long long mod = ((sum % n) + n) % n;

        count +=mp[mod];
        mp[mod]++;
    }
    cout << count << endl;
    return 0;
}