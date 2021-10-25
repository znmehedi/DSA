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
void deleteTree(struct Node* node);
int main(){
    struct Node* root=new Node(15);
    root->left=new Node(10);
    root->right=new Node(20);
    root->left->left=new Node(8);
    root->left->right=new Node(12);
    root->right->left=new Node(16);
    root->right->right=new Node(25);
    root->right->right->left=new Node(25);

    deleteTree(root);
    return 0;
}
void deleteTree(struct Node* node){
    if(node==NULL)
        return;
    if(node->left)
        deleteTree(node->left);
    if(node->right)
        deleteTree(node->right);
    cout<<"Delete---ing "<<node->data<<endl;
    delete node;

}
