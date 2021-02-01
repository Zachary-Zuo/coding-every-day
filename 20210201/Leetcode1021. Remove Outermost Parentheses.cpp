class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        string ans = "";
        int l = 1, r = 0;
        for (int i = 1; i < S.size(); i++)
        {
            if (S[i] == '(')
                l += 1;
            else
                r += 1;
            if (l != r)
                ans.push_back(S[i]);
            else
            {
                i++;
                l = 1;
                r = 0;
            }
        }
        return ans;
    }
};