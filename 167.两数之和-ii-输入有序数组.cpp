/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
#include <vector>

using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int n = numbers.size(), left = 0, right = n - 1;

//         vector<int> res;

//         while(left < right)
//         {
//             int sum = numbers[left] + numbers[right];
//             if(sum < target)
//             {
//                 left++;
//                 while(left < right && numbers[left] == numbers[left - 1])
//                     left++;
//             }
//             else if(sum > target)
//             {
//                 right--;
//                 while(left < right && numbers[right] == numbers[right + 1])
//                     right--;
//             }
//             else
//             {
//                 res.push_back(left + 1);
//                 res.push_back(right + 1);
//                 return res;
//             }
//         }

//         return res;
//     }
// };
// @lc code=end

class Solution {
public:
    // 二分 [闭区间] 找符合差值的数组元素
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int low = i + 1, high = numbers.size() - 1;
            while (low <= high) {
                int mid = (high - low) / 2 + low;
                if (numbers[mid] == target - numbers[i]) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] > target - numbers[i]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return {-1, -1};
    }
};

