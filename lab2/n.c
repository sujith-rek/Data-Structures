// ASSIGNMENT 2 ~ LAB 2
// P.SOMA SUJITH
// 2110110400
// P3
//                                        ~~~~~ COMPLETE PROGRAM ~~~~~
//         “I certify that this is my own work and I have not copied any part of it from other sources.”
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    char **name;
    int date;
    int tourist;
    char *destination;
    struct node *next;
};
struct node *TS1[100];
int countTS1 = 0;
struct node *TS2[100];
int countTS2 = 0;
struct node *TS3[100];
int countTS3 = 0;
int nameCount = 0;
char *name[1000];

FILE *tour;
/* Functions for Calculating Number of tourists , inserting at top and bottom and deleting at bottom starts here */
void deleteAtBottomForTS1(int count){
    if (TS1[0] == NULL) return;
    struct node *temp = TS1[0];
    while (temp->next->next != NULL) temp = temp->next;
    struct node *toDelete = temp->next;
    temp->next = NULL;
    free(toDelete);
    return;
}
int calculateTotalTouristsForTS1(int count,int dat){
    if (TS1[0] == NULL) return 0;
    else{
        struct node *temp = TS1[0];
        int sum = 0;
        while (temp != NULL){
            if(temp->date == dat){
            int t = temp->tourist;
            sum += t;}
            temp = temp->next;
        }
        return sum;
    }
}
void insertAtBottomForTS1(int count, char **leader, int dt, int ts, char *dest){
    struct node *new = malloc(sizeof(struct node));
    new->name = leader;
    new->date = dt;
    new->tourist = ts;
    new->destination = dest;
    new->next = NULL;
    if (TS1[0] == NULL)  TS1[0] = new;
    else{
        struct node *temp = TS1[0];
        while (temp->next != NULL) temp = temp->next;
        temp->next = new;
    }
}
void insertAtTopforTS1(int count, char **leader, int dt, int ts, char *dest){
    struct node *new = malloc(sizeof(struct node));
    new->name = leader;
    new->date = dt;
    new->tourist = ts;
    new->destination = dest;
    new->next = NULL;
    if (TS1[0] == NULL) TS1[0] = new;
    else{
        new->next = TS1[0];
        TS1[0] = new;
    }
}
void deleteforTS1(char *name){
        if (strcmp((char *)(TS1[0]->name), name) == 0){
            struct node *toDelete = TS1[0];
            TS1[0] = TS1[0]->next;
            free(toDelete);
        }else{
            struct node *temp = TS1[0];
            while (strcmp((char *)(temp->next->name), name) != 0)   temp = temp->next;
            struct node *todelete = temp->next;
            temp->next = temp->next->next;
            free(todelete);
        }
    }
void deleteAtBottomForTS2(int count){
    if (TS2[0] == NULL)       return;
    struct node *temp = TS2[0];
    while (temp->next->next != NULL) temp = temp->next;
    struct node *toDelete = temp->next;
    temp->next = NULL;
    free(toDelete);
}
int calculateTotalTouristsForTS2(int count,int dat){
    if (TS2[0] == NULL) return 0;
    else{
        struct node *temp = TS2[0];
        int sum = 0;
        while (temp != NULL){
            if(temp->date==dat){
            int t = temp->tourist;
            sum += t;}
            temp = temp->next;
        }
        return sum;
    }
}
void insertAtBottomForTS2(int count, char **leader, int dt, int ts, char *dest){
    struct node *new = malloc(sizeof(struct node));
    new->name = leader;
    new->date = dt;
    new->tourist = ts;
    new->destination = dest;
    new->next = NULL;
    if (TS2[0] == NULL) TS2[0] = new;
    else{
        struct node *temp = TS2[0];
        while (temp->next != NULL) temp = temp->next;
        temp->next = new;
    }
}
void insertAtTopforTS2(int count, char **leader, int dt, int ts, char *dest){
    struct node *new = malloc(sizeof(struct node));
    new->name = leader;
    new->date = dt;
    new->tourist = ts;
    new->destination = dest;
    new->next = NULL;
    if (TS2[0] == NULL)TS2[0] = new;
    else{
        new->next = TS2[0];
        TS2[0] = new;
    }
}
void deleteforTS2(char *name){
        if (strcmp((char *)(TS2[0]->name), name) == 0){
            struct node *toDelete = TS1[0];
            TS2[0] = TS2[0]->next;
            free(toDelete);
        }
        else{
            struct node *temp = TS2[0];
            while (strcmp((char *)(temp->next->name), name) != 0) temp = temp->next;
            struct node *todelete = temp->next;
            temp->next = temp->next->next;
            free(todelete);
        }
    }
