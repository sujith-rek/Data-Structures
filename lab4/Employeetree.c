/*
                                                        LAB-4 EMPLOYEE TREE
                                                        P.Soma sujith
                                                        2110110400
                                                        Lab group - P3
         “I certify that this is my own work and I have not copied any part of it from other sources. I have not shared my code with any other student”
                                                        ALL TASKS  */
#include<stdio.h>
#include<stdlib.h>

struct Tnode{
  char ch;
  struct Tnode *right;
  struct Tnode *left;
};

int BST=1,check=0;
struct Tnode *arr[65][3];

//Making nodes
struct Tnode *getNode(char c){
    struct Tnode *new = malloc(sizeof(struct Tnode));
      new->ch = c;
      new->left = NULL;
      new->right = NULL;
    return new;
}

//In-order of tree
void inOrder(struct Tnode *root){
    if(root==NULL) return;
    inOrder(root->left);
    printf("%c ",root->ch);
    inOrder(root->right);
}

//Pre-Order of tree
void preOrder(struct Tnode *root){
    if(root==NULL) return;
    printf("%c ",root->ch);
    preOrder(root->left);
    preOrder(root->right);
}

//Height of the tree
int height(struct Tnode *root){
    if(root==NULL) return 0;
    else return 1+(height(root->left)>height(root->right)?height(root->left):height(root->right));
}

//Finding number of bosses
int numberOfBosses(struct Tnode *root){
    if(root==NULL) return 0;
    if(root->right==NULL && root->left==NULL) return 0;
    else return 1+numberOfBosses(root->right)+numberOfBosses(root->left);
}

//To find out if the given tree is binary search tree or not
void isBST(struct Tnode *root){
    if(root==NULL) return;
        isBST(root->left);

        if(root->left != NULL && root->left->ch > root->ch){
            printf("This tree failed to be a Binary search tree ");
            printf("It failed at %c \n\n",root->ch);
            BST=0;
        }
        else if(root->right!=NULL && root->right->ch < root->ch){
            printf("This tree failed to be a Binary search tree ");
            printf("It failed at %c \n\n",root->ch);
            BST=0;
        }

        isBST(root->right);
    }

//Function for shuffling
struct Tnode *specialFunction(struct Tnode *root){
    struct Tnode *alpha;
    struct Tnode *omicron;
    alpha=root;
    omicron=alpha->right;
    alpha->right=omicron->left;
    omicron->left= alpha;
    return omicron;
}

//Checks for persons and their team mates in tree
void checkFor(struct Tnode *root,char c){
    if(root==NULL) return;
    if(root->ch==c){
        printf("\nConfirmed that %c is an employee\n",c);
        printf("He has no team-mates");
        check=1;
        return;
    }
    if(root->right!=NULL && root->right->ch==c){
        printf("\nConfirmed that %c is an employee\n",c);
        if(root->left!=NULL) printf("Team mate is %c\n",root->left->ch);
        else printf("%c is sole member of team\n",c);
        check=1;
        return;
    }
    else if(root->left!=NULL && root->left->ch==c){
        printf("\nConfirmed that %c is an employee\n",c);
        if(root->right != NULL ) printf("Team mate is %c\n",root->right->ch);
        else printf("%c is sole member of team\n",c);
        check=1;
        return;
    }
    else {
        checkFor(root->right,c);
        checkFor(root->left,c);}
}

//Function to link nodes and make the tree
void linkNodes(struct Tnode *root,int n,int anc){
    if(root==NULL) return;
    char ri=arr[anc][2]->ch,le=arr[anc][0]->ch;
    int j,k;
    for(int i=0;i<n;i++) if(arr[i][1]->ch == ri) {root->right=arr[i][1];j=i;}
    for(int i=0;i<n;i++) if(arr[i][1]->ch == le) {root->left=arr[i][1];k=i;}
    linkNodes(root->right,n,j);
    linkNodes(root->left,n,k);
}

int main(){
    FILE *ip;
    ip=fopen("employee.txt","r");
    if(ip==NULL){
        printf("The data file doesn't exist ");
        exit(0);}
    char nnn,ppp;
    struct Tnode *root=NULL;

    for(int k=0;k<50;k++) for(int j=0;j<3;j++) arr[k][j]=NULL;

    //reading nnn
    fscanf(ip,"%s",&nnn);

    //reading ppp
    fscanf(ip,"%s",&ppp);

    int n=0;
    //reading all the tuples
    while(!feof(ip)){
        char ro,le,ri;
        fscanf(ip,"%s",&ro);
        arr[n][1]=getNode(ro);
        fscanf(ip,"%s",&le);
        arr[n][0]=getNode(le);
        fscanf(ip,"%s",&ri);
        arr[n][2]=getNode(ri);
        n++;
    }

    //task 1 Finding the root and linking all nodes to form a tree
    //To find the CEO
    int flag=0;
    for(int i=0;i<n;i++){
        char c=arr[i][1] -> ch;
        int counter=0;
        for(int k=0;k<n;k++) if((arr[k][0])->ch == c || arr[k][2] -> ch == c) counter++;
        if(counter==0) flag=i;
    }

    //Linking nodes
    root = arr[flag][1];
    linkNodes(root,n,flag);

    //task 2 inOrder transversal
    printf("In-Order transversal of the tree is \n");
    inOrder(root);

    //task 3 Height of tree
    printf("\n\nHeight of the tree is %d \n",height(root));

    //task 4 Printing number of bosses
    printf("\nNumber of bosses are : %d\n\n",numberOfBosses(root));

    //task 5 Checking if the tree is BST or not
    isBST(root);
    if(BST==1) printf("The tree is Binary search tree whose CEO is %c\n\n",root->ch);

    //task 6 Role shuffling
    root=specialFunction(root);
    printf("Pre-Oder of employees after shuffling is \n");
    preOrder(root);
    printf("\n");

    //task 7 Checking for nnn and ppp
    checkFor(root,nnn);
    if(check!=1) printf("%c isn't an employee of company\n",nnn);
    check=0;
    checkFor(root,ppp);
    if(check!=1) printf("%c isn't an employee of company\n",ppp);

    fclose(ip);
}