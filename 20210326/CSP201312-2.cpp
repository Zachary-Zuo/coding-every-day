#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string str = "";
    cin >> str;
    int ans = str[0] - '0';
    for (int i = 2; i <= 4; i++)
    {
        ans += (str[i] - '0') * i;
    }
    for (int i = 6; i <= 10; i++)
    {
        ans += (str[i] - '0') * (i - 1);
    }
    if (ans % 11 == str[12] - '0')
    {
        cout << "Right";
    }
    else if (ans % 11 == 10 && str[12] == 'X')
    {
        cout << "Right";
    }
    else
    {
        str[12] = ans % 11 + '0';
        if (ans % 11 == 10)
            str[12] = 'X';
        cout << str;
    }

    return 0;
}