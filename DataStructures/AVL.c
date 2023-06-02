#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a > b) ? (a) : (b))
struct node{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

struct node *createNode(int data){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->key = data;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

int findHeight(struct node *root){
    if (root == NULL)  return 0;
    return root->height;
}

int balanceFactor(struct node *root){
    if (root == NULL) return 0;
    return (findHeight(root->left) - findHeight(root->right));
}

struct node *leftLeftRotate(struct node *root){
    struct node *leftChild = root->left;
    struct node *temp = root->left->right;
    leftChild->right = root;
    root->left = temp;
    root->height = 1 + max(findHeight(root->left) , findHeight(root->right));
    leftChild->height = 1 + max(findHeight(leftChild->left), findHeight(leftChild->right));
    return leftChild;
}

struct node *rightRightRotate(struct node *root){
    struct node *rightChild = root->right;
    struct node *temp = rightChild->left;
    rightChild->left = root;
    root->right = temp;
    root->height = 1 + max(findHeight(root->left) , findHeight(root->right));
    rightChild->height = 1 + max(findHeight(rightChild->left), findHeight(rightChild->right));
    return rightChild;
}

struct node *insert(struct node *root, int data){
    if (root == NULL){
        struct node *n = createNode(data);
        return n;
    }
    if (root->key > data) root->left = insert(root->left, data);
    else  root->right = insert(root->right, data);
    root->height = 1 + max(findHeight(root->left) , findHeight(root->right));
    int bf = balanceFactor(root);
    if(bf > 1 && data < root->left->key){
        root = leftLeftRotate(root);
        return root;
    }
    //RIGHT RIGHT ROTATE
    if(bf < -1 && data > root->right->key){
        root = rightRightRotate(root);
        return root;
    }

    //LEFT RIGHT ROTATE
    if(bf > 1 && data > root->left->key){
        root->left = rightRightRotate(root->left);
        root = leftLeftRotate(root);
        return root;
    }

    //RIGHT LEFT ROTATE
    if(bf < -1 && data < root->right->key){
        root->right = leftLeftRotate(root->right);
        root = rightRightRotate(root);
        return root;
    }
    return root;
}

void preorder(struct node* root){
    if(root == NULL) return;
    printf("%d ",root->key);
    preorder(root->left);
    preorder(root->right);
    return;
}

int main(){
    struct node* root = NULL;
    root = insert(root , 11);
    root = insert(root , 9);
    root = insert(root , 18);
    root = insert(root , 5);
    root = insert(root , 10);
    root = insert(root , 6);
    preorder(root);
    printf("\n");
}