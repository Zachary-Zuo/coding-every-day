class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty())
            return false;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool find = false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                backtrack(i, j, board, word, find, visited, 0);
                if (find)
                    return find;
            }
        }
        return find;
    }

    void backtrack(int i, int j, vector<vector<char>> &board, string &word, bool &find, vector<vector<bool>> &visited, int pos)
    {
        static vector<int> direction = {-1, 0, 1, 0, -1};
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        if (visited[i][j] || find || board[i][j] != word[pos])
            return;
        if (pos == word.size() - 1)
        {
            find = true;
            return;
        }
        visited[i][j] = true;
        int x, y;
        for (int k = 0; k < 4; k++)
        {
            x = i + direction[k];
            y = j + direction[k + 1];
            backtrack(x, y, board, word, find, visited, pos + 1);
        }
        visited[i][j] = false;
    }
};