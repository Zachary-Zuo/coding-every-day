class Solution
{
    vector<int> sums;

public:
    Solution(vector<int> &w) : sums(std::move(w))
    {
        partial_sum(sums.begin(), sums.end(), sums.begin());
    }

    int pickIndex()
    {
        int pos = rand() % sums.back() + 1;
        return lower_bound(sums.begin(), sums.end(), pos) - sums.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

/*Notes:
partial_sum：计算数组前缀和，最后一个参数为结果要存放的起始位置

在从小到大的排序数组中：（左闭右开）
lower_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
upper_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
*/