//JWALA MUKHI
//P.soma Sujith
//2110110400

/*
I declare an array of size n+1
then i store NULL in arr[0]
then use this to find first node from last in arr[1]
making this in loop will store successive nodes in arrays
and use last element of array to store node n
*/

#include<stdio.h>
#include<stdlib.h>

//Definition of structure of node
struct node{
  int data;
  struct node *next;
};

//Head pointer
struct node *JWALA=NULL;
//Last node pointer
struct node *MUKHI=NULL;

//Adding node to the list
struct node *addNode(int val,struct node *head){
    struct node *new=malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;
    if(head==NULL) head=new;
    else{
        struct node *temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=new;
    }
    return head;
}

//Finding the nth node from the last
void findN(int n,struct node *head){
    struct node *arr[n+2];
    for(int i=0;i<n+2;i++) arr[i]=NULL;
    for(int i=0;i<n+1;i++){
        struct node *temp=head;
        struct node *jp=arr[i];
        while(temp->next!=jp) temp=temp->next;
        arr[i+1]=temp;
    }
    struct node *i=arr[n];
    printf("Data in %dth last node is %d \n",n,i->data);
}

//Prints the list
void printList(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

//Linking last node to the first
void linkLast(struct node *head){
    struct node *temp=head;
    while(temp->next!=NULL) temp=temp->next;
    MUKHI=temp;
    MUKHI->next=JWALA;
}

//Adding the element in the first of circular list
struct node *addCirc(struct node *head,int val){
    struct node *new=malloc(sizeof(struct node));
    new->data=val;
    new->next=JWALA;
    MUKHI->next=new;
    JWALA=new;
    return new;
}

//Printing the list from start to end
void printCirc(struct node *head){
    struct node *temp=head;
    struct node *root=head;
    printf("%d ",temp->data);
    temp=temp->next;
    while(temp!=root){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    FILE *ip;

    //Opening the file
    ip=fopen("LIST2.txt","r");
    if(ip==NULL){
        printf("The file list2.txt doesn't exist");
        exit(0);
    }
    int n,k;

    //Scanning search node
    fscanf(ip,"%d",&n);

    //Scanning and linking the data
    while(!feof(ip)){
        fscanf(ip,"%d",&k);
        JWALA=addNode(k,JWALA);
    }

    //Finding the node
    findN(n,JWALA);

    //linking last node to first
    linkLast(JWALA);

    //Adding in the front
    JWALA=addCirc(JWALA,15);

    //Printing the circular list
    printCirc(JWALA);
}