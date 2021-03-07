class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int direction[5] = {-1, 0, 1, 0, -1};
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        int localArea = 0, maxArea = 0, x, y;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    localArea = 1;
                    grid[i][j] = 0;
                    stack<pair<int, int>> s;
                    s.push({i, j});
                    while (!s.empty())
                    {
                        auto [l, r] = s.top();
                        s.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            x = l + direction[k];
                            y = r + direction[k + 1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
                            {
                                grid[x][y] = 0;
                                localArea++;
                                s.push({x, y});
                            }
                        }
                    }
                    maxArea = max(maxArea, localArea);
                }
            }
        }
        return maxArea;
    }
};