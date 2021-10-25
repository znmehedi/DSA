//create in c

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->data=data;
    node->left=NULL;
    node->right=NULL;

    return node;
};

int main()
{

    struct Node* root = newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);

    root->left->left=newNode(4);
    root->left->left->left=newNode(5);
    root->left->left->right=newNode(6);
    root->right->left=newNode(7);

    printTree(root);
    return 0;
}
void printTree(struct Node* node){
    printf("%d->", node->data);
    if(node->left!=NULL)
        printTree(node->left);
    if(node->right!=NULL)
        printTree(node->right);
}
