class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int len = ratings.size();
        if (len < 2)
            return len;
        vector<int> result(len, 1);
        for (int i = 1; i < len; i++)
        {
            if (ratings[i] > ratings[i - 1])
                result[i] = result[i - 1] + 1;
        }
        for (int i = len - 1; i > 0; i--)
        {
            if (ratings[i - 1] > ratings[i])
                result[i - 1] = max(result[i - 1], result[i] + 1);
        }
        return std::accumulate(result.begin(), result.end(), 0);
    }
};

/*Notes:
vector<int> vi{1, 2, 3};
cout << std::accumulate(vi.begin(), vi.end(), 0);    // 6
在迭代器范围内累加，初始值为第三个参数

注意变量命名时有区分度，自动补全的时候注意别看错补充的是哪个
*/
