class Solution {
public:
    bool helper(int m, int n, vector<vector<int>>& grid,
                int i, int j, int health,
                vector<vector<bool>>& vis, vector<vector<vector<int>>>& dp) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        if (vis[i][j])
            return false;
        health -= grid[i][j];
        if (health <= 0)
            return false;
        if (i == m - 1 && j == n - 1)
            return true;
        if(dp[i][j][health]!=-1) return dp[i][j][health];

        vis[i][j] = true;

        bool ans = helper(m, n, grid, i - 1, j, health, vis,dp) ||
                   helper(m, n, grid, i + 1, j, health, vis,dp) ||
                   helper(m, n, grid, i, j - 1, health, vis,dp) ||
                   helper(m, n, grid, i, j + 1, health, vis,dp);

        vis[i][j] = false; 

        return dp[i][j][health]=ans;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<vector<int>>> dp(
    m,
    vector<vector<int>>(
        n,
        vector<int>(health + 1, -1)
    )
);

        return helper(m, n, grid, 0, 0, health, vis,dp);
    }
};