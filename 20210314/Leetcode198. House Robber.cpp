class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int pre1 = 0, pre2 = 0, cur = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            cur = max(pre1 + nums[i], pre2);
            pre1 = pre2;
            pre2 = cur;
        }
        return cur;
    }
};