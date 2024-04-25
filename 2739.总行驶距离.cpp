class Solution {
public:
    int distanceTraveled(int a, int b) {
        int res = 0;
        while(a >= 5)
        {
            res += 50;
            if(b) a++, b--;
            a -= 5;
        }

        if(a) res += a * 10;

        return res;
    }
};