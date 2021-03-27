class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int sell = 0, min_price = INT_MAX;
        for (const auto &price : prices)
        {
            min_price = min(min_price, price);
            sell = max(sell, price - min_price);
        }
        return sell;
    }
};