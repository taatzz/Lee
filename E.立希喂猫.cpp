#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<long long> t(n + 1), s(n + 1);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<pair<int, int>> tmp(n + 1);
    for(int i = 0; i < n; i++) tmp[i] = {b[i], a[i]};
    sort(tmp.begin(), tmp.end());

    for(int i = 1; i <= n; i++) 
    {
        int x = tmp[i].first, y = tmp[i].second;
        s[i] = s[i - 1] + (long long)x * y;
    }
    for(int i = 1; i <= n; i++) t[i] = t[i - 1] + tmp[i].second;
    
    auto find = [&](int x)
    {
        int l = 0, r = tmp.size() - 1;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(tmp[mid].first <= x) l = mid;
            else r = mid - 1;
        }

        return l + 1;
    };

    int q;
    vector<int> query;
    cin >> q;
    while(q --)
    {
        int k;
        cin >> k;
        
        int idx = find(k);
        long long res = 0;
        res = s[idx - 1] + (t[n] - t[idx - 1]) * k;

        cout << res << endl;
    }
}

int main()
{
    int r = 1;
    // cin >> r;
    while(r --) solve();

    return 0;
}