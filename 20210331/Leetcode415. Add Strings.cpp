class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string output("");
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int len_1 = num1.length();
        int len_2 = num2.length();
        if (len_1 <= len_2)
        {
            swap(num1, num2);
            swap(len_1, len_2);
        }
        int addbit = 0;
        for (int i = 0; i < len_2; i++)
        {
            int cur_sum = (num1[i] - '0') + (num2[i] - '0') + addbit;
            output += to_string(cur_sum % 10);
            addbit = cur_sum < 10 ? 0 : 1;
        }
        for (int i = len_2; i < len_1; i++)
        {
            int cur_sum = (num1[i] - '0') + addbit;
            output += to_string(cur_sum % 10);
            addbit = cur_sum < 10 ? 0 : 1;
        }
        if (addbit)
        {
            output += "1";
        }
        reverse(output.begin(), output.end());
        return output;
    }
};