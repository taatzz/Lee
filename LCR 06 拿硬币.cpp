#include <vector>

using namespace std;

class Solution {
public:
    int minCount(vector<int>& coins) {
        
        int res = 0;
        for(int i = 0; i < coins.size(); i++)
        {
            if(coins[i] % 2)
                res += coins[i] / 2 + 1;
            else
                res += coins[i] / 2; 
            // res += coins[i] + 1 / 2
        }
        return res;
    }
};