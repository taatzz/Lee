#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while(n --)
    {
        string s, t;
        cin >> t >> s;
        int m = s.size();

        // 首尾不能改变
        if(s[0] != t[0] || s[m - 1] != t[m - 1]) 
        {
            cout << -1 << endl;
            continue;
        }

        bool flag = true;
        int res = 0;
        for(int i = 1; i < m - 1; i++)
        {
            if(s[i] != t[i])
            {
                if(t[i] == t[i - 1] && t[i] == t[i + 1]  && s[i] != s[i - 1] && s[i] != s[i + 1])
                {
                    res++;
                    s[i] = t[i];
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }

        if(flag) cout << res << endl;
        else cout << -1 << endl;
    }

    return 0;
}