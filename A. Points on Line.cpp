#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    long long res = 0;
    for(int i = 0, k = 0; k < n; k++)
    {
        while(nums[k] - nums[i] > d) i++;
        res += (long long)(k - i) * (k - i - 1) / 2;
    }

    cout << res << endl;

    return 0;
}