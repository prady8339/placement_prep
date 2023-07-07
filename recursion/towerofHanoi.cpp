#include <bits/stdc++.h>
using namespace std;

void solve(int n, int s, int h, int d)
{
    if (n == 1)
    {
        cout << "move plate " << n << " from " << s << " to " << d << endl
             << endl;
        return;
    }
    solve(n - 1, s, d, h);
    cout << "move plate " << n << " from " << s << " to " << d << endl
         << endl;
    solve(n - 1, h, s, d);
}

int main()
{

    int n = 5;

    int s = 1, h = 2, d = 3;
    solve(n, s, h, d);

    return 0;
}
