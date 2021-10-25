#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
void printTree(struct Node* node);
int main(){

    struct Node* root=new Node(1);

    root->left=new Node(2);
    root->right=new Node(3);
    root->right->left=new Node(7);

    root->left->left=new Node(4);
    root->left->left->left=new Node(5);
    root->left->left->right=new Node(6);

    printTree(root);
 return 0;
}
void printTree(struct Node* node){
    cout<<node->data<<" ";
    if(node->left)
        printTree(node->left);
    if(node->right)
        printTree(node->right);
}
