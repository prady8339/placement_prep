#include <bits/stdc++.h>

using namespace std;

void solve(stack<int> &st, int n)
{
    if (st.size() == n / 2 + 1)
    {
        st.pop();
        return;
    }
    int tp = st.top();
    st.pop();
    solve(st, n);
    st.push(tp);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // st.push(5);

    solve(st, st.size());

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}