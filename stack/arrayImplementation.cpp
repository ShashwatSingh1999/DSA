#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct myStack
{
private:
    int cap;
    int *arr;
    int top;

public:
    myStack(int c)
    {
        cap = c;
        arr = new int[cap];
        top = -1;
    }
    void push(int el)
    {
        if (top == cap - 1)
        {
            cout << "over flow" << endl;
            return;
        }
        top++;
        arr[top] = el;
    }
    int pop()
    {
        if (top == -1)
            return INT_MIN;
        top--;
        return arr[top];
    }
    int peek()
    {   if(top==-1)return INT_MIN;

        return arr[top];
    }
    int size()
    {
        return top + 1;
    }
    bool isEmpty()
    {
        return (top == -1);
    }
};
int32_t main()
{
    myStack st(5);
    st.push(2);
    st.pop();
    st.push(3);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    while(!st.isEmpty()){
        cout<<st.peek()<<endl;
        st.pop();
    }
    cout<<st.peek();
    
}