void deleteAtBottomForTS3(int count){
    if (TS3[0] == NULL) return;
    struct node *temp = TS3[0];
    while (temp->next->next != NULL) temp = temp->next;
    struct node *toDelete = temp->next;
    temp->next = NULL;
    free(toDelete);
}
int calculateTotalTouristsForTS3(int count,int dat){
    if (TS3[0] == NULL)   return 0;
    else{
        struct node *temp = TS3[0];
        int sum = 0;
        while (temp != NULL){
            if(temp->date == dat){
            int t = temp->tourist;
            sum += t;}
            temp = temp->next;
        }
        return sum;
    }
}
void insertAtBottomForTS3(int count, char **leader, int dt, int ts, char *dest){
    struct node *new = malloc(sizeof(struct node));
    new->name = leader;
    new->date = dt;
    new->tourist = ts;
    new->destination = dest;
    new->next = NULL;
    if (TS3[0] == NULL)    TS3[0] = new;
    else{
        struct node *temp = TS3[0];
        while (temp->next != NULL)  temp = temp->next;
        temp->next = new;
    }
}
void insertAtTopforTS3(int count, char **leader, int dt, int ts, char *dest){
    struct node *new = malloc(sizeof(struct node));
    new->name = leader;
    new->date = dt;
    new->tourist = ts;
    new->destination = dest;
    new->next = NULL;
    if (TS3[0] == NULL) TS3[0] = new;
    else{
        new->next = TS3[0];
        TS3[0] = new;
    }
}
void deleteforTS3(char *name){
        if (strcmp((char *)(TS3[0]->name), name) == 0){
            struct node *toDelete = TS3[0];
            TS3[0] = TS3[0]->next;
            free(toDelete);
        }else {
            struct node *temp = TS3[0];
            while (strcmp((char *)(temp->next->name), name) != 0) temp = temp->next;
            struct node *todelete = temp->next;
            temp->next = temp->next->next;
            free(todelete);
        }
    }

/* Functions for Calculating Number of tourists , inserting at top and bottom and deleting at bottom ends here */
void deletesearch(char *name){
    for (int i = 0; i <= countTS3; i++){
        if (strcmp((char *)(TS3[i]->name), name) == 0){
            struct node *toDelete = TS3[i];
            TS3[i] = TS3[i]->next;
            free(toDelete);
            return;
        }else{
            struct node *temp = TS3[i];
            while (strcmp((char *)(temp->next->name), name) != 0)  temp = temp->next;
            struct node *todelete = temp->next;
            temp->next = temp->next->next;
            free(todelete);
            return;
        }
    }
    for (int i = 0; i <= countTS2; i++){
        if (strcmp((char *)(TS2[i]->name), name) == 0){
            struct node *toDelete = TS2[i];
            TS2[i] = TS2[i]->next;
            free(toDelete);
            return;
        }else{
            struct node *temp = TS2[i];
            while (strcmp((char *)(temp->next->name), name) != 0)  temp = temp->next;
            struct node *todelete = temp->next;
            temp->next = temp->next->next;
            free(todelete);
            return;
        }
    }
    for (int i = 0; i <= countTS1; i++){
        if (strcmp((char *)(TS1[i]->name), name) == 0){
            struct node *toDelete = TS1[i];
            TS1[i] = TS1[i]->next;
            free(toDelete);
            return;
        }else{
            struct node *temp = TS1[i];
            while (strcmp((char *)(temp->next->name), name) != 0)  temp = temp->next;
            struct node *todelete = temp->next;
            temp->next = temp->next->next;
            free(todelete);
            return;
        }
    }
}

