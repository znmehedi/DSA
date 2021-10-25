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
bool identicalTreeCheck(struct Node* tree1, struct Node* tree2);
int main(){

    //for 1st tree
    struct Node* tree1 = new Node(15);
    tree1->left=new Node(10);
    tree1->right=new Node(20);

    tree1->left->left=new Node(8);
    tree1->left->right=new Node(12);

    tree1->right->left=new Node(16);
    tree1->right->right=new Node(25);


    //for 2nd tree
    struct Node* tree2 = new Node(15);
    tree2->left=new Node(10);
    tree2->right=new Node(20);

    tree2->left->left=new Node(8);
    tree2->left->right=new Node(12);

    tree2->right->left=new Node(16);
    tree2->right->right=new Node(25);


    identicalTreeCheck(tree1, tree2)?
    (cout<<"Identical"):(cout<<"Not identical");
    cout<<endl;
    return 0;
}


bool identicalTreeCheck(struct Node* tree1, struct Node* tree2){


    return (tree1&&tree2) && (tree1->data==tree2->data) &&
            identicalTreeCheck(tree1->left, tree2->left) &&
            identicalTreeCheck(tree1->right, tree2->right);

}
