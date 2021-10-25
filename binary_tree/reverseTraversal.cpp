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
void reverseLevelOrder(struct Node* node);
int main(){
    struct Node* root = new Node(3);
    root->left = new Node(23);
    root->right = new Node(17);

    root->left->left = new Node(26);
    root->left->right = new Node(57);

    root->right->left = new Node(15);
    root->right->right = new Node(22);


    reverseLevelOrder(root);

    return 0;
}

void reverseLevelOrder(struct Node* node){

    queue<struct Node*>q;
    stack<struct Node*>s;

    q.push(node);
    s.push(node);


    while(!q.empty()){
        if(q.front()->right){
            s.push(q.front()->right);
            q.push(q.front()->right);
        }

         if(q.front()->left){
            s.push(q.front()->left);
            q.push(q.front()->left);
        }

        q.pop();
    }

    //print
    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }
    cout<<endl;

}
