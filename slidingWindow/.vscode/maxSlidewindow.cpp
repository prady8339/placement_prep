#include <bits/stdc++.h>
using namespace std;

// https : // leetcode.com/problems/sliding-window-maximum/

class Solution
{

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        int i = 0, j = 0;
        while (j < nums.size())
        {
            if (j < k)
            {
                pq.push({nums[j], j});
                j++;
            }
            else
            {
                ans.push_back(pq.top().first);
                pq.push({nums[j], j});
                j++;
                i++;
                while (pq.top().second < i)
                    pq.pop();
            }
        }
        if (!pq.empty())
            ans.push_back(pq.top().first);
        return ans;
    }
};

int main()
{

    Solution ob;
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = ob.maxSlidingWindow(nums, k);
    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
