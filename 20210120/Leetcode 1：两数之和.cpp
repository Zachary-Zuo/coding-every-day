class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> unordermp;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = unordermp.find(target - nums[i]);
            if (it != unordermp.end())
            {
                return {it->second, i};
            }
            unordermp[nums[i]] = i;
        }
        return {};
    }
};