#include <iostream>

using namespace std;

int n, m, a;

int main()
{
    cin >> m >> n >> a;

    int l, w;

    l = (m + a - 1) / a;
    w = (n + a - 1) / a;

    // if(m % a) l = m / a + 1;
    // else l = m / a;

    // if(n % a) w = n / a + 1;
    // else w = n / a;

    long long res = (long long)l * w;

    cout << res << endl;

    return 0;
}