
class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0' || visited[i][j]) return;
        visited[i][j] = true;

        dfs(i+1, j, n, m, grid, visited);
        dfs(i-1, j, n, m, grid, visited);
        dfs(i, j+1, n, m, grid, visited);
        dfs(i, j-1, n, m, grid, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        if(m == 0) return 0;

        int cnt = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j] != '0') {
                    dfs(i, j, n, m, grid, visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
