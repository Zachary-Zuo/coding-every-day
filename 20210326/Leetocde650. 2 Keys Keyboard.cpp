class Solution
{
public:
    int minSteps(int n)
    {
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; i++)
        {
            dp[i] = i;
            for (int j = 2; j <= sqrt(i); j++)
            {
                if (i % j == 0)
                {
                    dp[i] = dp[j] + dp[i / j];
                    break;
                }
            }
        }
        return dp[n];
    }
};

//==========================Solution 2======================================
// 本质上是素数分解之后的素数和，因为“乘法”快于“加法”
class Solution
{
public:
    int minSteps(int n)
    {
        int ans = 0;
        int d = 2;
        while (n > 1)
        {
            while (n % d == 0)
            {
                ans += d;
                n /= d;
            }
            d += 1;
        }
        return ans;
    }
};