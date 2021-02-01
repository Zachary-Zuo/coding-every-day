class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        string result(s.length(), 0);
        for (int i = 0; i < s.length(); i++)
        {
            result[indices[i]] = s[i];
        }
        return result;
    }
};

/*Note:
string result(s.length(), 0); 可创建指定长度空字符串
*/