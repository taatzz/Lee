/*
 * @lc app=leetcode.cn id=2502 lang=cpp
 *
 * [2502] 设计内存分配器
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Allocator {
public:
    vector<int> tmp; // 保存每块内存的ID
    unordered_map<int, int> h; // 保存当前内存是否被使用
    Allocator(int n) {
        tmp.resize(n);
        for(int i = 0; i < n; i++) h[i] = 0;
    }
    
    int allocate(int size, int mID) {
        for(int i = 0; i < tmp.size(); i ++)
        {
            if(h[i] == 0) // 当前内存为空向后找看是否可以找到符合大小的区间
            {
                int j = i;
                while(h[j] == 0 && j - i < size && j < tmp.size()) j++;
                if(j - i >= size) // 符合之后赋值
                {
                    int t = i;
                    while(i < j) 
                    {
                        h[i] = 1; // 标记已经使用
                        tmp[i] = mID; // 保存ID
                        i++;
                    }
                    return t; // 返回区间左端点
                }
                else i = j; // 不符合继续向后查找
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int res = 0;
        for(int i = 0; i < tmp.size(); i++)
        {
            if(tmp[i] == mID && h[i] == 1) // 找到符合ID和已经使用的内存
            {
                tmp[i] = 0;
                h[i] = 0;
                res++;
            }
        }

        return res;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
// @lc code=end

