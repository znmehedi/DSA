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
void levelOrder(struct Node* node);
bool printLevel(struct Node* node, int level);
int main(){
    struct Node* root = new Node(15);
    root->left=new Node(10);
    root->right=new Node(20);

    root->left->left=new Node(8);
    root->left->right=new Node(12);
    root->right->left=new Node(16);
    root->right->right=new Node(25);


    levelOrder(root);
    return 0;
}

void levelOrder(struct Node* node){
    int level=1;
    while(printLevel(node, level))
        level++;
}
bool printLevel(struct Node* node, int level){
    if(node==NULL)
        return false;
    if(level==1)
    {
        cout<<node->data<<" ";
        return true;
    }
    return printLevel(node->left, level-1) && printLevel(node->right, level-1);

}
