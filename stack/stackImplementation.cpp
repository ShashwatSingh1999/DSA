#include<bits/stdc++.h>
using namespace std;
#define ll long long
class myStack{
    int cap;
    vector<int>v;
    public:
    void push(int a){
        v.push_back(a);
    }
    int pop(){
            int ans=v[v.size()-1];
        if(v.empty())ans=INT_MIN;
        else{
            v.pop_back();
        }
        return ans;
    }
    int size(){
        return v.size();
    }
    int peek(){
        if(v.empty()){
            return INT_MIN;
        }
        return v[v.size()-1];
    }
    void printStack(){
        for(int i=v.size()-1;i>=0;--i)
        cout<<v[i]<<endl;
    }
    bool isEmpty(){
        return v.empty();
    }
};
int32_t main(){
myStack st;
st.push(3);
st.push(4);
st.push(5);
st.push(6);
// st.printStack();
st.pop();
st.printStack();
cout<<boolalpha<<st.isEmpty();





}