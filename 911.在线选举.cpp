/*
 * @lc app=leetcode.cn id=911 lang=cpp
 *
 * [911] 在线选举
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


class TopVotedCandidate {
public:
    vector<int> person, time;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> h;
        int mx = 0, p = 0;
        time = times;
        // 在每一个投票时刻时当前的候选人存在preson 中
        for(int i = 0; i < times.size(); i++)
        {
            if(++h[persons[i]] >= mx)
            {
                mx = h[persons[i]];
                p = persons[i];
            }
            person.push_back(p);
        }
    }
    
    int q(int t) {
        // 找到离查询时刻最近的投票时刻返回候选人
        int idx = upper_bound(time.begin(), time.end(), t) - time.begin() - 1;
        return person[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end

