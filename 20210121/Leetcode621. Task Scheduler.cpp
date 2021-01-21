class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> table;
        for (char c : tasks)
        {
            table[c]++;
        }

        vector<int> nextValid, rest;
        for (auto [_, v] : table)
        {
            nextValid.push_back(1);
            rest.push_back(v);
        }
        int len = 0;
        for (int i = 0; i < tasks.size(); i++)
        {
            len++;
            int minNext = INT_MAX;
            for (int j = 0; j < table.size(); j++)
            {
                if (rest[j])
                {
                    minNext = min(minNext, nextValid[j]);
                }
            }
            len = max(len, minNext);
            int choose = -1;
            for (int j = 0; j < table.size(); j++)
            {
                if (rest[j] && nextValid[j] <= len)
                {
                    if (choose == -1 || rest[j] > rest[choose])
                    {
                        choose = j;
                    }
                }
            }
            nextValid[choose] = len + n + 1;
            rest[choose]--;
        }
        return len;
    }
};