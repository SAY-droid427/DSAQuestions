#include<bits/stdc++.h>
using namespace std;

bool isBalanced(char a,char b)
{
    if(a=='{' && b=='}')
    return true;
    if(a=='(' && b==')')
    return true;
    if(a=='[' && b==']')
    return true;

    return false;
}

void balancedParenthesis(string s)
{
    stack<pair<char,int>> st;
    int flag=1;

    int l=s.length();

    for(int i=0;i<l;i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        st.push({s[i],i+1});
        else if(s[i]=='}' || s[i]==']' || s[i]==')')
        {
            if(!st.empty() && isBalanced(st.top().first,s[i]))
            st.pop();
            else
            {
                flag=0;
                break;                
            }
            
        }
    }

    if(st.empty()==false)
    cout<<"Not balanced\n";
    else if(flag==0)
    cout<<"Not balanced\n";
    else
    cout<<"Balanced\n";
}

int main()
{
    string s;
    cin>>s;
    balancedParenthesis(s);
}