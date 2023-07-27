#include <bits/stdc++.h>
using namespace std;
void gp(int open, int close, string temp)
{
    if (open <= 0 && close <= 0)
    {
        cout << temp << endl;
        return;
    }
    if (open > 0)
    {
        temp.push_back('(');
        gp(open - 1, close, temp);
        temp.pop_back();
    }
    if (open < close)
    {
        temp.push_back(')');
        gp(open, close - 1, temp);
        temp.pop_back();
    }
}
int main()
{
    int n = 3;
    if (n == 0)
    {
        cout << " ";
        return 0;
    }
    gp(n, n, "");
    return 0;
}
