#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      vector<int>price(n);
      for(int i=0;i<n;i++){
          cin>>price[i];
      }
      sort(price.begin(),price.end(),greater<int>());
      int ans=0;
      for(int i=0;i<n;i++){
          ans+=max((price[i]-i),0);
          ans%=mod;
      }
      cout<<ans<<"\n";
    }

}