#include <vector>
#include <unordered_set>

using namespace std;

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    static const int N = 110;
    bool st[N];
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> h;
        auto find = [&]()->int
        {
            for(int i = 2; i < N; i++)
            {
                if(!st[i])
                {
                    h.insert(i);
                    for(int j = i + i; j < N; j += i) st[j] = 1;
                }
            }
            return 0;
        }();
        
        int i = 0, j = n - 1;
        while(i < j && !h.count(nums[i])) i++;
        while(j > i && !h.count(nums[j])) j--;

        return j - i;
    }
};