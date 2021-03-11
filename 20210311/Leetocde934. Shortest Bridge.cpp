class Solution
{
    vector<int> direction = {-1, 0, 1, 0, -1};

public:
    int shortestBridge(vector<vector<int>> &A)
    {
        int m = A.size();
        int n = A[0].size();
        queue<pair<int, int>> points;

        bool find = false;
        for (int i = 0; i < m; i++)
        {
            if (find)
                break;
            for (int j = 0; j < n; j++)
            {
                if (A[i][j] == 1)
                {
                    dfs(points, A, m, n, i, j);
                    find = true;
                    break;
                }
            }
        }

        int x, y;
        int level = 0;
        while (!points.empty())
        {
            ++level;
            int n_points = points.size();
            while (n_points--)
            {
                auto [r, c] = points.front();
                points.pop();
                for (int k = 0; k < 4; k++)
                {
                    x = r + direction[k];
                    y = c + direction[k + 1];
                    if (x >= 0 && y >= 0 && x < m && y < n)
                    {
                        if (A[x][y] == 2)
                            continue;
                        if (A[x][y] == 1)
                            return level;
                        points.push({x, y});
                        A[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }

    void dfs(queue<pair<int, int>> &points, vector<vector<int>> &A, int m, int n, int i, int j)
    {
        if (i < 0 || j < 0 || i == m || j == n || A[i][j] == 2)
            return;
        if (A[i][j] == 0)
        {
            points.push({i.j});
            return;
        }
        A[i][j] = 2;
        int x, y;
        for (int k = 0; k < 4; k++)
        {
            x = i + direction[k];
            y = j + direction[k + 1];
            dfs(points, A, m, n, x, y);
        }
    }
};