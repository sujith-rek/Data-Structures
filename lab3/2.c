#include<stdio.h>
#include<stdlib.h>

struct node{                                        //structure of stack
    char c;
    struct node *next;
};

struct node *dup=NULL;                               //stack for characters
struct node *word=NULL;                              //stack for words

struct node *push(char ch,struct node *top){         //inserting element into document
    struct node *new=malloc(sizeof(struct node));
    new->c=ch;
    new->next=top;
    top=new;
    return top;
}

void write(struct node *top){                       //printing the document
    struct node *temp=NULL;
    struct node *mov=top;
    while(mov!=NULL && (mov->c)!='%'){
        temp=push(mov->c,temp);
        mov=mov->next;
    }
    while(temp!=NULL){
        if((temp->c)=='%') printf("\n");
        else if((temp->c)=='^') printf(" ");
        else printf("%c",temp->c);
        temp=temp->next;
    }
    printf("\n");
}

struct node *undoL(struct node *top){              //Un-doing a character
    struct node *temp=top;
    dup=push(temp->c,dup);
    top=top->next;
    free(temp);
    return top;
}

struct node *undoW(struct node *top){              //Un-doing a word
    struct node *temp=top;
    word=push('$',word);
    while((temp->c)!='^'){
        temp=temp->next;
            struct node *tem=top;
            word=push(tem->c,word);
            top=top->next;
            free(tem);
        if((temp->c)=='^'){
            temp=temp->next;
            struct node *tem=top;
            word=push(tem->c,word);
            top=top->next;
            free(tem);
            break;
        }
    }
    return top;
}

struct node *redoL(struct node *top){              //re-doing a character
    struct node *temp=dup;
    top=push(temp->c,top);
    dup=dup->next;
    free(temp);
    return top;
}

struct node *redoW(struct node *top){              //re-doing a word
    struct node *temp=word;
            top=push(temp->c,top);
            temp=temp->next;
            word=word->next;
        while((temp->c)!='$'){
            temp=temp->next;
            struct node *tem=word;
            top=push(tem->c,top);
            word=word->next;
            free(tem);
            if((temp->c)=='$'){
                    temp=temp->next;
                    struct node *tem=word;
                    word=word->next;
                    free(tem);
                    break;
            }
        }
        return top;
}

int main(){
    FILE *ip;
    ip=fopen("editor.txt","r");
    if(ip==NULL){
        printf("Editor file is missing");
        exit(0);
    }
    struct node *doc=NULL;
    int i;
    char ch;
    while(1){
        fscanf(ip,"%d",&i);
        if(i==1){
            ch=60;
            while(ch>57 || ch<49){
            fscanf(ip,"%s",&ch);
                if(ch<57 && ch>49) i=ch-48;
                else doc=push(ch,doc);
            };
        }
        if(i==2) doc=undoL(doc);
        if(i==3) doc=redoL(doc);
        if(i==4) doc=undoW(doc);
        if(i==5) doc=redoW(doc);
        if(i==6) write(doc);
        if(i==7) doc=push('%',doc);
        if(i==8) exit(0);
    }
}