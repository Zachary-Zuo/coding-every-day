class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int size = isConnected.size();
        if (size == 0)
            return 0;
        vector<bool> visited(size, false);
        int count = 0, k;
        for (int i = 0; i < size; i++)
        {
            if (!visited[i])
            {
                count++;
                stack<int> s;
                s.push(i);
                visited[i] = true;
                while (!s.empty())
                {
                    k = s.top();
                    s.pop();
                    for (int j = 0; j < size; j++)
                    {
                        if (!visited[j] && isConnected[k][j] == 1)
                        {
                            s.push(j);
                            visited[j] = true;
                        }
                    }
                }
            }
        }
        return count;
    }
};