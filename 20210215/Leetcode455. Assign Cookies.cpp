class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int childCount = 0, cookie = 0;
        while (childCount < g.size() && cookie < s.size())
        {
            if (g[childCount] <= s[cookie])
                ++childCount;
            cookie++;
        }
        return childCount;
    }
};