#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(m);
    for(int i = 0; i < m; i++)
    {
        nums[i].resize(2);
        cin >> nums[i][0] >> nums[i][1];
    }
    
    int q;
    cin >> q;
    vector<int> query(q);
    for(int i = 0; i < q; i++) cin >> query[i];
    
    auto check = [&](int x)->bool
    {
        vector<int> s(n + 2);
        for(int i = 0; i <= x; i++)
        {
            int l = query[i], r = query[i];
            s[l] += 1;
        }
        
        for(int i = 1; i <= n; i++) 
        {
            s[i] += s[i - 1];
        }
        
        for(int i = 0; i < m; i++)
        {
            int l = nums[i][0], r = nums[i][1];
            int num_one = s[r] - s[l - 1];
            if(num_one > r - l + 1 - num_one)
                return 1;
        }
        
        return 0;
    };
    
    int l = 0, r = q - 1;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    
    if(!check(l)) cout << -1 << endl;
    else cout << l + 1 << endl;
}

int main()
{
    int r;
    cin >> r;
    
    while(r --) solve();
    
    return 0;
}