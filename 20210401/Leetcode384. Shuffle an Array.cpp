class Solution
{
    vector<int> origin;

public:
    Solution(vector<int> &nums) : origin(nums)
    {
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return origin;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        if (origin.empty())
            return {};
        vector<int> shuffled(origin);
        for (int i = origin.size() - 1; i >= 0; --i)
        {
            swap(shuffled[i], shuffled[rand() % (i + 1)]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

/*Notes:
rand()不需要参数，它会返回一个从0到最大随机数的任意整数，最大随机数的大小通常是固定的一个大整数。
*/