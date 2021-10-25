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
void printBST( struct Node* node);
void createBST(struct Node* node, int& data);
int main()
{
    int arr[]={15, 10, 20, 8, 50, 12, 16, 25, 17};

    int length = sizeof(arr)/sizeof(arr[0]);

    struct Node* root = new Node(arr[0]);

    for(int i=1;i<length;i++){
        createBST(root, arr[i]);
    }

    //in-order
    printBST(root);
    return 0;
}

void createBST(struct Node* node, int& data){

    if(node->data > data && node->left==NULL){
        node->left=new Node(data);
        return;
    }
    if(node->data < data && node->right==NULL){
        node->right=new Node(data);
        return;
    }
    (node->data > data)? createBST(node->left, data):createBST(node->right, data);

}
void printBST( struct Node* node){
    if(node->left)
        printBST(node->left);
    cout<<node->data<< " ";
    if(node->right)
        printBST(node->right);


}
