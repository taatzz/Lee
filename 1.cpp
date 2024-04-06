#include <iostream>
#include <vector>

using namespace std;

static const int N = 100010;
int nums[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<int> res(n + 1), cnt(n + 1);

    int k = 1;
    for(int i = 0; i < n; i++)
    {
        cnt[nums[i]] = 1;
        if(nums[i] == k)
        {
            while(k <= n && cnt[k] != 0)
            {
                res[k] = i + 1;
                k++;
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << res[i] << " ";

    return 0;
}