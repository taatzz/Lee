/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <vector>

using namespace std;

// class Solution {
// public:

//     // 自顶向下建堆
//     void set_down(vector<int>& h, int parent)
//     {
//         int child = 2 * parent + 1;

//         while(child < h.size())
//         {
//             if(child + 1 < h.size() && h[child + 1] > h[child])
//                 child += 1;
//             if(h[child] > h[parent])
//             {
//                 swap(h[parent], h[child]);
//                 parent = child;
//                 child = parent * 2 + 1;
//             }
//             else break;
//         }
//     }

//     void maxheap(vector<int>& heap)
//     {
//         int n = heap.size();
//         for(int i = (n - 2) / 2; i >= 0; i++)
//         {
//             set_down(heap, i);
//         }
//     }

//     int findKthLargest(vector<int>& nums, int k) {
//         // 大顶堆
//         maxheap(nums);

//         // 前k个元素最大的元素只需要出堆k-1次
//         while(--k)
//         {
//             swap(nums[0], nums[nums.size() - 1]);
//             nums.pop_back();
//             set_down(nums, 0);
//         }

//         return nums[0];
//     }
// };
// @lc code=end


class Solution {
public:
    int quick_sort(vector<int>& nums, int left, int right, int k)
    {
        if(left >= right)
            return nums[left];
        
        int x = nums[(left + right) >> 1];
        int l = left - 1, r = right + 1;
        while(l < r)
        {
            do l++; while(nums[l] < x);
            do r--; while(nums[r] > x);
            if(l < r)
                swap(nums[l], nums[r]);
        }
        if(r >= k)
            return quick_sort(nums, left, r, k);
        else
            quick_sort(nums, r + 1, right, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        return quick_sort(nums, 0, n - 1,  n - k);
    }
};