class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> ans;
        for (int i = 0; i < expression.length(); i++)
        {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*')
            {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (const auto &l : left)
                {
                    for (const auto &r : right)
                    {
                        switch (c)
                        {
                        case '+':
                            ans.push_back(l + r);
                            break;
                        case '-':
                            ans.push_back(l - r);
                            break;
                        case '*':
                            ans.push_back(l * r);
                            break;
                        }
                    }
                }
            }
        }
        if (ans.empty())
            ans.push_back(stoi(expression));
        return ans;
    }
};