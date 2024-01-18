#include <iostream>
#include <vector>

using namespace std;

const int N = 2010;
int a[N][10];

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> a[i][j];

    vector<int> res(n);
    for(int i = 0; i < n; i++)
    {
        int j = 0;
       
        for(; j < n; j++)
        {
            bool flag = true;
            for(int k = 0; k < m; k++)
            {
                if(a[i][k] >= a[j][k]) 
                {
                    flag = false;
                    break;
                }
            }
            if(flag) 
            {
                res[i] = j + 1;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) cout << res[i] << endl;

    return 0;
}