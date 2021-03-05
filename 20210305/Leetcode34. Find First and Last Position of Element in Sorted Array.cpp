class Solution
{
public:
    int lowerBound(vector<int> &nums, int target)
    {
        int l = 0, size = nums.size(), mid = 0;
        while (l < size)
        {
            mid = (l + size) / 2;
            if (nums[mid] >= target)
                size = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    int upperBound(vector<int> &nums, int target)
    {
        int l = 0, size = nums.size(), mid = 0;
        while (l < size)
        {
            mid = (l + size) / 2;
            if (nums[mid] > target)
                size = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return {-1, -1};
        int low = lowerBound(nums, target);
        int up = upperBound(nums, target) - 1;
        if (low == nums.size() || nums[low] != target)
            return {-1, -1};
        return {low, up};
    }
};