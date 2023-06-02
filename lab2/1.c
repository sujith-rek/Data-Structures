#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*Date,group leader name,no.of people in group*/

int size,dt,opt;

struct list{
    int date;
    struct Node *inf;
    struct list *next;
};

struct Node{
    int count;
    char **name;
    struct Node *NEXT;
};
struct list *TS1=NULL,*TS2=NULL,*TS3=NULL;

void printList(struct list *ptr,int tour){
    struct list *tmp=malloc(sizeof(struct list));tmp=ptr;
    while(tmp!=NULL){
    printf("-----------------------------------------------\n");
    printf(" May : %d //",tmp->date);
    struct Node *temp=malloc(sizeof(struct Node));temp=tmp->inf;
        while(temp!=NULL){
            printf("%d %s",temp->count,temp->name);
            temp=temp->NEXT;
        }
        tmp=tmp->next;
    //free(tmp);
    }}

void addDate(int dat,struct list *ptr){
    struct list *new=malloc(sizeof(struct list)),*prev=ptr;
    new->date=dat;
    new->inf=NULL;
    new->next=NULL;
    if (ptr==NULL) ptr=new;
    else{
    while (prev!=NULL) {
      prev=prev->next;
    }
     prev=new;
  }//printList(ptr,1);
  //free(prev);
  return;
}

void addName(char **ln,int total,struct list *ptr,int pos,int da){
    struct Node *new=malloc(sizeof(struct Node)),*n,*m;
    struct list *temp=ptr;
    new->name=ln;
    new->count=total;
    new->NEXT=NULL;
    printf("LOL1");
    if(ptr->date==da){
        if(ptr->inf==NULL){
            ptr->inf=new;
            printf("\nLOL2");
        }else{
            m=ptr->inf;
            while(m->NEXT!=NULL) m=m->NEXT;
            m->NEXT=new;printf("\nLOL3");
        }
    }else{
        while(temp->date!=da && temp!=NULL) temp=temp->next;
        if(temp->inf==NULL){
            temp->inf=new;
            printf("\nLOL4");
        }else{
            n=temp->inf;
            while(n->NEXT!=NULL) n=n->NEXT;
            n->NEXT=new;printf("\nLOL5");
        }
    }

}

void delNode(char *an,struct list *ptr,int op){
    return;
}

int peopleSum(){
    return 0;
}

int main(){
    FILE *ip = NULL;
    char l[1000],tm[1000],an[1000];
    char *ln[100];int i=1,total=0;
    ip=fopen("tour.txt","r");
    if(ip==NULL){
        printf("tour.txt file doesn't exists");
        exit(0);
    }
    fscanf(ip,"%d",&size);
    while(1){
    fscanf(ip,"%s",l);
    printf("-->%s<--\n",l);
    if(strcmp(l,"C1")==0){
        fscanf(ip,"%s",tm);
        if(strcmp(tm,"TS1")==0) opt=1;//Update the pointer to TS1
        if(strcmp(tm,"TS2")==0) opt=2;//Update the pointer to TS2
        if(strcmp(tm,"TS3")==0) opt=3;//Update the pointer to TS3
        printf("tourist destination %s\n",tm);
    }        printf("LOLLMAO");

    if(strcmp(l,"C2")==0){
        fscanf(ip,"%d",&dt);
        if(opt==1) addDate(dt,TS1);
        if(opt==2) addDate(dt,TS2);
        if(opt==3) addDate(dt,TS3);
        //Read integer as date
    }
            printf("LOL");
    if(strcmp(l,"C3")==0){
        printf("Enter");
        fscanf(ip,"%s",&ln[i]);printf("%s",ln[i]);
        fscanf(ip,"%d",&total);printf("%d",total);
        printf("\nLOL10");
        printf("LOL");
        if(opt==1) addName(&ln[i],total,TS1,2,dt);
        if(opt==2) addName(&ln[i],total,TS2,2,dt);
        if(opt==3) addName(&ln[i],total,TS3,2,dt);
        i++;
        // Read group leader name and then total people in group
    }
    if(strcmp(l,"C3A")==0){
        fscanf(ip,"%s",&ln[i]);
        fscanf(ip,"%d",&total);
        if(opt==1) addName(&ln[i],total,TS1,1,dt);
        if(opt==2) addName(&ln[i],total,TS2,1,dt);
        if(opt==3) addName(&ln[i],total,TS3,1,dt);
        i++;
        // VIP Grup leader and members
    }
    if(strcmp(l,"C5")==0){
        fscanf(ip,"%s",an);///////////////////////////////////////////////// tm or ln make sure to check out
        if(opt==1) delNode(an,TS1,1);
        if(opt==2) delNode(an,TS2,1);
        if(opt==3) delNode(an,TS3,1);
        // Read group leader name and delete them from list
    }
    if(strcmp(l,"C8")==0){
        fscanf(ip,"%s",tm);
        // Read spot code and print Date total people group leaders names
        if(strcmp(tm,"TS1")==0) printList(TS1,1);
        if(strcmp(tm,"TS2")==0) printList(TS2,2);
        if(strcmp(tm,"TS3")==0) printList(TS3,3);
    }
    if(strcmp(l,"C9")==0) exit(0);
    }
    fclose(ip);
}