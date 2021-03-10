class Solution
{
    vector<int> direction = {-1, 0, 1, 0, -1};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {

        if (matrix.empty() || matrix[0].empty())
            return {};
        vector<vector<int>> ans;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> reachPacific(m, vector<bool>(n, false));
        vector<vector<bool>> reachAtlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            dfs(matrix, reachPacific, i, 0);
            dfs(matrix, reachAtlantic, i, n - 1);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(matrix, reachPacific, 0, i);
            dfs(matrix, reachAtlantic, m - 1, i);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                if (reachPacific[i][j] && reachAtlantic[i][j])
                    ans.push_back(vector<int>{i, j});
        }
        return ans;
    }

    void dfs(const vector<vector<int>> &matrix, vector<vector<bool>> &reach, int r, int c)
    {
        if (reach[r][c])
            return;
        reach[r][c] = true;
        int x, y;
        for (int i = 0; i < 4; i++)
        {
            x = r + direction[i];
            y = c + direction[i + 1];
            if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[r][c] <= matrix[x][y])
                dfs(matrix, reach, x, y);
        }
    }
};