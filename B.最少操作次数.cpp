#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve()
{
    int n;
    string a;
    cin >> n >> a;
    
    vector<int> s(n + 1);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + (a[i - 1] - '0');
    if(s[n] == n || s[n] == 0) 
    {
        cout << 0;
        return;
    }

    if(s[n] == n - s[n])
    {
        for(int i = n - 1; i > 1; i--)
        {
            if(s[i] != i - s[i]) 
            {
                cout << 2;
                return;
            }
        }
        cout << -1;
    }
    else cout << 1;
}

int main()
{
    int r = 1;
    // cin >> r;
    while(r --) solve();


    return 0;
}