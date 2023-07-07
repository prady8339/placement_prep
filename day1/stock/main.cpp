#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void solve()
    {
    }

public:
    int givenFunction(vector<int> &prices)
    {
        int mini = prices[0];
        int maxi = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            mini = min(prices[i], mini);
            if (prices[i] > mini)
            {
                maxi = max(prices[i] - mini, maxi);
            }
        }
        return maxi;
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
        vector<int> prices(n);
        for (int i = 0; i < n; i++)
            cin >> prices[i];
        int ans = ob.givenFunction(prices);
        cout << ans << endl;
    }
    return 0;
}
