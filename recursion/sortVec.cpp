#include <bits/stdc++.h>

using namespace std;
// bascially insertion sort using recursion
void insert(vector<int> &arr, int tp)
{

    if (arr.size() == 0 || arr[arr.size() - 1] <= tp)
    {
        arr.push_back(tp);
        return;
    }

    int top = arr.back();
    arr.pop_back();
    insert(arr, tp);
    arr.push_back(top);
}

void solve(vector<int> &arr)
{
    if (arr.size() <= 1)
        return;
    int tp = arr.back();
    arr.pop_back();
    solve(arr);
    // arr.push_back(tp);
    // int j = arr.size()-1;
    // while(j>=1 && arr[j]<arr[j-1]){ swap(arr[j],arr[j-1]); j--; }
    insert(arr, tp);
}

int main()
{
    vector<int> arr{3, 2, 1, 5, 4};

    solve(arr);
    for (auto x : arr)
    {
        cout << x << " ";
    }

    return 0;
}