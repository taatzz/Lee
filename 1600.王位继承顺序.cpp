/*
 * @lc app=leetcode.cn id=1600 lang=cpp
 *
 * [1600] 王位继承顺序
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class ThroneInheritance {
public:
    unordered_map<string, vector<string>> son;
    unordered_set<string> die;
    string s;
    vector<string> res;

    ThroneInheritance(string kingName) {
        son.insert({kingName, {}});
        s = kingName;
    }
    
    void birth(string parentName, string childName) {
        son[parentName].push_back(childName);
    }
    
    void death(string name) {
        die.insert(name);
    }

    void dfs(string name)
    {
        if(son.find(name) == son.end()) 
        {
            if(die.find(name) == die.end())
                res.push_back(name);
            return;
        }

        if(die.find(name) == die.end())
            res.push_back(name);
        for(auto& e : son[name])
        {
            dfs(e);
        }
    }
    
    vector<string> getInheritanceOrder() {
        res.clear();
        dfs(s);

        return res;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
// @lc code=end

