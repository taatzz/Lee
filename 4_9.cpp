#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int N = 200010;
int a[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    string s;
    cin >> s;
    vector<int> l, r;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'B') l.push_back(a[i]);
        else r.push_back(a[i]);
    }

    sort(l.begin(), l.end());
    sort(r.begin(), r.end(), greater<int>());

    bool flag = 1;
    for(int i = 0; i < l.size(); i++)
    {
        if(l[i] < i + 1) 
        {
            flag = 0;
        }
    }

    for(int i = 0; i < r.size(); i++)
    {
        if(r[i] > n - i) 
        {
            flag = 0;
        }
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    int r;
    cin >> r;
    while(r --) solve();

    return 0;
}