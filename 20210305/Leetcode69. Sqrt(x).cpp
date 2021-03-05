class Solution
{
public:
    int mySqrt(int x)
    {
        long a = x;
        while (a * a > x)
            a = (a + x / a) / 2;
        return a;
    }
};

/*Notes:
牛顿迭代法：
x_{n+1} = x_n-f(x_n)/f'(x_n)
*/