//Next greatest elements to the left
#include <bits/stdc++.h>
using namespace std;
void nextGreatestElement(int a[], int n)
{
    stack<int> s;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
            v.push_back(-1);
        else if (s.empty() != true && s.top() > a[i])
            v.push_back(s.top());
        else if (s.empty() != true && s.top() <= a[i])
        {
            while (s.empty() != true && s.top() <= a[i])
            {
                s.pop();
            }
            if (s.empty())
                v.push_back(-1);
            if (s.empty() != true && s.top() > a[i])
                v.push_back(s.top());
        }
        s.push(a[i]);
    }
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    nextGreatestElement(a, n);
}
