//      P.Soma Sujith
//      2110110400
//      P3

#include<stdio.h>
#include<stdlib.h>

//Structure of node in tree
struct Tnode{
    int data;
    struct Tnode *left;
    struct Tnode *right;
};

//Allocating pointers to nodes
struct Tnode *getNode(int value){
    struct Tnode *new = malloc(sizeof(struct Tnode));
       new->data = value;
       new->left = NULL;
       new->right = NULL;
    return new;
}

//Prints the Pre-Order of Tree
void preorder(struct Tnode *root){
    if(root==NULL) return;
    printf("%d  ",root->data);
    preorder(root->left);
    preorder(root->right);
}

//Prints the In-Order of Tree
void inorder(struct Tnode *root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d  ",root->data);
    inorder(root->right);
}

//double the data in every node
void double_using_inOrder_transversal(struct Tnode *root){
    if(root==NULL) return;
    double_using_inOrder_transversal(root->left);
    root->data=(root->data)*2;
    double_using_inOrder_transversal(root->right);
}

int main(){
    struct Tnode *root = NULL;
    struct Tnode *A, *B, *C, *D, *E, *F, *G, *H;
    A = getNode(7);
    B = getNode(5);
    C = getNode(3);
    D = getNode(8);
    E = getNode(6);
    F = getNode(2);
    G = getNode(9);
    H = getNode(1);

    A->right = B;
    A->left = C;
    C->right = E;
    C->left = D;
    root=A;
//----------Tree-1------------------
    printf("Tree-1 \nPre-order : ");
    preorder(root);
    printf("\nIn-Order  : ");
    inorder(root);
//----------Tree-2-------------------
    E->right = H;
    E->left = G;
    B->right = F;
    printf("\n\nTree-2 \nPre-order : ");
    preorder(root);
    printf("\nIn-Order  : ");
    inorder(root);
//----------Tree-3------------------
    A->right=NULL;
    A->left=NULL;
    A->right=C;
    A->left=B;
    printf("\n\nTree-3 \nPre-order : ");
    preorder(root);
    printf("\nIn-Order  : ");
    inorder(root);
    double_using_inOrder_transversal(root);
    printf("\n\nPre-Order of Tree-3 after doubling : ");
    preorder(root);
}