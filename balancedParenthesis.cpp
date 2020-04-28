#include<bits/stdc++.h>
using namespace std;
bool ArePairs(char start,char end)
{
    if(start="(" && end==')')
    return true;
    if(start=='{' && end=='}')
    return true;
    if(start=='[' && end==']')
    return true;
    return false;
}
void Balanced()
{
    string s;
    cin>>s;
    int l=s.length();
    stack<int> st;int flag=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        st.push(s[i]);
        else if(s[i]==')' || s[i]=='}' || s[i]==']')
        {
            if(st.empty() ||!(ArePairs(st.top(),s[i])) )
            {
                flag=1;
                break;
            }
            st.pop();
        }
        
    }
    if(flag==1 || st.empty()==false)
    cout<<"Not balanced\n";
    else if(flag==0 && st.empty()==true)
    cout<<"Balanced\n";
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
Balanced();
}