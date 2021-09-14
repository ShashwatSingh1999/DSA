#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
    }
};
struct myStack
{
    Node *head;
    int sz;
    myStack(){
        head=NULL;
        sz=0;
    }
    void push(int val){
        Node *temp=new Node(val);
        temp->next=head;
        head=temp;
        sz++;
    }
    int pop(){
        if(head==NULL)return INT_MIN;
        int top=head->data;
        Node*temp=head;
        head=head->next;
        delete temp;
        sz--;
        return top;
    }
    int top(){
        return head->data;
    }
    int size(){
        return sz;
    }
    bool isEmpty(){
        return (sz==0);
    }
};
int32_t main()
{
    myStack st;
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(6);
    st.push(6);
    st.pop();
    cout<<st.size()<<endl;
    while(!st.isEmpty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    cout<<boolalpha<<st.isEmpty();
}