class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if(nums.empty())
            return 0;
        int l = 0;
        for(int r=0; r<nums.size()-1;r++)
        {
            if(nums[r]!=nums[r+1])
            {
                nums[++l]=nums[r+1];
            }
        }
        return l+1;
    }
};