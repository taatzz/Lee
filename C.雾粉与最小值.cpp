#include <vector>
#include <stack>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    stack<int> stk;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> left(n, -1), right(n, n);
    for(int i = 0; i < n; i+=1)
    {
        while(stk.size() && a[stk.top()] > a[i])
        {
            right[stk.top()] = i;
            stk.pop();
        }
        if(stk.size()) left[i] = stk.top();
        stk.push(i);
    }
    map<int, int> h;
    for(int i = 0; i < n; i++) h[a[i]] = max(h[a[i]], right[i] - left[i] - 1);
    map<int, int> h_idx; // 将每一个元素重新映射下标
    int j = 0;
    for(auto it = h.rbegin(); it != h.rend(); it++)
    {
        h_idx[it->first] = j++;
    }

    // 树状数组
    vector<int> tr(j + 1);
    auto insert = [&](int x, int c)
    {
        for(; x < tr.size(); x += x & -x) 
            tr[x] = max(tr[x], c);
    };
    auto query = [&](int x)
    {
        int res = 0;
        for(; x; x -= x & -x)
            res = max(res, tr[x]);

        return res;
    };  
    for(auto e : h_idx)
    {
        insert(e.second + 1, h[e.first]);
    }

    int q;
    cin >> q;
    while(q --)
    {
        int x, l, r;
        cin >> x >> l >> r;
        auto it = h.lower_bound(x);
        if(it == h.end()) cout << "No" << endl;
        else
        {
            int idx = h_idx[it->first] + 1;
            int res = query(idx);
            
            if(res < l) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }

    return 0;
}