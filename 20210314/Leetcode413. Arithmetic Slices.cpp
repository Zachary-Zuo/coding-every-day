class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int dp = 0;
        int sum = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                dp++;
                sum += dp;
            }
            else
            {
                dp = 0;
            }
        }
        return sum;
    }
};