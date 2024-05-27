#include <vector>
#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int i = 0;
    long long res = 0;
    while(i < n)
    {
        int start = i, c = a[start] < 0 ? 0 : 1;
        i++;
        int mx = a[start];
        while(i < n)
        {
            if(c == 0)
            {
                if(a[i] < 0) mx = max(mx, a[i]), i++;
                else break;
            }
            else 
            {
                if(a[i] > 0) mx = max(mx, a[i]), i++;
                else break;
            }
        }

        res += mx;
    }

    cout << res << endl;
}

int main()
{
    int r;
    cin >> r;
    while(r --) solve();

    return 0;
}