/*
As B is two digits
we are dealing with 2+1 stacks
Here, We are multiplying A with first digit of B and stroing in a stack[0]
doing same and storing in stack[1]
then we reverse both stacks, add them and store in stack3
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure of node
struct node{
    int digit;
    struct node *next;
};

int c;

//stack[0] is for multiplication for first digit of B
//stack[1] is for multiplication for second digit of B
//stack3 is for storing product
struct node *stack[2],*stack3=NULL;

//Push elements into stack
struct node *push(struct node *head,int val){
    struct node *new=malloc(sizeof(struct node));
    new->digit=val;
    new->next=head;
    head=new;
    return head;
}

//popping elements out of stack
struct node *pop(struct node *head){
    struct node *temp=head;
    c=temp->digit;
    head=head->next;
    free(temp);
    return head;
}

//Printing the stack
void printStack(struct node *head){
    struct node *dup=head;
    while(dup!=NULL){
        printf("%d",dup->digit);
        dup=dup->next;
    }
    printf("\n");
}

//To add stacks
struct node *addStacks(struct node *s1,struct node *s2,struct node *s3){
    int carry=0;
    while(s2!=NULL && s1!=NULL){
        s1=pop(s1);
        int a=c;
        s2=pop(s2);
        int b=c;
        int l=(a+b+carry)%10;
        s3=push(s3,l);
        carry=(a+b+carry)/10;
    }
    if(s2==NULL) while(s1!=NULL){
        s1=pop(s1);
        int a=(c+carry)%10;
        s3=push(s3,a);
        carry=(c+carry)/10;
    }
    else if(s1==NULL) while(s2!=NULL){
        s2=pop(s2);
        int b=(c%10)+carry;
        s3=push(s3,b);
        carry=(c+carry)/10;
    }
    s3=push(s3,carry);
    while(s3->digit==0) s3=s3->next;
    return s3;
}

//To reverse the stacks
struct node *ReverseStack(struct node *head){
    struct node *dup=NULL;
    while(head!=NULL){
        dup=push(dup,head->digit);
        head=head->next;
    }
    return dup;
}

int main(){
    FILE *ip;

    //Opening the text doc
    ip=fopen("MULT.txt","r");
    if(ip==NULL){
        printf("NO file");
        exit(0);
    }
    stack[0]=NULL;
    stack[1]=NULL;
    char A[20],B[3];

    //reading the strings
    fscanf(ip,"%s%s",A,B);
    int n=strlen(A);
    int arr[n],ar[2],carry=0,k=0;

    //Changing the strings to integers
    for(int i=0;i<n;i++) arr[i]=A[i]-'0';
    ar[0]=B[1]-'0';
    ar[1]=B[0]-'0';

    //Performing multiplication and pushing into stacks
    while(k<2){
        for(int i=n-1;i>-1;i--){
        int mul=(arr[i]*ar[k])+carry;
        int dig=mul%10;
        stack[k]=push(stack[k],dig);
        carry=mul/10;
        }
    stack[k]=push(stack[k],carry);
    carry=0;
    k++;
    if(k==1)stack[k]=push(stack[k],carry);
    }
    printf("Stack 1 is ");
    printStack(stack[0]);
    printf("Stack 2 is ");
    printStack(stack[1]);
    stack[0]=ReverseStack(stack[0]);
    stack[1]=ReverseStack(stack[1]);

    //Adding both stacks
    stack3=addStacks(stack[0],stack[1],stack3);
    printf("Product is ");
    printStack(stack3);
}