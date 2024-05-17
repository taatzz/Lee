#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int m = s.size();
    s += s;
    int n = s.size();
    int i = 0, res = 0;
    while(i < n)
    {
        int start = i;
        i++;
        while(i < n && s[i] != s[i - 1]) i++;
        res = max(res, i - start);
    }
    
    if(res % m == 0) cout << m;
    else cout << res % m;
    
    return 0;
}
