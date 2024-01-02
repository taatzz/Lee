#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size(), res = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == s[i + 1] || s[i + 1] == '?' || s[i - 1] == '?')
        {
            res ++;
            i++;
        }
    }

    cout << res << endl;

    return 0;
}