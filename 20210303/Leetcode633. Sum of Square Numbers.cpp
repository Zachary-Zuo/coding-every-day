class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (int i = 2; i * i <= c; ++i)
        {
            int count = 0;
            if (c % i == 0)
            {
                while (c % i == 0)
                {
                    count++;
                    c /= i;
                }
                if (i % 4 == 3 && count % 2 != 0)
                    return false;
            }
        }
        return c % 4 != 3;
    }
};

/*Notes:
费马平方和定理：
一个非负整数 c 能够表示为两个整数的平方和，当且仅当 c 的所有形如 4k+3 的质因子的幂次均为偶数。
*/