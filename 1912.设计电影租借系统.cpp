/*
 * @lc app=leetcode.cn id=1912 lang=cpp
 *
 * [1912] 设计电影租借系统
 */

// @lc code=start
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

class MovieRentingSystem {
public:
    typedef pair<int, int> pii;
    static const int N = 100010;
    set<pii> move_id[N];
    set<pair<int, pii>> rt;
    map<pii, int> prc;

    MovieRentingSystem(int n, vector<vector<int>>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            int a = nums[i][0], b = nums[i][1], c = nums[i][2];
            move_id[b].insert({c, a});
            prc[{a, b}] = c;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        auto it = move_id[movie].begin();
        for(int i = 0; i < 5 && it != move_id[movie].end(); i++, it++)
        {
            res.push_back((*it).second);
        }

        return res;
    }
    
    void rent(int shop, int movie) {
        int price = prc[{shop, movie}];
        move_id[movie].erase({price, shop});
        rt.insert({price, {shop, movie}});
    }
    
    void drop(int shop, int movie) {
        int price = prc[{shop, movie}];
        move_id[movie].insert({price, shop});
        rt.erase({price, {shop, movie}});
    }
    
    vector<vector<int>> report() {
        auto it = rt.begin();
        vector<vector<int>> res;
        for(int i = 0; i < 5 and it != rt.end(); i++, it++)
        {
            res.push_back({it->second.first, it->second.second});
        }

        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
// @lc code=end

