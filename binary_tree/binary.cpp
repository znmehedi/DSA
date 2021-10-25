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
void reverseLevel(struct Node* node);
int main(){

    struct Node* root=new Node(5);
    root->left=new Node(52);
    root->right=new Node(75);

    root->left->left=new Node(53);

    root->right->left=new Node(25);
    root->right->right=new Node(71);

    root->left->left->left=new Node(43);
    root->left->left->right=new Node(70);


    root->right->left->left=new Node(57);
    root->right->left->right=new Node(40);

    root->right->right->left=new Node(10);
    root->right->right->right=new Node(13);



    reverseLevel(root);

    return 0;
}

void reverseLevel(struct Node* node){
    stack<struct Node*>s;
    queue<struct Node*>q;

    s.push(node);
    q.push(node);


    while(!q.empty()){
        if(q.front()->right)
        {
            s.push(node->right);
            q.push(node->right);
        }

        if(q.front()->left)
        {
            s.push(node->left);
            q.push(node->left);
        }
        q.pop();
        }

    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }

}
