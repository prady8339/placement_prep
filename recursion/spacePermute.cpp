#include <bits/stdc++.h>
using namespace std;

void solve(string input, string output, int idx)
{
    if (idx >= input.size())
    {
        cout << output << endl;
        return;
    }
    string c1 = output;
    string c2 = output;
    c1.push_back(input[idx]);
    c2.push_back(' ');
    c2.push_back(input[idx]);

    solve(input, c1, idx + 1);
    solve(input, c2, idx + 1);
    return;
}
void solve2(string &input, string output)
{
    if (input.size() == 0)
    {
        cout << output << endl;
        return;
    }
    // char get = input[0];
    // output.push_back(get);
    // input.erase(input.begin() + 0);
    // solve2(input, output);
    // output.pop_back();
    // output.push_back(' ');
    // output.push_back(get);
    // solve2(input, output);
    string op1 = output;
    string op2 = output;
    op1.push_back(input[0]);
    op2.push_back(' ');
    op2.push_back(input[0]);
    input.erase(input.begin() + 0);
    solve2(input, op1);
    solve2(input, op2);
    return;
}

int main()
{
    string input = "abcd";
    string output;
    if (input.size() < 1)
        return 0;
    output.push_back(input[0]);
    input.erase(input.begin() + 0);
    // solve(input, output, 0);
    solve2(input, output);
}
