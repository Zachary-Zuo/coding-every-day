class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                else if (j == 0)
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                else
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

/*状态压缩*/
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[j] = grid[i][j];
                else if (i == 0)
                    dp[j] = dp[j - 1] + grid[i][j];
                else if (j == 0)
                    dp[j] = grid[i][j] + dp[j];
                else
                    dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};