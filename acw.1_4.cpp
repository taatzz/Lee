#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int cnt = 0, res = 0;
    while(n)
    {
        cnt++;
        if(n % 3 == 1 && !res) res = cnt;
        n -= (n + 3 - 1) /3;
    }

    cout << cnt << " " << res;

    return 0;
}