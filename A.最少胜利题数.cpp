#include <iostream>
#include <string>

using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;

    if(a.size() > b.size()) swap(a, b);
    if(b.size() == 6) 
    {
        cout << -1;
        return;
    }

    cout << b.size() - a.size() + 1;
}

int main()
{
    int r = 1;
    // cin >> r;
    while(r --) solve();


    return 0;
}