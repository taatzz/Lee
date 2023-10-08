#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] != 5)
            return false;
        
        int five_num = 0, ten_num = 0;
        for(int i = 0; i < bills.size(); i++)
        {
            if(bills[i] == 5)
                five_num++;
            else if(bills[i] == 10)
            {
                five_num--;
                ten_num++;
            }
            else
            {
                if(ten_num < 0 && five_num < 3)
                {
                    return false;
                }
                else
                {
                    ten_num--;
                    five_num--;
                }
            }
        }
        return true;
    }
};