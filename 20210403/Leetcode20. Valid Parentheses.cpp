class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> parsed;
        for (const char &c : s)
        {
            if (c == '{' || c == '[' || c == '(')
                parsed.push(c);
            else
            {
                if (parsed.empty())
                    return false;
                char t = parsed.top();
                if (
                    (c == '}' && t == '{') ||
                    (c == ']' && t == '[') ||
                    (c == ')' && t == '('))
                {
                    parsed.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return parsed.empty();
    }
};