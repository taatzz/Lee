#include <vector>

using namespace std;

class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        vector<int> pos;

        int c = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0) continue;
            c = max(c, 1);
            pos.push_back(i);
            if(i > 0 && nums[i - 1] == 1)
            {
                if(i > 1 && nums[i - 2] == 1)
                    c = max(c, 3);
                else c = max(c, 2);
            }
        }

        c = min(k, c);
        if(maxChanges >= k - c)
        {
            return max(c - 1, 0) + (k - c) * 2;
        }

        int n = pos.size();
        vector<long long> s(n + 1);
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + pos[i - 1];

        int size = k - maxChanges;
        long long res = 1e10 + 10;
        for(int right = size; right <= n; right++)
        {
            int left = right - size;
            int i = left + size / 2;
            long long idx = pos[i];
            long long s1 = idx * (i - left) - (s[i] - s[left]);
            long long s2 = s[right] - s[i] - idx * (right - i);
            res = min(res, s1 + s2);
        }

        return res + maxChanges * 2;
    }
};