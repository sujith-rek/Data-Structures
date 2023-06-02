/*
                                                        LAB-3 STACKS EDITOR
                                                        P.Soma sujith
                                                        2110110400
                                                        Entry - 1
                                                        Lab group - P3
         “I certify that this is my own work and I have not copied any part of it from other sources. I have not shared my code with any other student”
                                                        PHASES-1,2,3
*/

#include<stdio.h>
#include<stdlib.h>

struct node{                                        //structure of stack
    char c;
    struct node *next;
};

struct node *dup=NULL;                               //stack for characters
struct node *word=NULL;                              //stack for words

//inserting element into document
struct node *push(char ch,struct node *top){
    struct node *new=malloc(sizeof(struct node));
    new->c=ch;
    new->next=top;
    top=new;
    return top;
}

//printing the document
void write(struct node *top){
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

//Un-doing a character
struct node *undoL(struct node *top){
    struct node *temp=top;
    if(temp->c!='%'){
        dup=push(temp->c,dup);
        top=top->next;
        free(temp);
        return top;}
    else{
        printf("End of File to do operations ");
        exit(0);
    }
}

//Un-doing a word
struct node *undoW(struct node *top){
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

//re-doing a character
struct node *redoL(struct node *top){
    struct node *temp=dup;
    top=push(temp->c,top);
    dup=dup->next;
    free(temp);
    return top;
}

//re-doing a word
struct node *redoW(struct node *top){
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

    //Opening editor.txt file
    ip=fopen("editor.txt","r");
    if(ip==NULL){
        printf("Editor file is missing");
        exit(0);
    }

    //Main document stack
    struct node *doc=NULL;
    int i;
    char ch;
    while(1){

        //Reading option
        fscanf(ip,"%d",&i);

        //Read character
        if(i==1){
            ch=60;
            while(ch>57 || ch<49){
            fscanf(ip,"%s",&ch);
                if(ch<57 && ch>49) i=ch-48;
                else doc=push(ch,doc);
            };
        }

        //Undo letter
        if(i==2) doc=undoL(doc);

        //Redo letter
        if(i==3) doc=redoL(doc);

        //Undo word
        if(i==4) doc=undoW(doc);

        //Redo word
        if(i==5) doc=redoW(doc);

        //Print contents of document
        if(i==6) write(doc);

        //new line or document
        if(i==7) doc=push('%',doc);

        //exit
        if(i==8) exit(0);
    }
}