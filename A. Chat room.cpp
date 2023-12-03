#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string tmp = "hello";

    int i = 0, j = 0;
    for(; i < s.size(); i++)
    {
        if(s[i] == tmp[j]) j++;
        if(j == tmp.size()) break;
    }

    if(j == tmp.size()) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}