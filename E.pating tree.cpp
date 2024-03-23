#include <iostream>
#include <cstring>

using namespace std;

const int N = 200010;
int h[N], e[N * 2], ne[N * 2], idx;
bool st[N];
long long res[N], sz[N];
int n;
long long mx = 0;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u)
{
    st[u] = 1;
    long long cnt = 1;
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            cnt += dfs(j);
        }
    }   
    sz[u] = cnt;
    
    return cnt;
}

void reroot(int u)
{
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!res[j])
        {
            res[j] = res[u] + n - (long long)2 * sz[j];
            mx = max(mx, res[j]);
            reroot(j);
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1);
    for(int i = 1; i <= n; i++) res[1] += sz[i];
    mx = res[1];
    reroot(1);

    cout << mx;

    return 0;
}