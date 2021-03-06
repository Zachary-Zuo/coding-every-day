class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> counts;
        int max_count = 0;
        for (const int &num : nums)
        {
            max_count = max(max_count, ++counts[num]);
        }
        vector<vector<int>> buckets(max_count + 1);
        for (const auto &num : counts)
        {
            buckets[num.second].push_back(num.first);
        }
        vector<int> ans;
        for (int i = max_count; i >= 0 && ans.size() < k; i--)
        {
            for (const auto &num : buckets[i])
            {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};