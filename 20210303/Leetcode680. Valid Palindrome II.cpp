class Solution
{
public:
    bool check(const string &s, const int &low, const int &high)
    {
        for (int i = low, j = high; i < j; ++i, --j)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        int low = 0, high = s.size() - 1;
        while (low < high)
        {
            if (s[low] == s[high])
                ++low, --high;
            else
                return check(s, low, high - 1) || check(s, low + 1, high);
        }
        return true;
    }
};
