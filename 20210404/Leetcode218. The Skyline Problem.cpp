class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        multiset<pair<int, int>> all;
        vector<vector<int>> res;

        for (auto &e : buildings)
        {
            all.insert(make_pair(e[0], -e[2]));
            all.insert(make_pair(e[1], e[2]));
        }

        multiset<int> heights({0});
        vector<int> last = {0, 0};
        for (auto &p : all)
        {
            if (p.second < 0)
                heights.insert(-p.second);
            else
                heights.erase(heights.find(p.second));
            auto maxHeight = *heights.rbegin();

            if (last[1] != maxHeight)
            {
                last[0] = p.first;
                last[1] = maxHeight;
                res.push_back(last);
            }
        }
        return res;
    }
};

/*Notes:
 c++语言中，multiset是<set>库中一个非常有用的类型，它可以看成一个序列，插入一个数，删除一个数都能够在O(logn)的时间内完成，而且他能时刻保证序列中的数是有序的，而且序列中可以存在重复的数。
 multiset<pair<int, int>>自动比较，先比较第一个，再比较第二个
*/