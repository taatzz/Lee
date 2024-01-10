#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 100010;

int n, a[N], b[N];

// 贪心
// 对于每个超过n/10次的元素我们应该取超出部分修改代价小的
// 证明：反证法 假设选最小的不是最优解，那么我们在之前的某一步还有优化的空间但是我们已经每一步都是最优解了，所以与已知条件冲突，证毕
int main()
{
    unordered_map<int, priority_queue<int, vector<int>, greater<int>> > h;

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        h[a[i]].push(b[i]);
    }

    int k = n / 10;
    long long res = 0;
    for(auto e : h)
    {
        int m = e.second.size();
        while(m > k)
        {
            res += e.second.top();
            e.second.pop();
            m--;
        }
    }

    cout << res << endl;

    return 0;
}