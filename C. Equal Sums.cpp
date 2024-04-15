#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

int main()
{
    int k;
    cin >> k;

    int tmp = 1;
    unordered_map<int, pair<int, int>> h;
    bool flag = 0;
    while(tmp <= k)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int sum = accumulate(a.begin(), a.end(), 0);
        
        for(int i = 0; i < n; i++)
        {
            int x = sum - a[i];
            if(h.find(x) != h.end())
            {
                auto t = h[x];
                if(t.first != tmp) 
                {
                    cout << "YES" << endl;
                    cout << tmp << " " << i + 1 << endl;
                    cout << t.first << " " << t.second << endl;
                    flag = 1;
                    break;
                }
            }
            h[x] = {tmp, i + 1};
        }

        if(flag) break;
        tmp++;
    }
    if(!flag) cout << "NO" << endl;
    
    return 0;
}