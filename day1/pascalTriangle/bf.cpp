#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void solve()
    {
    }

public:
    vector<vector<long long int>> givenFunction(int n)
    {

        if (n == 0)
            return {};
        if (n == 1)
            return {{1}};
        if (n == 2)
            return {{1}, {1, 1}};
        vector<vector<long long int>> ans(n);
        ans[0] = {1};
        ans[1] = {1, 1};
        for (int i = 2; i < n; i++)
        {
            ans[i].push_back(1);
            for (int j = 1; j < i; j++)
            {
                ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            ans[i].push_back(1);
        }
        return ans;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        int n;
        cin >> n;
        vector<vector<long long int>> ans = ob.givenFunction(n);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl
             << endl;
    }
    return 0;
}
