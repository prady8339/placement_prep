#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int k)
{
    int sum = 0;
    if (arr.size() <= k)
    {
        for (int i = 0; i < k; i++)
        {
            sum += arr[i];
        }
        return sum;
    }
    int maxi = sum;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
        maxi = max(sum, maxi);
    }
    for (int i = k; i < arr.size(); i++)
    {
        sum -= arr[i - k];
        sum += arr[i];
        maxi = max(sum, maxi);
    }
    return maxi;
}

int main()
{
    vector<int> arr{1, 2, 5, 2, 5, 2, 1, 1, 6, 3};
    int k = 3;
    cout << solve(arr, k);
    return 0;
}
