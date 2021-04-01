class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int checklist[26] = {0};
        for (const char &c : magazine)
        {
            checklist[c - 'a']++;
        }
        bool find = true;
        for (const char &c : ransomNote)
        {
            checklist[c - 'a']--;
            if (checklist[c - 'a'] < 0)
            {
                find = false;
                break;
            }
        }
        return find;
    }
};