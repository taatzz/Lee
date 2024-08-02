#include <vector>

using namespace std;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> row(m), col(n);
        for(int i = 0; i < m; i++)
        {
            int cnt = 0;
            for(int j = 0; j < n; j++) cnt += grid[i][j];
            row[i] = cnt;
        }
        for(int j = 0; j < n; j++)
        {
            int cnt = 0;
            for(int i = 0; i < m; i++) cnt += grid[i][j];
            col[j] = cnt;
        }

        long long res = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                if(grid[i][j]) res += (row[i] - 1) * (col[j] - 1);
        }

        return res;
    }
};