#include <bits/stdc++.h>
using namespace std;
#define ll long long
// /if one closing balanced by 2 opening  then check if balanced
bool isBalanced(string &s)
{
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push(s[i]);
        }
        else{
        if(!st.empty() && st.top()=='(')
        {
            st.pop();
            if(!st.empty() && st.top()=='('){
                st.pop();
            }           
            else{
                st.push(s[i]);
            }
        }   
        else{
            st.push(s[i]);
        }         

        }
    }
    return st.empty();
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << boolalpha << isBalanced(s);
        
    }
}