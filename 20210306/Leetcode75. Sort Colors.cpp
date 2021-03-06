class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int i0 = 0, i2 = n - 1;
        for (int i = 0; i <= i2; i++)
        {
            while (i <= i2 && nums[i] == 2)
            {
                swap(nums[i], nums[i2]);
                i2--;
            }
            if (nums[i] == 0)
            {
                swap(nums[i], nums[i0]);
                i0++;
            }
        }
    }
};