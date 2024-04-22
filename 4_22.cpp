// #include <iostream>
// #include <queue>
// #include <unordered_map>

// using namespace std;
// typedef long long LL;

// int main()
// {
//     LL n, k, a, b;
//     cin >> n >> k >> a >> b;

//     LL res = 0;
//     while(n)
//     {
//         res += n % k * a;
//         n -= n % k;
//         if((LL) (n -  n / k) * a <= b)
//         {
//             res += (LL)(n - 1) * a;
//             break;
//         }
//         n /= k;
//         res += b;
//     }

//     cout << res;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
const int N = 100010;
vector<pii> edge;
int in[N];
int h[N], e[N], ne[N];
int idx = 0;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool check(int n, int x)
{
    memset(h, -1, sizeof h);
    memset(in, 0, sizeof in);
    idx = 0;
    int mx = 0;
    for(int i = 0; i <= x; i++)
    {
        add(edge[i].first, edge[i].second);
        in[edge[i].second]++;
        mx = max(mx, edge[i].second);
        mx = max(mx, edge[i].first);
    }

    queue<int> q;
    int res = 0;
    for(int i = 1; i <= mx; i++)
    {
        if(!in[i]) 
        {
            q.push(i);
            res++;
        }
    }

    while(q.size())
    {
        if(q.size() > 1) return false; 
        auto t = q.front();
        q.pop();

        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(--in[j] == 0)
            {
                q.push(j);
                res++;
            }
        }
    }

    return res == n;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        edge.emplace_back(a, b);
        in[b]++;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) 
        if(in[i] == 0) cnt++;
    if(cnt > 1)
    {
        cout << -1;
        return 0;
    }

    int l = 0, r = m - 1;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(check(n, mid)) r = mid;
        else l = mid + 1;
    }

    if(check(n, l)) cout << l + 1;
    else cout << -1;

    return 0;
}