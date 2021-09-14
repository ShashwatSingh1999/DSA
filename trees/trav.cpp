#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inversion(Node *root)
{
    if (root == NULL)
        return;
    inversion(root->left);
    inversion(root->right);
    swap(root->left,root->right);
}
int32_t main()
{

    Node *root = new Node(1);
    Node *node1 = new Node(2);
    Node *node2 = new Node(3);
    root->left = node1;
    root->right = node2;
    Node *node3 = new Node(4);
    Node *node4 = new Node(5);
    node1->left = node3;
    node1->right = node4;
    Node *node5 = new Node(6);
    node2->right = node5;
    // inorder(root);
    preorder(root);
    cout<<"\n";
    inversion(root);
    preorder(root);
}