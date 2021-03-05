class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int ans = 0;
        for (auto &e : nums)
            ans ^= e;
        return ans;
    }
};