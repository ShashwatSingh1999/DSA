#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second > p2.second;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        int n, cap;
        cin >> n >> cap;
        vector<pair<int, int>> price(n);
        vector<pair<int, int>> mass(n);
        for (int i = 0; i < n; i++)
        {
            cin >> price[i].first;
            cin >> mass[i].first;
            price[i].second = price[i].first / mass[i].first;
            mass[i].second = price[i].first / mass[i].first;
        }
        sort(price.begin(), price.end(), cmp);
        sort(mass.begin(), mass.end(), cmp);
        int i=0,ans=0;
        while(i<n && cap>0){
            if(mass[i].first<=cap){
                ans+=price[i].first;
                cap-=mass[i].first;
                i++;
            }
            else{
                ans+=price[i].second*cap;
                i++;
                cap=0;
            }

        }
        cout<<ans<<"\n";
    }
}