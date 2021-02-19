class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> result;
        for (auto &person : people)
        {
            result.insert(result.begin() + person[1], person);
        }
        return result;
    }
};

/*Notes:
vector的insert的位置必须与现有vector的内容相连，即：头、尾、中间
不能有间隔，不会自动填充。
*/