/*
 * @lc app=leetcode.cn id=2250 lang=cpp
 *
 * [2250] 统计包含每个点的矩形数目
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> tmp;
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] >= b[0];
    }
   
    int find(int x)
    {
        int l = 0, r = tmp.size() - 1;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(tmp[mid] >= x) r = mid;
            else l = mid + 1;
        }

        return l + 1;
    }

    int lowbit(int x)
    {
        return x & -x;
    }

    void update(vector<int>& tr, int x, int c)
    {
        for(int i = x; i < tr.size(); i += lowbit(i)) tr[i] += c;
    }

    int query(vector<int>& tr, int x)
    {
        int res = 0;
        for(int i = x; i; i -= lowbit(i)) res += tr[i];

        return res;
    }

    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        sort(rectangles.begin(), rectangles.end(), cmp);
        vector<pair<pair<int, int>, int>> x;
        for(int i = 0; i < points.size(); i++)
        {
            x.push_back({{points[i][0], points[i][1]}, i});
        }

        sort(x.begin(), x.end());

        for(auto& e : rectangles) tmp.push_back(e[1]);
        for(auto& e : points) tmp.push_back(e[1]);
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

        int m = tmp.size();
        vector<int> tr(m + 1);
        vector<int> res(points.size());
        
        int i = 0;
        for(int j = x.size() - 1; j >= 0; j--)
        {
            int t = x[j].first.first;
            while(i < rectangles.size() && rectangles[i][0] >= t)
            {
                update(tr, find(rectangles[i][1]), 1);
                i++;
            }
            int idx = find(x[j].first.second);
            res[x[j].second] = query(tr, m) - query(tr, idx - 1);
        }

        return res;
    }
};
// @lc code=end

