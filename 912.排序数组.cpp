/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    void set_down(vector<int>& heap, int s, int parent)
    {
        int child = parent * 2 + 1;

        while(child < s)
        {
            if(child + 1 < s && heap[child + 1] > heap[child])
                child += 1;
            if(heap[child] > heap[parent])
            {
                swap(heap[child], heap[parent]);
                parent = child;
                child = parent * 2 + 1;
            }
            else break;
        }
    }

    void maxheap(vector<int>& heap)
    {
        for(int i = (heap.size() - 2) / 2; i >= 0; i--)
        {
            set_down(heap, heap.size(), i);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        maxheap(nums);

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            swap(nums[0], nums[i]);
            set_down(nums, i, 0);
        }

        return nums;
    }
};
// @lc code=end

