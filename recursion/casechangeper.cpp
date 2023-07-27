#include <bits/stdc++.h>
using namespace std;
void solve(string &s, string temp, int idx)
{
    if (idx >= s.size())
    {
        cout << temp << endl;
        return;
    }

    temp.push_back(s[idx]);
    solve(s, temp, idx + 1);
    temp.pop_back();
    temp.push_back(s[idx] - 'a' + 'A');
    solve(s, temp, idx + 1);
}

void varsolve(string &s, string temp, int idx)
{
    if (idx >= s.size())
    {
        cout << temp << endl;
        return;
    }

    if (s[idx] >= 'A' && s[idx] <= 'Z')
    {
        temp.push_back(s[idx]);
        varsolve(s, temp, idx + 1);
        temp.pop_back();
        temp.push_back(s[idx] - 'A' + 'a');
        varsolve(s, temp, idx + 1);
    }
    else if (s[idx] >= 'a' && s[idx] <= 'z')
    {
        temp.push_back(s[idx]);
        varsolve(s, temp, idx + 1);
        temp.pop_back();
        temp.push_back(s[idx] - 'a' + 'A');
        varsolve(s, temp, idx + 1);
    }
    else
    {
        temp.push_back(s[idx]);
        varsolve(s, temp, idx + 1);
    }
}

int main()
{

    // string s = "abc";
    // solve(s, "", 0);
    string vs = "aBc1D7";
    varsolve(vs, "", 0);
    return 0;
}
