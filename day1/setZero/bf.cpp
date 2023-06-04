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
        int n = matrix.size(), m = matrix[0].size();
        vector<int> cols(m, 1), rows(n, 1);
        // marking rows and cols which are zero
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (rows[i] == 0 || cols[j] == 0)
                    matrix[i][j] = 0;
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
