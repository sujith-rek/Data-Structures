#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *PushSP(int val,struct node *top){
    struct node *new=malloc(sizeof(struct node));
    new->data=val;
    new->next=(top);
    top=new;
    printf("%d is pushed\n",val);
    return top;
}

struct node *PopSP(struct node *top){
    struct node *temp = top;
    top=top->next;
    printf("%d is popped \n",temp->data);
    free(temp);
    return top;
}

void display(struct node *top){
    struct node *temp=top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    struct node *stackAA=NULL;
    stackAA=PushSP(25,stackAA);
    stackAA=PushSP(34,stackAA);
    stackAA=PushSP(5,stackAA);
    stackAA=PushSP(6,stackAA);
    display(stackAA);
    stackAA=PopSP(stackAA);
    display(stackAA);
}