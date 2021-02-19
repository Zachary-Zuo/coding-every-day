class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        int len = S.size();

        int last[26] = {0};
        for (int i = 0; i < len; i++)
        {
            last[S[i] - 'a'] = i;
        }

        vector<int> result;
        int start = 0;
        int end = 0;
        for (int i = 0; i < len; i++)
        {
            end = max(end, last[S[i] - 'a']);
            if (i == end)
            {
                result.push_back(end - start + 1);
                start = end + 1;
                end++;
            }
        }
        return result;
    }
};