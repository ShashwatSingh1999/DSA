#include<bits/stdc++.h>
using namespace std;
#define ll long long
void bubbleSort(vector<int>&v){

for(int i=0;i<v.size()-1;i++){
    bool swapped=false;
    for(int j=0;j<v.size()-1-i;j++){
        if(v[j]>v[j+1]){
            swap(v[j],v[j+1]);
            swapped=true;
        }
    }
    if(!swapped){
        break;
    }
}
}
int32_t main(){
vector<int>v{1,6,2,3,5};
bubbleSort(v);
for(auto &el:v){
    cout<<el<<" \n";
}

}