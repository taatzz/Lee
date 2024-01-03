#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N = 100010;
long long n, len;
long long s[N], l[N];

bool check(long long x)
{
    vector<pair<long, long>> t;
    for(int i = 0; i < n; i++)
    {
        if(x < s[i]) continue;
        long long left = max(1LL, l[i] - (x - s[i]));
        long long right = min(len, l[i] + (x - s[i]));
        t.push_back({left, right});
    }
    sort(t.begin(), t.end());
    if(t.size() == 0) return false;
    if(t[0].first > 1) return false;
    
    vector<pair<long, long>> res;
    for(auto e : t)
    {
        if(res.empty())
            res.push_back(e);
        else if(res.back().second < e.first)
            res.push_back(e);
        else
        {
            auto tmp = res.back();
            res.pop_back();
            res.push_back({min(tmp.first, e.first), max(tmp.second, e.second)});
        }
    }

    long long last = len;
    for(int i = res.size() - 1; i >= 0; i--)
    {
        if(res[i].second < last) return false;
        else if(res[i].second >= last) last = res[i].first - 1;
    }
    
    return true;
}

int main()
{
    
    cin >> n >> len;

    for(int i = 0; i < n; i++)
    {
        cin >> l[i] >> s[i];
    }

    long long l = 0, r = 2e9;
    while(l < r)
    {
        long long mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << endl;

    return 0;
}