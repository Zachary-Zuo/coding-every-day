class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> chars(128, 0);
        vector<bool> flags(128, false);
        for (auto c : t)
        {
            flags[c] = true;
            ++chars[c];
        }

        int cnt = 0, l = 0, l_min = 0, size = s.size() + 1;
        for (int i = 0; i < s.size(); ++i)
        {
            if (flags[s[i]])
            {
                if (--chars[s[i]] >= 0)
                {
                    cnt++;
                }
                while (cnt == t.size())
                {
                    if (i - l + 1 < size)
                    {
                        l_min = l;
                        size = i - l + 1;
                    }
                    if (flags[s[l]] && ++chars[s[l]] > 0)
                    {
                        --cnt;
                    }
                    ++l;
                }
            }
        }
        return size > s.size() ? "" : s.substr(l_min, size);
    }
};

/*Notes:
string.substr
0. 用途：一种构造string的方法
1. 形式：s.substr(pos, n)
2. 解释：返回一个string，包含s中从pos开始的n个字符的拷贝（pos的默认值是0，n的默认值是s.size() - pos，即不加参数会默认拷贝整个s）
3. 补充：若pos的值超过了string的大小，则substr函数会抛出一个out_of_range异常；若pos+n的值超过了string的大小，则substr会调整n的值，只拷贝到string的末尾
*/
