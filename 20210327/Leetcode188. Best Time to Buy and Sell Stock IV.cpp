class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int days = prices.size();
        if (days < 2)
            return 0;
        if (k >= days)
        {
            int maxProfit = 0;
            for (int i = 1; i < days; i++)
            {
                if (prices[i] > prices[i - 1])
                    maxProfit += prices[i] - prices[i - 1];
            }
            return maxProfit;
        }
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        for (int i = 0; i < days; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
};