#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, vector<int> &ans, int k)
{
    queue<int> q;
    for (int i = 0, j = 0; i < arr.size(); i++)
    {
        if (i < k)
        {
            if (arr[i] < 0)
            {
                q.push(arr[i]);
            }
            if (i == k - 1)
            {
                if (!q.empty())
                    ans.push_back(q.front());
            }
            continue;
        }
        else
        {
            if (arr[j++] < 0)
                q.pop();
            if (arr[i] < 0)
                q.push(arr[i]);
            if (!q.empty())
                ans.push_back(q.front());
        }
    }
    return;
}

int main()
{
    vector<int> arr{1, -2, 5, -3, 5, -2, 1, 1, 6, -3};
    int k = 3;
    vector<int> ans;
    solve(arr, ans, k);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}
