#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    static const int N = 1e9;
    int maxPointsInsideSquare(vector<vector<int>>& nums, string s) {
        int n = s.size();

        map<int, map<pair<int, int>, char>> h;
        for(int i = 0; i < n; i++)
        {
            int a = nums[i][0], b = nums[i][1];
            h[max(abs(a), abs(b))][{a, b}] = s[i];
        }

        int res = 0, k = 1, flag = 0;
        vector<int> st(26);
        for(auto& e : h)
        {
            int cnt = 0;
            for(auto& [k, t] : e.second)
            {
                int x = t - 'a';
                if(!st[x])
                {
                    cnt++;
                    st[x] = 1;
                }
                else flag = 1;
            }
            if(flag) break;
            else res += cnt;
        }

        return res;
    }
};