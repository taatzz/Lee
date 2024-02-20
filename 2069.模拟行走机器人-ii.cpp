/*
 * @lc app=leetcode.cn id=2069 lang=cpp
 *
 * [2069] 模拟行走机器人 II
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Robot {
public:
    pair<int, int> dx[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
    int w, h, k = 0;
    int x = 0, y = 0;
    bool flag = false;
    int loc = 0;

    Robot(int width, int height) {
        w = width - 1, h = height - 1;
    }
    
    void step(int num) {
        flag = true;
        loc += num;
        loc %= (w + h) * 2;
    }
    
    vector<int> getPos() {
        move();

        return {x, y};
    }

    void move()
    {
        int num = loc;
        while(true)
        {
            if(num == 0) break;
            int a = x + dx[k].first, b = y + dx[k].second;
            if(a >= 0 && a <= w && b >= 0 && b <= h)
            {
                x = a, y = b;
                num--;
            }
            else
            {
                k = (k + 1) % 4;
            }
        }
        loc = 0;
    }
    
    string getDir() {
        move();
        // 机器人在（0，0）没有移动时方向是向东移动过就是南
        if(x == 0 && y == 0) return flag ? "South" : "East";
        if(k == 0) return "East";
        else if(k == 1) return "North";
        else if(k == 2) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
// @lc code=end

