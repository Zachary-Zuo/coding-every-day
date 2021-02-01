class Solution
{
public:
    int getKthMagicNumber(int k)
    {
        if (k < 0)
            return 0;
        long long vec[k];
        vec[0] = 1;
        int it3 = 0, it5 = 0, it7 = 0;
        for (int i = 1; i < k; i++)
        {
            vec[i] = min(min(vec[it3] * 3, vec[it5] * 5), vec[it7] * 7);
            if (vec[i] == vec[it3] * 3)
                it3++;
            if (vec[i] == vec[it5] * 5)
                it5++;
            if (vec[i] == vec[it7] * 7)
                it7++;
        }
        return vec[k - 1];
    }
};

/*Note:
- **去重**
- 注意int表示的范围，如果内存充裕，最好都用long long
*/