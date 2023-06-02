#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *tour;
struct node{
    char **name;
    int date;
    int tourist;
    int destination;
    struct node *next;
};

struct node *TS1 = NULL,*TS2=NULL,*TS3=NULL;

struct node *insertAtTop(struct node *head, char **leader, int dt, int ts, int dest){
    struct node *new = malloc(sizeof(struct node));
    new->name = leader;
    new->date = dt;
    new->tourist = ts;
    new->destination = dest;
    new->next = NULL;
    if (head == NULL){
        head = new;
        return head;
    }else{
        new->next = head;
        head = new;
        return head;
    }
}

struct node *insertAtBottom(struct node *head, char **leader, int dt, int ts, int dest){
    struct node *new = malloc(sizeof(struct node));
    new->name = leader;
    new->date = dt;
    new->tourist = ts;
    new->destination = dest;
    new->next = NULL;
    if (head == NULL){
        head = new;
        return head;
    }else{
        struct node *temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
        return head;
    }
}

void deleteAtBottom(struct node *head){
    if (head == NULL) return;
    struct node *temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    struct node *toDelete = temp->next;
    temp->next = NULL;
    free(toDelete);
}

int calculateTotalTourists(struct node *head,int k){
    if (head == NULL){
        return 0;
    }else{
        struct node *temp = head;
        int sum = 0;
        while (temp != NULL ){
            if(k==temp->date){
            int t = temp->tourist;
            sum += t;}
            temp = temp->next;
        }
        return sum;
    }
}
void display(struct node *head){
    struct node *tem=malloc(sizeof(struct node));tem=head;
    printf("\n");
    switch(tem->destination){
        case 1:printf("Group destination = Darjeeling\n");break;
        case 2:printf("Group destination = Leh\n");break;
        case 3:printf("Group destination = Ooty\n");break;
    }
    while (tem != NULL){
        printf("May %d : %d tourists : ", tem->date, tem->tourist);
        printf(" ->  %s  <- ", tem->name);
        printf("\n");
        tem = tem->next;
    }
    printf("\n");
}

void delet(struct node *head, char *name){
    if (strcmp((char*)(head->name),name) == 0){
        struct node *toDelete = head;
        head = head->next;
        free(toDelete);
    }else{
        struct node *temp = malloc(sizeof(struct node));temp=head;
        while (strcmp((char*)(temp->next->name) , name) != 0)temp  = temp->next;
        struct node *todelete = temp->next;
        temp->next = temp->next->next;
        free(todelete);
    }
}

int c2Handler(){
    int date;
    fscanf(tour, "%d", &date);
    return date;
}

int c1Handler(){
    char code[1000];
    fscanf(tour, "%s", code);
    if (strcmp(code, "TS1") == 0) return 1;
    if (strcmp(code, "TS2") == 0) return 2;
    if (strcmp(code, "TS3") == 0) return 3;
}

void c5Handler(int location){
    char code[1000];
    fscanf(tour, "%s", code);
    if (location == 1)        delet(TS1, code);
    if (location == 2)        delet(TS2, code);
    if (location == 3)        delet(TS3, code);
}

void c8Handler(){
    char code[1000];
    fscanf(tour, "%s", code);
    if (strcmp(code, "TS1") == 0) display(TS1);
    if (strcmp(code, "TS2") == 0) display(TS2);
    if (strcmp(code, "TS3") == 0) display(TS3);
}

int main(){
    tour = fopen("tour.txt", "r");
    char *nam[1000];
    int numberOfTourists,n,i=0,location,date;
    fscanf(tour, "%d", &numberOfTourists);
    n=numberOfTourists;
    printf("Number of Tourists allowed = %d\n", numberOfTourists);
    char code[1000];
    while (1){
        fscanf(tour, "%s", code);
        if (strcmp(code, "C1") == 0) location = c1Handler();
        if (strcmp(code, "C2") == 0) date = c2Handler(location);
        if (strcmp(code, "C3") == 0){
            fscanf(tour, "%s", &nam[i]);
            int num;
            fscanf(tour, "%d", &num);
            if(date>25) continue;
            if (location == 1){
                TS1 = insertAtBottom(TS1, &nam[i], date, num, location);
                int number = calculateTotalTourists(TS1,date);
                if (number > n) deleteAtBottom(TS1);
            }
            if (location == 2){
                TS2 = insertAtBottom(TS2, &nam[i], date, num, location);
                int number = calculateTotalTourists(TS2,date);
                if (number > n) deleteAtBottom(TS2);
            }
            if (location == 3){
                TS3 = insertAtBottom(TS3, &nam[i], date, num, location);
                int number = calculateTotalTourists(TS3,date);
                if (number > n) deleteAtBottom(TS3);
            }
            i++;
    }
        if (strcmp(code, "C3A") == 0){
            fscanf(tour, "%s", &nam[i]);
            int num;
            fscanf(tour, "%d", &num);
            if(date>25) continue;
            if (location == 1){
                TS1 = insertAtTop(TS1, &nam[i], date, num, location);
                int number = calculateTotalTourists(TS1,date);
                if (number > n) deleteAtBottom(TS1);
            }
            if (location == 2){
                TS2 = insertAtTop(TS2, &nam[i], date, num, location);
                int number = calculateTotalTourists(TS2,date);
                if (number > n)deleteAtBottom(TS2);
            }
            if (location == 3){
                TS3 = insertAtTop(TS3, &nam[i], date, num, location);
                int number = calculateTotalTourists(TS3,date);
                if (number > n) deleteAtBottom(TS3);
            }
            i++;
        }
        if (strcmp(code, "C5") == 0) {c5Handler(location);}
        if (strcmp(code, "C8") == 0) c8Handler();
        if (strcmp(code, "C9") == 0) exit(0);
        i++;
    }
    exit(0);
}