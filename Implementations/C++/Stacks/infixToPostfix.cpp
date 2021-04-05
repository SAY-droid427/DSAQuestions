//infix to postfix conversion
#include <bits/stdc++.h>
using namespace std;
bool isOperator(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/')
        return true;
    return false;
}
int prec(char a)
{
    if (a == '+' || a == '-')
        return 1;
    else if (a == '*' || a == '/')
        return 2;
}
void infixToPostfix(string s)
{
    int l = s.length();
    stack<char> st;
    string ns = "";
    st.push('N');
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '(')
            st.push('(');
        else if (s[i] == ')')
        {
            /*If the scanned element is ) then pop elements until the end of the stack is reached or ( is reached*/
            while (st.top() != 'N' && st.top() != '(')
            {
                char x = st.top();
                ns += x;
                st.pop();
            }
            if (st.top() == '(')
            {
                st.pop();
            }
        }
        else if (isOperator(s[i]))
        {
            /*If the precedence of the operator is greater than the precedence of the element scanned then push it 
            If the precedence of the operator is less than the precedence of the elemnt scanned then pop all the elements till a ( is reached or lesser precedence is found or end of stack*/
            while (st.top() != 'N' && prec(st.top()) <= prec(s[i]))
            {
                char x = st.top();
                ns += x;
                st.pop();
            }
            st.push(s[i]);
        }
        else
        {
            ns += s[i];
        }
    }
    while (st.top() != 'N')
    {
        ns += st.top();
        st.pop();
    }
    cout << ns << "\n";
}
int main()
{
    string s;
    cin >> s;
    infixToPostfix(s);
}
