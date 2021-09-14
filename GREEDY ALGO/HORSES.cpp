#include<bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
      int N;
      cin>>N;
      vector<int>horse_skills(N);
      for(int i=0;i<N;i++){
         cin>>horse_skills[i];
        
      }
      sort(horse_skills.begin(),horse_skills.end());
      int ans=INT_MAX;
      for(int i=1;i<N;i++){
          ans=min(ans,horse_skills[i]-horse_skills[i-1]);
      }
      cout<<ans<<"\n";
    }

}   