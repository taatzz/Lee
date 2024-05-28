#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();
    long long d = m - n + 1, res = 0, cnt = 0;

    for(int i = 0, j = 0; i < m; i++)
    {
        cnt += b[i] == '1';

        if(i >= d - 1)
        {
            if(a[j] == '1') res += d - cnt;
            else res += cnt;

            int l = i - d + 1;
            cnt -= b[l] == '1';
        }   
    }
    cout << res;

    return 0;
}