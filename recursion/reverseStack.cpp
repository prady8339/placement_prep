#include <bits/stdc++.h>

using namespace std;

void insert(stack<int> &st, int tp)
{
    if (st.size() == 0)
    {
        st.push(tp);
        return;
    }
    int topp = st.top();
    st.pop();
    insert(st, tp);
    st.push(topp);
}

void solve(stack<int> &st)
{
    if (st.size() == 0)
    {
        return;
    }
    int tp = st.top();
    st.pop();
    solve(st);
    insert(st, tp);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    solve(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}