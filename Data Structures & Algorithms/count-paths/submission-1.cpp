#include<cstring>
class Solution {
public:
    int dp[101][101];
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid) {
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        int down = solve(i, j+1, m, n, grid);

        int right = solve(i+1, j, m, n, grid);

        return dp[i][j] = down + right;
    }

    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> vec(m, vector<int>(n, 0));
        return solve(0, 0, m, n, vec);
    }
};