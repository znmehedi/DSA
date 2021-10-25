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
void spiralOrder(struct Node* node);
int main(){
    struct Node* root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);

    root->right->left=new Node(6);
    root->right->right=new Node(7);

    spiralOrder(root);
    return 0;
}

void spiralOrder(struct Node* node){
    if(node==NULL)
        return;

    stack<struct Node*>s1, s2;

    s1.push(node);

    while(!s1.empty()||!s2.empty()){

        while(!s1.empty()){

            if(s1.top()->left)
                s2.push(s1.top()->left);
            if(s1.top()->right)
                s2.push(s1.top()->right);
            cout<<s1.top()->data<<" ";
            s1.pop();
        }
        cout<<endl;
        while(!s2.empty()){

            if(s2.top()->right)
                s1.push(s2.top()->right);
            if(s2.top()->left)
                s1.push(s2.top()->left);
            cout<<s2.top()->data<<" ";
            s2.pop();
        }
        cout<<endl;
    }



}
