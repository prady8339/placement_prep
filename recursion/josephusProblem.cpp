#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &people, int idx, int k)
{
    if (people.size() == 1)
        return people[0];

    int die = (idx + k) % people.size();
    people[die] = 0;
    for (int i = die; i < people.size() - 1; i++)
    {
        swap(people[i], people[i + 1]);
    }
    people.pop_back();
    return solve(people, die, k);
}
int main()
{
    int n = 40;
    int k = 7;
    vector<int> people(n);
    for (int i = 0; i < n; i++)
    {
        people[i] = i + 1;
    }
    cout << solve(people, 0, k - 1);
}
