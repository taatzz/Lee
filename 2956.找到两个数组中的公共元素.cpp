#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> cnt1(101), cnt2(101);
        for(int e : nums1) cnt1[e]++;
        for(int e : nums2) cnt2[e]++;

        vector<int> res(2);
        for(int i = 0; i < nums1.size(); i++)
        {
            if(cnt2[nums1[i]]) 
            {
                res[0]++;
            }
        }
        for(int i = 0; i < nums2.size(); i++)
        {
            if(cnt1[nums2[i]]) 
            {
                res[1]++;
            }
        }

        return res;
    }
};