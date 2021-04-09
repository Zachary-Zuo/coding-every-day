#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct points
{
    int x;
    int y;
    int num;
    int d;
};

bool operator<(const points &p1, const points &p2)
{
    if (p1.d != p2.d)
        return p1.d < p2.d;
    else
        return p1.num < p2.num;
}

int main()
{
    int n, X, Y;
    vector<points> p;
    cin >> n >> X >> Y;
    for (int i = 0; i < n; i++)
    {
        points t;
        cin >> t.x >> t.y;
        t.num = i + 1;
        t.d = (X - t.x) * (X - t.x) + (Y - t.y) * (Y - t.y);
        p.push_back(t);
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < 3; i++)
    {
        cout << p[i].num << endl;
    }
    return 0;
}