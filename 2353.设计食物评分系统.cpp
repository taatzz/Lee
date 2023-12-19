/*
 * @lc app=leetcode.cn id=2353 lang=cpp
 *
 * [2353] 设计食物评分系统
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class FoodRatings {
public:
    unordered_map<string, pair<int, string>> fs;
    unordered_map<string, set<pair<int, string>> > cs;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i =0; i < n; i++)
        {
            cs[cuisines[i]].emplace(-ratings[i], foods[i]);
            fs[foods[i]] = { ratings[i], cuisines[i] };
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& x = fs[food];
        auto& s = cs[x.second];

        s.erase({-x.first, food});
        s.emplace(-newRating, food);
        x.first = newRating;
    }
    
    string highestRated(string cuisine) {
        return (*cs[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
// @lc code=end

