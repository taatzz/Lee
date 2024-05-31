#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

int res = 0;
std::unordered_map<std::string, int> h;
const int N = 20010;
int son[N][26], cnt[N], idx;

void insert(std::string s)
{
    int p = 0;
    for(int i = 0; i < s.size(); i++)
    {
        int u = s[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }

    h[s] = std::max(h[s], 1);
    cnt[p]++;
}

void query(std::string s)
{
    int p = 0;
    for(int i = 0; i < s.size(); i++)
    {
        int u = s[i]  - 'a';
        if(!son[p][u]) return;
        p = son[p][u];
        
        if(cnt[p] && i != s.size() - 1)
        {
            std::string t = s.substr(0, i + 1);
            h[s] = std::max((int)h[s], (int)h[t] + 1);
        }
    }

    res = std::max(res, (int)h[s]);
}


int main()
{
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];

    std::sort(a.begin(), a.end(), [](const std::string& a, const std::string& b) {return a.size() < b.size();});

    for(int i = 0; i < n; i++)
    {
        insert(a[i]);
        query(a[i]);
    }

    std::cout << res;

    return 0;
}