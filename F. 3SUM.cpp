#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if(n < 3) 
    {
        cout << "NO" << endl;
        return;
    }
    vector<int> t(10);
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        t[a % 10]++;
    }
    
    for(int i = 0; i < t.size(); i++)
    {
        if(t[i] == 0) continue;
        t[i]--;
        for(int j = 0; j < t.size(); j++)
        {
            if(t[j] == 0) continue;
            t[j]--;
            for(int k = 0; k < t.size(); k++)
            {
                if(t[k] == 0) continue;
                if((i + j + k) % 10 == 3) 
                {
                    cout << "YES" << endl;
                    return;
                }
            }
            t[j]++;
        }
        t[i]++;
    }

    cout << "NO" << endl;
}

int main()
{
    int r;
    cin >> r;

    while(r--) solve();

    return 0;
}