#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* right;
    struct Node* left;
    Node(int data){
        this->data=data;
        right=left=NULL;
    }

};
void traverse(struct Node* node);
int main(){

    struct Node* root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);


    traverse(root);
    return 0;
}
void traverse(struct Node* node){

    struct Node* temp=node;
    queue<struct Node*>q;
    q.push(temp);
    while(!q.empty()){
        cout<<q.front()->data<<" ";
        if(q.front()->left)
            q.push(q.front()->left);
        if(q.front()->right)
            q.push(q.front()->right);
        q.pop();
    }

}
