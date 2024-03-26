#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for(int i = 1; i <= n; i++) 
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());
    int m = (n - 1) / 2;
    int l = lower_bound(a.begin(), a.end(), k) - a.begin();
    int r = upper_bound(a.begin(), a.end(), k) - a.begin() - 1;
    
    int res = 0;
    if(l == n || a[l] != k)
    {
        res = 1;
        r = l;
        n++;
    }
    cout << l << " " << m << " " << r << endl;
    if(l > m) res += 2 * l - n + 1;
    else if(r < m) res += n - 2 * r - 2;
    
    cout << res;

    return 0;
}