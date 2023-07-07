#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void solve()
    {
    }

public:
    int givenFunction(vector<int> &nums)
    {
        int maxi = INT_MIN;
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum > maxi)
                maxi = sum;
            if (sum < 0)
                sum = 0;
        }
        // if(maxi<0) return 0;
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
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        int ans = ob.givenFunction(nums);
        cout << ans << endl;
    }
    return 0;
}
