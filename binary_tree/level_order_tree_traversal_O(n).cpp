#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* right;
    struct Node* left;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};
void reverseLevelOrderTraverse(struct Node* node);
void levelOrderTraverse(struct Node* node);
int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    levelOrderTraverse(root);

    reverseLevelOrderTraverse(root);

    return 0;
}
void reverseLevelOrderTraverse(struct Node* node){
    queue<struct Node*>q;
    stack<struct Node*>s;

    q.push(node);
    s.push(node);

    while(!q.empty()){

        if(q.front()->right)
            {
                q.push(q.front()->right);
                s.push(q.front()->right);
            }
        if(q.front()->left){
            q.push(q.front()->left);
            s.push(q.front()->left);
        }

        q.pop();
    }
    cout<<endl;
    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }

}
void levelOrderTraverse(struct Node* node){
    queue<struct Node*>q;
    q.push(node);


    while(!q.empty()){
        cout<<q.front()->data<<" ";
        if(q.front()->left)
            q.push(q.front()->left);
        if(q.front()->right)
            q.push(q.front()->right);
        q.pop();
    }
}
