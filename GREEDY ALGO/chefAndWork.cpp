#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        vector<int> boxes(N);
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> boxes[i];
            
        }
       
        int lifted=0,rounds=1;
        for (int i = 0; i < N; i++)
        {   if(boxes[i]>K){
            rounds=-1;
            break;
        }
           lifted+=boxes[i];
           if(lifted>K){
               lifted=boxes[i];
               rounds++;
           }
        }
        cout<<rounds<<"\n";
    }
}