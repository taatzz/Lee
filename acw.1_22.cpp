#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
int mod = 1e9 + 7;
using i128 = __int128;
int sum(int n) {
    return i128(n) * (n + 1) * (2 * n + 1) / 6 % mod;
}

int main()
{
    int n;
    cin >> n;
    
    
    LL ans = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        int s = sum(r) - sum(l - 1);
        ans += 1LL * s * (n / l) % mod;
        ans %= mod;
    }
    if (ans < 0) {
        ans += mod;
    }

    cout << ans;

    return 0;
}