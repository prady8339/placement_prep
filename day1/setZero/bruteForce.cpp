#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void solve()
    {
    }

public:
    void givenFunction(vector<vector<int>> &matrix)
    {
        unordered_set<int> cols, rows;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    cols.insert(j);
                    rows.insert(i);
                }
            }
        }

        for (auto x : rows)
        {
            for (int i = 0; i < matrix[0].size(); i++)
            {
                matrix[x][i] = 0;
            }
        }
        for (auto x : cols)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][x] = 0;
            }
        }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }

        ob.givenFunction(matrix);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}
