#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int res = 1e9;
    for(int i = 1; i < n - 1; i++) res = min(res, a[i]);

    cout << res;

    return 0;
}