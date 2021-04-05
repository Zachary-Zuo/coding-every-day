class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int different = 0, same = 1, count = 0;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
                same++;
            else
            {
                different = same;
                same = 1;
            }
            if (different >= same)
                ++count;
        }
        return count;
    }
};