/* Display Functions for TS1, TS2 and TS3 starts here*/
void displayForTS1(){
    printf("\n");
    printf("Group destination = Darjeeling");
        struct node *temp = TS1[0];
        printf("\n");int d=temp->date;
        printf("Number of tourists for may %d is %d \n\n",temp->date,calculateTotalTouristsForTS1(1,temp->date));
        while (temp!= NULL){
            if(d!=temp->date){  printf("\nNumber of tourists for may %d is %d \n\n",temp->date,calculateTotalTouristsForTS1(1,temp->date));d=temp->date;}
            printf("May %d : ", temp->date);
            printf("%s ", temp->name);
            printf("Group tourists = %d\n", temp->tourist);
            temp = temp->next;
        }
            printf("-------------------------------------\n");

}
void displayForTS2(){
    printf("\n");
    printf("Group destination = Leh");
        struct node *temp = TS2[0];
        printf("\n");int d=temp->date;
        printf("Number of tourists for may %d is %d \n\n",temp->date,calculateTotalTouristsForTS2(1,temp->date));
        while (temp!= NULL){
            if(d!=temp->date){  printf("\nNumber of tourists for may %d is %d \n\n",temp->date,calculateTotalTouristsForTS1(1,temp->date));d=temp->date;}
            printf("May %d : ", temp->date);
            printf("%s ", temp->name);
            printf("Group tourists = %d\n", temp->tourist);
            temp = temp->next;
    }
        printf("-------------------------------------\n");

}
void displayForTS3(){
    printf("\n");
    printf("Group destination = Ooty");
        struct node *temp = TS3[0];
        printf("\n");int d=temp->date;
        printf("Number of tourists for may %d is %d \n\n",temp->date,calculateTotalTouristsForTS3(1,temp->date));
        while (temp!= NULL){
            if(d!=temp->date){  printf("\nNumber of tourists for may %d is %d \n\n",temp->date,calculateTotalTouristsForTS1(1,temp->date));d=temp->date;}
            printf("May %d : ", temp->date);
            printf("%s ", temp->name);
            printf("Group tourists = %d\n", temp->tourist);
            temp = temp->next;
    }
    printf("-------------------------------------\n");
}
/* Display Functions for TS1, TS2 and TS3 ends here*/
void c8Handler(){
    char code[1000];int k=1;
    fscanf(tour, "%s", code);
    if (strcmp(code, "TS1") == 0) {k=0;displayForTS1();}
    if (strcmp(code, "TS2") == 0) {k=0;displayForTS2();}
    if (strcmp(code, "TS3") == 0) {k=0;displayForTS3();}
    if(k==1) printf("\n\nThe list to print isn't available as code %s is not in tour list\n\n",code);
}
void c5Handler(char *location){
    char code[1000];int k=1;
    fscanf(tour, "%s", code);
    if (strcmp(location, "Darjeeling") == 0) {deleteforTS1(code);k=0;}
    if (strcmp(location, "Leh") == 0) {deleteforTS2(code);k=0;}
    if (strcmp(location, "Ooty") == 0) {deleteforTS3(code);k=0;}
    if(k!=0) printf("\n\nName to be deleted isn't in the list \n\n");
}
void c3aHandler(int date, char *location, int n){
    fscanf(tour, "%s", &name[nameCount]);
    int num,cod=1;
    fscanf(tour, "%d", &num);
    if (strcmp(location, "Darjeeling") == 0){
            insertAtTopforTS1(countTS1, &name[nameCount], date, num, location);
            int number = calculateTotalTouristsForTS1(countTS1,date);
            if (number > n) deleteAtBottomForTS1(countTS1);
            countTS1++;cod=0;
    }
    if (strcmp(location, "Leh") == 0){
            insertAtTopforTS2(countTS2, &name[nameCount], date, num, location);
            int number = calculateTotalTouristsForTS2(countTS2,date);
            if (number > n) deleteAtBottomForTS2(countTS2);
            countTS2++;cod=0;
    }
    if (strcmp(location, "Ooty") == 0){
            insertAtTopforTS3(countTS2, &name[nameCount], date, num, location);
            int number = calculateTotalTouristsForTS3(countTS3,date);
            if (number > n)  deleteAtBottomForTS3(countTS3);
        countTS3++;cod=0;
    }
        nameCount++;
    if(cod==1) printf("\n\nError while handling C3A because of wrong input format\n check tour.txt file \n\n");
}
void c3Handler(int date, char *location, int n){
    fscanf(tour, "%s", &name[nameCount]);
    int num,cod=1;
    fscanf(tour, "%d", &num);
    if (strcmp(location, "Darjeeling") == 0){
            insertAtBottomForTS1(countTS1, &name[nameCount], date, num, location);
            int number = calculateTotalTouristsForTS1(countTS1,date);
            if (number > n) deleteAtBottomForTS1(countTS1);
            countTS1++;cod=0;
    }
    if (strcmp(location, "Leh") == 0){
            insertAtBottomForTS2(countTS2, &name[nameCount], date, num, location);
            int number = calculateTotalTouristsForTS2(countTS2,date);
            if (number > n)  deleteAtBottomForTS2(countTS2);
            countTS2++;cod=0;
    }
    if (strcmp(location, "Ooty") == 0){
            insertAtBottomForTS3(countTS3, &name[nameCount], date, num, location);
            int number = calculateTotalTouristsForTS3(countTS3,date);
            if (number > n)  deleteAtBottomForTS3(countTS3);
            countTS3++;cod=0;
    }
    nameCount++;
        if(cod==1) printf("\n\nError while handling C3 because of wrong input format\n check tour.txt file \n\n");
}
int c2Handler(char *location){
    int date;
    fscanf(tour, "%d", &date);
    if(date>31) printf("\n\nIllegal date, May has only 31 days\n\n");
    return date;
}

