class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        if (n == 0)
            return ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> column(n, false);
        vector<bool> ldiag(2 * n - 1, false);
        vector<bool> rdiag(2 * n - 1, false);
        backtrack(ans, board, column, ldiag, rdiag, 0, n);
        return ans;
    }

    void backtrack(vector<vector<string>> &ans, vector<string> &board, vector<bool> &column, vector<bool> &ldiag, vector<bool> &rdiag, int row, int n)
    {
        if (row == n)
        {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (column[i] || ldiag[n - row + i - 1] || rdiag[row + i + 1])
                continue;
            board[row][i] = 'Q';
            column[i] = ldiag[n - row + i - 1] = rdiag[row + i + 1] = true;
            backtrack(ans, board, column, ldiag, rdiag, row + 1, n);
            board[row][i] = '.';
            column[i] = ldiag[n - row + i - 1] = rdiag[row + i + 1] = false;
        }
    }
};