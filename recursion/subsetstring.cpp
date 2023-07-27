#include <bits/stdc++.h>
using namespace std;
void subSet(string input, string output, int idx)
{
    if (idx >= input.size())
    {
        for (auto x : output)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    output.push_back(input[idx]);
    subSet(input, output, idx + 1);
    output.pop_back();
    subSet(input, output, idx + 1);
}

int main()
{
    string input = "abcd";
    string output = "";
    subSet(input, output, 0);
}
