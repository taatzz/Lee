#include <iostream>

using namespace std;


void solve()
{
    int n, s;
    cin >> n >> s;

    long long pre = 0, l = s, r = s;
    bool flag = 1;
    for(int i = 0; i < n; i++)
    {
        long long t, a, b;
        cin >> t >> a >> b;
        l -= t - pre;
        r += t - pre;
        if(l > b || r < a) 
        {
            flag = 0;
        }
        l = max(l, a);
        r = min(r, b);
        pre = t;
    }

    if(flag)
        cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    int r;
    cin >> r;

    while(r --) solve();

    return 0;
}