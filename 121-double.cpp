#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <queue>

using namespace std;


// class Solution {
// public:
//     int missingInteger(vector<int>& nums) {
//         unordered_map<int, int> h(nums.begin(), nums.end());

//         int res = 0, t = nums[0];
//         for(int i = 1; i < nums.size(); i++)
//         {
//             if(nums[i] == nums[i - 1] + 1)
//                 t += nums[i];
//             else break;
//         }

//         while(t)
//         {
//             if(h.find(t) == h.end()) return t;
//             t++;
//         }

//         return 0;
//     }
// };



// class Solution {
// public:
//     int minOperations(vector<int>& nums, int k) {
//         int n = nums.size();

//         int t = 0, res = 0;
//         for(int i = 0; i < n; i++) t ^= nums[i];

//         if(t == k) return 0;
//         else
//         {
//             for(int i = 0; i < 31; i++)
//                 if((t & (1 << i)) != (k & (1 << i)))
//                     res++;
//         }

//         return res;
//     }
// };

class Solution {
public:
    vector<int> tmp;

    void find()
    {
        int t = 1, j = 2;
        while(t < 10010)
        {
            t = 5 * j;
            j++;
        }
        t = 1, j = 2;
        while(t < 10010)
        {
            t = 11 * j;
            j++;
        }
        t = 1;
        while(t < 10010)
        {
            t *= 5;
            tmp.push_back(t);
        }
        t = 1;
        while(t < 10010)
        {
            t *= 11;
            tmp.push_back(t);
        }
        t = 1;
        while(t < 10010)
        {
            t *= 55;
            tmp.push_back(t);
        }
        sort(tmp.begin(), tmp.end());
    }

    int minimumOperationsToMakeEqual(int x, int y) {
        int res = 0;
        if(x <= y) return y - x;
        else
        {
            find();

            int t = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
            
            if(tmp[t] != x)
            {
                if(t != 0 && tmp[t] - x < abs(tmp[t - 1] - x))
                    t = tmp[t];
                else if(t != 0 && tmp[t] - x >= abs(tmp[t - 1] - x))
                    t = tmp[t - 1];
                else if(t == 0) 
                {
                    return min(5 - x + 1 + y - 1, x - y);
                }
                res = abs(t - x);
            }
            else if(t == 0 && tmp[t] == x)
                return min(5 - x + 1 + y - 1, x - y);
            else t = tmp[t];
            

            while(t != 1)
            {
                if(t % 11 == 0) 
                {
                    t /= 11;
                    res++;
                }
                else
                    if(t % 5 == 0)
                    {
                        t /= 5;
                        res++;
                    }
            }
            if(y != 1) res += y - 1;
        }

        return min(res, x - y);
    }
};