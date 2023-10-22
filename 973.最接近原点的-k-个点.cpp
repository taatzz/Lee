/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    bool check(vector<int>& a, vector<int>& b)
    {
        int num1 = a[0] * a[0] + a[1] * a[1];
        int num2 = b[0] * b[0] + b[1] * b[1];

        return num1 < num2 ? 0 : 1;
    }

    void set_down(vector<vector<int> >& heap, int s, int parent)
    {
        int child = parent * 2 + 1;

        while(child < s)
        {
            if(child + 1 < s && check(heap[child], heap[child + 1]))
                child += 1;
            if(check(heap[parent], heap[child]))
            {
                swap(heap[child], heap[parent]);
                parent = child;
                child = parent * 2 + 1;
            }
            else break;
        }
    }

    void minheap(vector<vector<int> >& heap)
    {
        for(int i = (heap.size() - 2) / 2; i >= 0; i--)
        {
            set_down(heap, heap.size(), i);
        }
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        minheap(points);
        vector<vector<int> > res;
        int end = points.size() - 1;

        while(k--)
        {
            res.push_back(points[0]);
            swap(points[0], points[end]);
            set_down(points, end, 0);
            end--;
        }

        return res;
    }
};
// @lc code=end

