class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> nums(k, 0);
        int count = 0;
        backtrack(ans, count, nums, 1, n, k);
        return ans;
    }

    void backtrack(vector<vector<int>> &ans, int &count, vector<int> &nums, int pos, int n, int k)
    {
        if (count == k)
        {
            ans.push_back(nums);
            return;
        }
        for (int i = pos; i <= n; i++)
        {
            nums[count++] = i;
            backtrack(ans, count, nums, i + 1, n, k);
            --count;
        }
    }
};