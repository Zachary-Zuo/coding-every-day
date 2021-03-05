class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (target == nums[mid])
            {
                return true;
            }
            else if (nums[left] == nums[mid])
                left++;
            else if (nums[mid] <= nums[right])
            {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
            {
                if (target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return false;
    }
};