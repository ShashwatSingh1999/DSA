#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
    int val;
    Node *next;
    Node(int v)
    {
        val = v;
        next = NULL;
    }
};

void *insertAtBegin(Node *&frnt, int v)
{
    Node *temp = new Node(v);
    temp->next = frnt;
    frnt = temp;
}
void printLL(Node *frnt)
{
    while (frnt != NULL)
    {
        cout << frnt->val << " ";
        frnt = frnt->next;
    }
}
void insertAtEnd(Node *&bck, int v)
{
    Node *temp = new Node(v);
    bck->next = temp;
    bck = temp;
}
void DeleteFront(Node *&frnt)
{
    Node *temp = frnt;
    frnt = frnt->next;
    delete temp;
}
void DeleteBack(Node *&frnt)
{
    Node *it = frnt;
    while (it->next->next != NULL)
    {
        it = it->next;
    }
    Node *temp = it->next;
    it->next = NULL;
    delete temp;
}
void Delete(Node *&frnt,int v,Node *&bck)
{
    Node *it = frnt;
    if(it->val==v){
        frnt=frnt->next;
        delete it;
        return;
    }
    while(it->next->val!=v && it!=NULL){
        it=it->next;
    }
    if(it->next->next==NULL){
        bck=it;
        delete it->next;
        return;
    }
    Node*temp=it->next;
    it->next=it->next->next;
    delete temp;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *firstNode = new Node(5);
    Node *bck = NULL, *frnt = NULL;
    bck = frnt = firstNode;
    insertAtBegin(frnt, 10);
    insertAtBegin(frnt, 0);
    insertAtBegin(frnt, 1);
    insertAtEnd(bck, 20);
    insertAtEnd(bck, 34);
    insertAtEnd(bck, 44);
    insertAtEnd(bck, 44);
    // DeleteFront(frnt);
    DeleteBack(frnt);
    DeleteBack(frnt);
    Delete(frnt,5,bck);
    Delete(frnt,20,bck);
    printLL(frnt);
}