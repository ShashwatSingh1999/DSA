#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}
char toLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}
char toUpper(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    return c;
}
void print(int n)
{
    if (n == 0)
        return;
    print(n - 1);
    cout << "\n";
    for (int i = 1; i <= n; i++)
        cout << i << " ";
}
void print2(int n)
{
    if (n == 0)
        return;
    for (int i = 1; i <= n; i++)
        cout << i << " ";
    cout << "\n";
    print2(n - 1);
}
void print_triangle_sum(vector<int> &v)
{

    if (v.size() < 1)
        return;

    vector<int> temp;
    for (int i = 1; i < v.size(); i++)
    {
        temp.push_back(v[i] + v[i - 1]);
    }
    print_triangle_sum(temp);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}
int findMin(vector<int>&v)
{ if(v.size()==1)return v[0];
  int temp=v[v.size()-1];
  v.pop_back();
  int minEl=findMin(v);
  return min(minEl,temp);
}
int findMax(vector<int>&v){
    if(v.size()==1)return v[0];
    int temp=v[v.size()-1];
    v.pop_back();
    int maxEl=findMax(v);
    return max(maxEl,temp);
}
char findFirstUpperCase(string &s){
      if(s.size()==0)return 0;
      char temp=s.back();
      s.pop_back();
      char val=findFirstUpperCase(s);
      if(val>='A' && val<='Z')return val;
      if(temp>='A' && temp<='Z')return temp;
      return 0;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // print(5);
    // print2(5);
    vector<int> v{1, 4, 45, 6, 10, -8};
    // print_triangle_sum(v);
    // cout<<findMin(v);
    // cout<<findMax(v);
    string s="geekS";
    cout<<findFirstUpperCase(s);
}