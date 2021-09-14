#include<bits/stdc++.h>
using namespace std;
#define ll long long
void selectionSort(vector<int>&v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(v[j]<v[min_idx]){
                min_idx=j;
            }
        }
        swap(v[i],v[min_idx]);
    }
}
int32_t main(){
   vector<int>v{1,5,2,3,6};
   selectionSort(v);
   for(auto &el:v){
       cout<<el<<"\n";
   }
}