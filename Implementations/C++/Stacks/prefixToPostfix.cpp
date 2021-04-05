//Prefix to postfix conversion
#include <bits/stdc++.h>
using namespace std;
bool isOperator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return true;
    return false;
}
void prefixToPostfix(string s)
{
    stack<string> st;
    int l = s.length();
    for (int i = l - 1; i >= 0; i--)
    {
        if (isOperator(s[i]))
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string ns = op1 + op2 + s[i];
            st.push(ns);
        }
        else
        {
            st.push(string(1, s[i]));
        }
    }
    while (st.empty() != true)
    {
        cout << st.top();
        st.pop();
    }
}
int main()
{
    string s;
    cin >> s;
    prefixToPostfix(s);
}
