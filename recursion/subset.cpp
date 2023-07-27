#include <bits/stdc++.h>
using namespace std;
void subSet(vector<int> &arr, vector<int> &ds, int idx)
{
    if (idx >= arr.size())
    {
        for (auto x : ds)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    ds.push_back(arr[idx]);
    subSet(arr, ds, idx + 1);
    ds.pop_back();
    subSet(arr, ds, idx + 1);
}

int main()
{
    vector<int> arr{1, 2, 3, 4};
    vector<int> ds;
    subSet(arr, ds, 0);
}
