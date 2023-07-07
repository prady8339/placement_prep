#include <bits/stdc++.h>

using namespace std;

void insert(stack<int> &st, int tp)
{
    if (st.size() == 0 || tp > st.top())
    {
        st.push(tp);
        return;
    }
    int temp = st.top();
    st.pop();
    insert(st, tp);
    st.push(temp);
}

void solve(stack<int> &st)
{
    if (st.size() <= 1)
        return;
    int tp = st.top();
    st.pop();
    solve(st);
    insert(st, tp);
}

int main()
{
    stack<int> st;
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(5);
    st.push(4);

    solve(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}