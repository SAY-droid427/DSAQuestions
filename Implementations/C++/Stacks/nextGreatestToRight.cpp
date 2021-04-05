//Code to print the next greatest to each element in the array
#include <bits/stdc++.h>
using namespace std;
void nextGreatestToRight(int a[], int n)
{
    vector<int> v;
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty() == true)
            v.push_back(-1);
        else if (s.empty() != true && s.top() > a[i])
            v.push_back(s.top());
        else if (s.empty() != true && s.top() <= a[i])
        {
            while (s.empty() != true && s.top() <= a[i])
                s.pop();
            if (s.empty())
                v.push_back(-1);
            if (s.top() > a[i])
                v.push_back(s.top());
        }
        s.push(a[i]);
    }
    reverse(v.begin(), v.end());
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
    nextGreatestToRight(a, n);
}

/*
INPUT:
4
1 3 2 4
OUTPUT:
3 4 4 -1 
*/
