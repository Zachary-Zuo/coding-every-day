#include <iostream>
#include <cstring>
using namespace std;

int numList[10005];

int main()
{
    int n;
    cin >> n;
    int x;
    memset(numList, 0, sizeof(numList));
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        numList[x]++;
    }
    int result = 0, min_num = 0;
    for (int i = 1; i <= 10000; i++)
    {
        if (min_num < numList[i])
        {
            result = i;
            min_num = numList[i];
        }
    }
    cout << result;
    return 0;
}