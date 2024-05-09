#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, int> pii;
const int N = 200010;
int n, m, h[N], e[N * 4], ne[N * 4], idx;
LL w[N * 4], dist[N];
bool st[N];

void add(int a, int b, LL c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void Dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dist[0] = 0;
    q.push({0, 0});

    while(q.size())
    {
        auto t = q.top();
        q.pop();
        LL ver = t.second, d = t.first;
        if(st[ver]) continue;
        st[ver] = 1;

        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > d + w[i])
            {
                dist[j] = d + w[i];
                q.push({dist[j], j});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        LL c;
        cin >> a >> b >> c;
        add(a, b, 2 * c);
        add(b, a, 2 * c);
    }
    for(int i = 1; i <= n; i++) 
    {
        LL a;
        cin >> a;
        add(0, i, a);
        add(i, 0, a);
        dist[i] = 1e18;
    }

    Dijkstra();

    for(int i = 1; i <= n; i++)
        cout << dist[i] << " ";
    
    return 0;
}