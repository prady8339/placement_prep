#include <bits/stdc++.h>
using namespace std;
void solve(int n, int one, int zero, vector<int> &ds)
{
    if (one + zero > n)
        return;

    if (one + zero == n)
    {
        for (auto x : ds)
            cout << x << " ";
        cout << endl;
        return;
    }

    ds.push_back(1);
    solve(n, one + 1, zero, ds);
    ds.pop_back();
    if (one > zero)
    {
        ds.push_back(0);
        solve(n, one, zero + 1, ds);
        ds.pop_back();
    }
}
int main()
{

    int n = 4;
    vector<int> ds;
    solve(n, 0, 0, ds);
    return 0;
}
