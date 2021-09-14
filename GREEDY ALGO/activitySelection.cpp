#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<int,int>p1,pair<int,int>p2){
return p1.second<p2.second;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      vector<pair<int,int>>activity(n);
      for(int i=0;i<n;i++){
          cin>>activity[i].first;
          cin>>activity[i].second;

      }
      sort(activity.begin(),activity.end(),cmp);
      int free=0,ans=0;
      for(int i=0;i<n;i++){
          if(free<=activity[i].first){
              ans++;
              free=activity[i].second;
          }
      }
    cout<<ans<<"\n";

    }

}