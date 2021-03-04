class Solution
{
public:
    bool find(string source, string key)
    {
        int j = 0;
        for (int i = 0; i < source.size() && j < key.size(); i++)
        {
            if (source[i] == key[j])
                j++;
        }
        return j == key.size();
    }
    string findLongestWord(string s, vector<string> &dictionary)
    {
        string max_str = "";
        for (auto str : dictionary)
        {
            if (find(s, str))
                if (str.size() > max_str.size() || (str.size() == max_str.size() && str < max_str))
                    max_str = str;
        }
        return max_str;
    }
};