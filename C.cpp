#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> s(n + 1);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    
    ll res = 0;
    for(int i = 1; i <= n && s[i] <= s[n] / 2; i++)
    {
        int l = i + 1, r = n;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(s[mid] - s[i] > s[i] && s[mid] - s[i] > s[n] - s[mid]) r = mid;
            else l = mid + 1;
        }
        if(l <= n)
            res += n - l;
    }
    cout << res;
    
    return 0;
}