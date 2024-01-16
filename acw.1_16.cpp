#include <iostream>
#include <vector>

using namespace std;

// 二维前缀和 和 差分
void insert(vector<vector<int>>& s, int x1, int y1, int x2, int y2)
{
    s[x1][y1] += 1;
    s[x2 + 1][y1] -= 1;
    s[x1][y2 + 1] -= 1;
    s[x2 + 1][y2 + 1] += 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n + 10, vector<int>(n + 10, 0));

    while(m --)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        insert(s, x1, y1, x2, y2);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            if(s[i][j] % 2)cout << 1;
            else cout << 0;
        cout << endl;
    }

    return 0;
}