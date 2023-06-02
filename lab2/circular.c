#include<stdio.h>
#include<stdlib.h>

struct node{
    int num;
    struct node *next;
};

void printing(struct node *head){
    if(head==NULL) printf("Empty list \n");
    else {struct node *tmp=head;
    while(tmp!=NULL) {printf("%d ",tmp->num);tmp=tmp->next;}}
}

struct node *addL(struct node *head,int n){
    struct node *tmp=head,*new=malloc(sizeof(struct node));
    new->num=n;
    new->next=NULL;
    if(tmp==NULL) head=new;
    else{
        while(tmp->next!=NULL) tmp=tmp->next;
        tmp->next=new;
    }
    return head;
}

void q3(struct node **head){
    if((*head)!=NULL){
        if((*head)->next!=NULL) (*head)= (*head)->next;
        if((*head)->next!=NULL){
            struct node *temp=(*head)->next;
            while(temp->next->next!=NULL) temp=temp->next;
            temp->next=NULL;
        }
        else (*head)=NULL;
    }
}

void fun1(struct node *head) {
    if (head == NULL) return;
    else fun1(head->next);
    printf("%d ", head->num);
}

struct node *circular(struct node *head){
    if(head!=NULL){
    struct node *temp=head;
    struct node *rear=head;
    while(temp->next->next!=NULL) temp=temp->next;
    temp->next->next=rear;
    return temp->next;}
}

void print(struct node *rear){
    struct node *temp=rear->next;
    struct node *head=rear->next;
    printf("%d ",temp->num);
    temp=temp->next;
    while(temp->next!=head->next){
    printf("%d ",temp->num);
    temp=temp->next;
    }
}

struct node *addR(struct node *rear,int data){
    struct node *new=malloc(sizeof(struct node));
    new->num=data;
    new->next=rear->next;
    rear->next=new;
    return new;
}

int main(){
    FILE *ip;
    struct node *alpha=NULL;
    ip=fopen("linking.txt","r");
    if(ip==NULL){
        printf("Error in opening linking.txt file ");
        exit(0);
    }
    fseek(ip,0,SEEK_END);
    int size = ftell(ip);
    if(size==0) {
        printf("File is empty\n");exit(0);
    }
    rewind(ip);
    int n;
    while(!feof(ip)){
        fscanf(ip,"%d",&n);
        alpha=addL(alpha,n);
    }
    printf("\nQuestion 1 Output \n");
    printing(alpha);
    //    ------------- Q2 starts -----------
    printf("\n\nQuestion 2 Output \n");
    fun1(alpha);
    //    ------------- Q3 starts -----------
    printf("\n\nQuestion 3 Output \n");
    q3(&alpha);
    printing(alpha);
    //    ------------- Q4 starts -----------
    printf("\n\nQuestion 4 Output \n");
    struct node *Calpha=circular(alpha);
    Calpha=addR(Calpha,30);
    print(Calpha);
    fclose(ip);
}