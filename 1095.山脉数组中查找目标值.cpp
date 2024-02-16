/*
 * @lc app=leetcode.cn id=1095 lang=cpp
 *
 * [1095] 山脉数组中查找目标值
 */

// @lc code=start

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
  public:
    int get(int index);
    int length();
};


class Solution {
public:
    int find(int l, int r, int x, MountainArray &nums, bool flag)
    {
        if(flag)
        {
            while(l < r)
            {
                int mid = (l + r) >> 1;
                if(nums.get(mid) >= x) r = mid;
                else l = mid + 1;
            }
        }
        else
        {
            while(l < r)
            {
                int mid = (l + r) >> 1;
                if(nums.get(mid) <= x) r = mid;
                else l = mid + 1;
            }
        }

        return l;
    }

    int findInMountainArray(int target, MountainArray &nums) {
        int n = nums.length();

        int l = 0, r = n - 1;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(nums.get(mid) > nums.get(mid + 1)) r = mid;
            else l = mid + 1;
        }
        if(nums.get(l) < target) return -1;
        
        int t = find(0, l, target, nums, 1);
        if(nums.get(t) == target) return t;
        int t1 = find(l, n - 1, target, nums, 0);
        if(nums.get(t1) == target) return t1;
        

        return -1;
    }
};
// @lc code=end

