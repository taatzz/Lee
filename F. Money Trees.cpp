#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;


void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int i = 0, res = 0;
    while(i < n)
    {
        int start = i;
        i++;
        while(i < n && (b[i - 1] % b[i] == 0)) i++;

        int sum = 0;
        for(int l = start, r = start; r < i; r++)
        {
            sum += a[r];
            while(l <= r && sum > k) sum -= a[l++];
            res = max(res, r - l + 1);
        }
    }

    cout << res << endl;
}

int main()
{
    int r = 1;
    cin >> r;
    while(r --) solve();

    return 0;
}