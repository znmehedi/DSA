#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};
void inOderTraversal(struct Node* node);
void preOderTraversal(struct Node* node);
void postOderTraversal(struct Node* node);

int main(){

    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->right->left=new Node(5);
    root->right->right=new Node(6);
    root->right->left->left=new Node(7);
    root->right->left->right=new Node(8);

    //inOderTraversal(root);//left-root-right
    //preOderTraversal(root);//root-left-right
    //postOderTraversal(root);//left-right-root
    return 0;
}
void inOderTraversal(struct Node* node){
    if(node->left)
        inOderTraversal(node->left);

    cout<<node->data<<" ";

    if(node->right)
        inOderTraversal(node->right);
}
void preOderTraversal(struct Node* node){
    cout<<node->data<<" ";

    if(node->left)
        preOderTraversal(node->left);

    if(node->right)
        preOderTraversal(node->right);
}
void postOderTraversal(struct Node* node){
    if(node->left)
        postOderTraversal(node->left);

    if(node->right)
        postOderTraversal(node->right);

    cout<<node->data<<" ";
}
