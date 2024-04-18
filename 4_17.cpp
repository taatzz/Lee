#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
vector<int> t;
const int N = 800010;
vector<pii> insert;
int s[N];

int find(int x)
{
    int l = 0, r = t.size();
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(t[mid] >= x) r = mid;
        else l = mid + 1;
    }

    return l + 1;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)   
    {
        int a, b;
        cin >> a >> b;
        insert.push_back({a, b});
        t.push_back(a);
        t.push_back(b);
        t.push_back(a - 1);
        t.push_back(b + 1);
    }

    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());

    for(auto& e : insert)
    {
        int l = find(e.first), r = find(e.second);
        s[l] += 1, s[r + 1] -= 1;
    }
    
    for(int i = 1; i < t.size(); i++) s[i] += s[i - 1];
    
    vector<int> pre(t.size() + 1);
    for(int i = 1; i < t.size(); i++) 
        pre[i] = pre[i - 1] + (s[i] == 1);

    int res = -1;
    for(int k = 0; k < insert.size(); k++)
    {
        int l = find(insert[k].first), r = find(insert[k].second);
        if(pre[r] - pre[l - 1] == 0) 
        {
            res = k + 1;
            break;
        }
    }
    cout << res;
    

    return 0;
}