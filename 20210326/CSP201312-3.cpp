#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int pin[1010];

int main()
{
    memset(pin, 0, sizeof(pin));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> pin[i];
    }
    int ans = 0;
    stack<int> s;
    for (int i = 0; i <= n + 1; i++)
    {
        while (!s.empty() && pin[s.top()] > pin[i])
        {
            int h = s.top();
            s.pop();
            int left = s.top() + 1;
            int right = i - 1;
            ans = max(ans, (right - left + 1) * pin[h]);
        }
        s.push(i);
    }
    cout << ans;
    return 0;
}

// Same as Leetcode 84. Largest Rectangle in Histogram