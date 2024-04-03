#include <iostream>
#include <vector>

using namespace std;

const int N = 200010;
int nums[N], n;

bool check(int x)
{
    vector<int> cur;
    for(int i = 0; i < n; i++) cur.push_back(nums[i]);
    
    for(int i = n - 1; i > 1; i--)
    {
        if(cur[i] < x) return false;
        // 移动的石子是原先的，所以不能超过原来的数量
        int d = min(cur[i] - x, nums[i]) / 3;
        cur[i - 1] += d;
        cur[i - 2] += d * 2;
    }
    
    return cur[1] >= x && cur[0] >= x;
}

int main()
{
    int r;
    cin >> r;
    while(r--)
    {
        cin >> n;
        int r = 1e9;
        for(int i = 0; i < n; i++) 
        {
            cin >> nums[i];
        }

        int l = 0;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(check(mid)) l = mid; 
            else r = mid - 1;
        }

        cout << l << endl;
    }

    return 0;
}