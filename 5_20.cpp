#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    
    vector<int> cnt(4);
    int res = 1e9, sum = 0;
    for(int i = 0, j = 0; i < n; i++)
    {
        int u = s[i] - '0';
        if(cnt[u]++ == 0) sum++;
        
        while(j <= i && sum >= 3)
        {
            res = min(res, i - j + 1);
            if(--cnt[s[j++] - '0'] == 0) sum--;
        }
    }
    
    if(res == 1e9) cout << 0 << endl;
    else cout << res << endl;
}

int main()
{
    int r = 1;
    cin >> r;
    while(r --) solve();
    
    return 0;
}