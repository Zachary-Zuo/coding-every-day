class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> vec;
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; i++)
            q.push(pair<int, int>(nums[i], i));
        vec.push_back(q.top().first);
        for (int i = k; i < nums.size(); i++)
        {
            q.push(pair<int, int>(nums[i], i));
            while (q.top().second <= i - k)
            {
                q.pop();
            }
            vec.push_back(q.top().first);
        }
        return vec;
    }
};

/*Note:
queue的队首是queue.front()
priority_queue的队首是queue.top()

emplace方法是用传给 emplace() 的参数调用 T 的构造函数，在 queue 的尾部生成对象。
而push方法要求直接压入对象

维护数据结构时，我们无需使其每个时刻都保持最优结构，而只需要保证其正确性，其优化和维护的步骤可以延迟到下一次使用前以降低开销
*/