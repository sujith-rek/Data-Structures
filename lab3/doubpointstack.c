#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void push(int val,struct node **top){
    struct node *new=malloc(sizeof(struct node));
    new->data=val;
    new->next=(*top);
    *top=new;
    printf("%d is pushed\n",val);
}

void pop(struct node **top){
    struct node *temp = *top;
    *top=(*top)->next;
    printf("%d is popped \n",temp->data);
    free(temp);
}

void display(struct node *top){
    struct node *temp=top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void peek(struct node **top){
    printf("Top value is %d\n",(*top)->data);
}

int main(){
    struct node *top=NULL;
    push(5,&top);
    push(6,&top);
    push(4,&top);
    push(9,&top);
    push(3,&top);
    display(top);
    pop(&top);
    display(top);
    pop(&top);
    display(top);
    push(8,&top);
    display(top);
    peek(&top);
    display(top);
}