class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int low = 0, high = numbers.size() - 1;
        int sum = numbers[low] + numbers[high];
        while (low < high)
        {
            if (sum == target)
                return {low + 1, high + 1};
            else if (sum < target)
            {
                low += 1;
                sum = numbers[low] + numbers[high];
            }
            else
            {
                high -= 1;
                sum = numbers[low] + numbers[high];
            }
                }
        return {0, 0};
    }
};