char *c1Handler(){
    int oCode=1;
    char code[1000];
    fscanf(tour, "%s", code);
    if (strcmp(code, "TS1") == 0) {oCode=0;return "Darjeeling";}
    if (strcmp(code, "TS2") == 0) {oCode=0;return "Leh";}
    if (strcmp(code, "TS3") == 0) {oCode=0;return "Ooty";}
    if(oCode==1) printf("\n\nThere's no spot code as %s \n\n",code);
}
void codeHandler(int n){
    char code[1000];
    while (1){
        int opCode=1;
        char *location;
        int date;
        fscanf(tour, "%s", code);
        if (strcmp(code, "C1") == 0)  {location = c1Handler();opCode=0;}
        if (strcmp(code, "C2") == 0)  {date = c2Handler(location);opCode=0;}
        if (strcmp(code, "C3") == 0)  {if(date>25) continue;c3Handler(date, location, n);opCode=0;}
        if (strcmp(code, "C3A") == 0)  {if(date>25) continue;c3aHandler(date, location, n);opCode=0;}
        if (strcmp(code, "C5") == 0)  {c5Handler(location);opCode=0;}
        if (strcmp(code, "C8") == 0)  {c8Handler();opCode=0;}
        if (strcmp(code, "C9") == 0)  exit(0);
        if(opCode!=0) {printf("\n\nWrong usage of primary codes \n");
            printf("This code -> %s <- isn't specified in the program  \n\n",code);
        }
    }
}
int main(){
    TS1[0] = NULL;TS2[0] = NULL;TS3[0] = NULL;
    tour = fopen("tour.txt", "r");
    if(tour==NULL){
        printf("Error in opening tour.txt file");
        exit(0);
    }
    int numberOfTourists;
    fscanf(tour, "%d", &numberOfTourists);
    printf("Number of Tourists allowed = %d\n", numberOfTourists);
    codeHandler(numberOfTourists);
    fclose(tour);
    exit(0);
}
/*
SAMPLE INPUT FILE I USED:
12
C1 TS1 C2 14 C3 AA 2 C3 BB 3 C2 17 C3 CC 4 C8 TS1 C10
C1 TS2 C2 15 C3 QQ 3 C3 WW 4 C5 QQ C8 TS2 C11
C1 TS3 C2 20 C3 EE 4 C3 RR 5 C8 TS3 C9

Output
Number of Tourists allowed = 12

Group destination = Darjeeling

Number of tourists for may 14 is 5

May 14 : AA Group tourists = 2
May 14 : BB Group tourists = 3

Number of tourists for may 17 is 4

May 17 : CC Group tourists = 4
-------------------------------------

Wrong usage of primary codes
This code -> C10 <- isn't specified in the program

Group destination = Leh
Number of tourists for may 15 is 4

May 15 : WW Group tourists = 4
-------------------------------------

Wrong usage of primary codes
This code -> C11 <- isn't specified in the program

Group destination = Ooty
Number of tourists for may 20 is 9

May 20 : EE Group tourists = 4
May 20 : RR Group tourists = 5
*/