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
void printTree(struct Node* node);
int treeHeight(struct Node* node);
int main(){
    struct Node* root=new Node(15);
    root->left=new Node(10);
    root->right=new Node(20);
    root->left->left=new Node(8);
    root->left->right=new Node(12);
    root->right->left=new Node(16);
    root->right->right=new Node(25);
    root->right->right->left=new Node(25);

    printTree(root);
    cout<<endl<<"Tree Height = "<<treeHeight(root)<<endl;

    return 0;
}
int treeHeight(struct Node* node){
    if(node==NULL)
        return 0;
    return 1+max(treeHeight(node->left), treeHeight(node->right));

}
void printTree(struct Node* node){
    cout<<node->data<<" ";

    if(node->left)
        printTree(node->left);
    if(node->right)
        printTree(node->right);
}
