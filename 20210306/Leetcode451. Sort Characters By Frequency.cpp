class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> counts;
        int max_count = 0;
        for (const char &c : s)
        {
            max_count = max(max_count, ++counts[c]);
        }
        vector<vector<char>> buckets(max_count + 1);
        for (const auto &c : counts)
        {
            buckets[c.second].push_back(c.first);
        }
        vector<char> ans;
        for (int i = max_count; i >= 0; i--)
        {
            for (const auto &c : buckets[i])
            {
                for (int j = 0; j < counts[c]; j++)
                    ans.push_back(c);
            }
        }
        string str;
        str.assign(ans.begin(), ans.end());
        return str;
    }
};