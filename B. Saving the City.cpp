#include <iostream>
#include <string>

using namespace std;

int main()
{
    int r;
    cin >> r;

    while(r --)
    {
        int a, b;
        string s;
        cin >> a >> b >> s;

        int i = 0, n = s.size();
        int prev = -999, res = 0;
        while(i < n)
        {
            if(s[i] == '1')
            {
                res += min(b * (i - prev - 1), a);
                prev = i;
            }
            i++;
        }
        cout << res << endl;
    }

    return 0;
}