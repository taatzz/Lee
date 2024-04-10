#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100010;
long long s1[N], s2[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 1; i <= n; i++) s1[i] = s1[i - 1] + a[i - 1];
    for(int i = 1; i <= m; i++) s2[i] = s2[i - 1] + b[i - 1];

    long long res = 0x3f3f3f3f3f3f3f3f;
    // 枚举每一个位置作为符合条件的点时的答案
    for(int i = 0; i < n; i++)
    {
        int x = a[i];
        int idx2 = upper_bound(b.begin(), b.end(), x) - b.begin();

        long long l = (long long)i * x - s1[i], r = s2[m] - s2[idx2] - (long long)(m - idx2) * x;
        res = min(res, l + r);
    }

    for(int i = 0; i < m; i++)
    {
        int x = b[i];
        int idx = upper_bound(a.begin(), a.end(), x) - a.begin();
        long long l = (long long)idx * x - s1[idx], r = s2[m] - s2[i] - (long long)(m - i) * x;
        res = min(res, l + r);
    }

    cout << res << endl;
}

int main()
{
    int r = 1;
    while(r --) solve();

    return 0;
}