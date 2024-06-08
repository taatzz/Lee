#include <iostream>
#include <functional>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n;
    cin >> n;

    int mod = 1e9 + 7;
    long long x = n / 2, dif = n - x - 1;
    
//     for(int i = 2; i <= 4; i++)
//     {
//         cout << gcd(i * (i - 1) / 2, i * (i + 1) / 2) << endl;
//     }
    long long res = (x + x * (x - 1) / 2 + dif * 3 + dif * (dif - 1)) % mod;
    
    cout << res;

    return 0;
}