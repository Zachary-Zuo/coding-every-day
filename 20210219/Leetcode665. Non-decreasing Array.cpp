class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < nums.size() - 1 && nums[left] <= nums[left + 1])
            left++;
        if (left == nums.size() - 1)
            return true;
        while (right > 0 && nums[right - 1] <= nums[right])
            right--;
        if (right - left > 1)
            return false;
        if(left==0||right==nums.size() - 1)
            return true;
        if (nums[left] <= nums[right + 1] || nums[left - 1] <= nums[right])
            return true;
        return false;
    }
};