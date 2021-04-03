class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        int n = T.size();
        vector<int> ans(n);
        stack<int> indices;
        for (int i = 0; i < n; i++)
        {
            while (!indices.empty())
            {
                int pre_index = indices.top();
                if (T[i] <= T[pre_index])
                    break;
                indices.pop();
                ans[pre_index] = i - pre_index;
            }
            indices.push(i);
        }
        return ans;
    }
};