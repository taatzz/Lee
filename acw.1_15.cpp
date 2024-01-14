#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;

int n, f[N][3];

int main()
{
    cin >> n;
    vector<int> nums1(n), nums2(n);

    for(int i = n - 1; i >= 0; i--)
    {
        char c;
        cin >> c;
        nums1[i] = c - '0';
    }
    
    for(int i = n - 1; i >= 0; i--)
    {
        char c;
        cin >> c;
        nums2[i] = c - '0';
    }
    
    f[0][0] = abs(nums1[0] - nums2[0]);
    f[0][1] = 10 - nums1[0] + nums2[0];
    f[0][2] = nums1[0] - nums2[0] + 10;
    n = nums1.size();
    for(int i = 1; i < n; i++)
    {
        f[i][0] = min({ f[i - 1][0] + abs(nums1[i] - nums2[i]),
                        f[i - 1][1] + abs(nums1[i] + 1 - nums2[i]),
                        f[i - 1][2] + abs(nums1[i] - 1 - nums2[i])
        });
        
        f[i][1] = min({ f[i - 1][0] + 10 - nums1[i] + nums2[i],
                        f[i - 1][1] + 10 - (nums1[i] + 1) + nums2[i],
                        f[i - 1][2] + 10 - (nums1[i] - 1) + nums2[i]
        });
        
        f[i][2] = min({ f[i - 1][0] + nums1[i] + 10 - nums2[i],
                        f[i - 1][1] + (nums1[i] + 1) + 10 - nums2[i],
                        f[i - 1][2] + (nums1[i] - 1) + 10 - nums2[i]
        });
    }
    
    cout << min({ f[n - 1][0], f[n - 1][1], f[n - 1][2] }) << endl;

    return 0;
}