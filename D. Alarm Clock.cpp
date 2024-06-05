#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int res = 0, cnt = 0;
    for(int i = 0, j = 0; i < n; i++)
    {
        cnt++;
        while(a[i] - a[j] >= m) 
        {
            if(a[j] > 0) cnt--;
            j++;
        }
        if(cnt == k)
        {
            a[i] = 0;
            cnt--;
            res++;
        }
    }

    cout << res;

    return 0;
}