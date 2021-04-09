#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, t;
    int xl, yl, xr, yr;
    cin >> n >> k >> t >> xl >> yl >> xr >> yr;
    int xi, yi;
    int num;
    int pass = 0, stop = 0;
    for (int i = 0; i < n; i++)
    {
        num = 0;
        bool add = false;
        bool addpass = false;
        for (int j = 0; j < t; j++)
        {
            cin >> xi >> yi;
            if (xi >= xl && xi <= xr && yi >= yl && yi <= yr)
            {
                if (!add)
                {
                    pass++;
                    add = true;
                }
                num++;
                if (addpass == false && num >= k)
                {
                    stop++;
                    addpass = true;
                }
            }
            else
            {
                num = 0;
            }
        }
    }
    cout << pass << endl;
    cout << stop << endl;
    return 0;
}