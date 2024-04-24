/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 */

// @lc code=start
#include <string>
#include <cstring>
#include <unordered_map>

using namespace std;

class MapSum {
public:
    static const int N = 10010;
    int son[N][26], idx = 0, cnt[N][26];
    unordered_map<string, int> h;

    MapSum() {
        memset(son, 0, sizeof son);
    }
    
    void insert(string key, int val) {
        int p = 0;
        bool flag = false;
        if(h.count(key)) flag = true;

        for(int i = 0; i < key.size(); i++)
        {
            int u = key[i] - 'a';
            if(flag)
            {
                cnt[p][u] -= h[key];
            }
            cnt[p][u] += val;
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        h[key] = val;
    }
    
    int sum(string s) {
        int res = 0;
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) return 0;
            res = cnt[p][u];
            p = son[p][u];
        }

        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

