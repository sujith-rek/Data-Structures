#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a>b?a:b)

//Node of a vertex list
struct node{
    int weight;
    struct vertex *link;
    struct node *next;
};

//Vertex of a graph
struct vertex{
    int stat;
    int num;
    struct node *list;
};

//Stack for DFS
struct stack{
    struct vertex *vert;
    struct stack *down;
};

//Queue for BFS
struct queue{
    struct vertex *ver;
    struct queue *back;
};

int arr[100][3],n=0,size=0,cost=0,matrix[100][100];
struct vertex *graph[50];

//Push function to add Vertex to stacks for DFS
struct stack *push(struct stack *head,struct vertex *add){
    struct stack *new=malloc(sizeof(struct stack));
    new->vert=add;
    new->down=head;
    head=new;
    return new;
}

//For popping vertex out of stack in DFS
struct stack *pop(struct stack *head){
    struct stack *temp=head;
    head=head->down;
    free(temp);
    return head;
}

//For popping Un-visited vertex and pushing linked vertices for DFS
struct stack *popVertex(struct stack *head){
    if(head->vert->stat==0){
        printf("%d ",head->vert->num);
        struct stack *root=NULL;
        struct node *temp=head->vert->list;
        while(temp!=NULL) {root=push(root,temp->link);temp=temp->next;}
        head->vert->stat=1;
        head=pop(head);
        while(root!=NULL){
            head=push(head,root->vert);
            root=root->down;
        }
    }
    else head=pop(head);
    return head;
}

//Enqueing a vertex for BFS
struct queue *enqueue(struct queue *head,struct vertex *add){
    struct queue *new=malloc(sizeof(struct queue));
    new->ver=add;
    new->back=NULL;
    if(head==NULL) head=new;
    else{
        struct queue *temp=head;
        while(temp->back!=NULL) temp=temp->back;
        temp->back=new;
    }
    return head;
}

//For Dequeing Vertex for BFS
struct queue *dequeue(struct queue *head){
    struct queue *temp=head;
    head=head->back;
    free(temp);
    return head;
}

//Dequeing vertex and enqueing vertices linked to that vertex
struct queue *dequeueVertex(struct queue *head){
    if(head->ver->stat==0){
        printf("%d ",head->ver->num);
        struct node *temp=head->ver->list;
        while(temp!=NULL){
            head=enqueue(head,temp->link);
            temp=temp->next;
        }
        head->ver->stat=1;
        head=dequeue(head);
    }
    else head=dequeue(head);
    return head;
}

//Depth First Search of the graph
void DFS(){
    struct stack *head=NULL;
    head=push(head,graph[1]);
    while(head!=NULL) head=popVertex(head);
}

//Breadth First Search of the graph
void BFS(){
    struct queue *head=NULL;
    head=enqueue(head,graph[1]);
    while(head!=NULL) head=dequeueVertex(head);
}

//To reset the visit status baack to 0
void reset(){
    for(int i=1;i<size;i++) graph[i]->stat=0;
}

//Matrix representation of graph
void matrixGraph(){
    FILE *out;
    out=fopen("gr.txt","w");
    if(out==NULL){
        printf("The data file gr.txt doesn't exist ");
        exit(0);}
    for(int i=0;i<n;i++) size=max(max(arr[i][0],size),max(arr[i][1],size));
    size++;

    //Marking all elements to 0
    for(int i=0;i<size;i++) for(int j=0;j<size;j++){
        if(i==0) matrix[i][j]=j;
        else if(j==0) matrix[i][j]=i;
        else matrix[i][j]=0;
    }

    //Giving the weights to edges
    for(int i=0;i<n;i++){
        matrix[arr[i][0]][arr[i][1]]=arr[i][2];
        matrix[arr[i][1]][arr[i][0]]=arr[i][2];
    }

    //finding the cost of graph
    for(int i=0;i<size;i++) for(int j=0;j<i;j++)   if(i!=0 && j!=0)cost=cost+matrix[i][j];
    fprintf(out,"Cost of graph is %d\n",cost);
    for(int i=0;i<size;i++){
        fprintf(out,"\n");
        for(int j=0;j<size;j++)  fprintf(out,"%3d ",matrix[i][j]);
    }
    fclose(out);
}

//Function to create a vertex
struct vertex *getNode(int i){
    struct vertex *new=malloc(sizeof(struct vertex));
    new->num=i;
    new->stat=0;
    new->list=NULL;
    return new;
}

//Adding node to vertex
void addNode(int a,int b,int weigh){
    struct node *new=malloc(sizeof(struct node));
    new->link=graph[b];
    new->weight=weigh;
    new->next=NULL;
    struct node *temp=graph[a]->list;
    if(temp==NULL) graph[a]->list=new;
    else{
        while(temp->next!=NULL) temp=temp->next;
        temp->next=new;
    }
}

//Printing the linked list graph
void printGraph(){
    for(int i=1;i<size;i++){
        printf("(%d)",i);
        struct node *temp=graph[i]->list;
        while(temp!=NULL){
        printf(" --> ");
        printf("(%2d,%2d)",temp->link->num,temp->weight);
        temp=temp->next;
        }
        printf("\n");
    }
}

//Create and print linked list graph
void linkedListGraph(){
    for(int i=0;i<size;i++) graph[i]=NULL;
    for(int i=1;i<size;i++) graph[i]=getNode(i);
    for(int i=1;i<size;i++)  for(int j=1;j<size;j++)  if(matrix[i][j]!=0) addNode(i,j,matrix[i][j]);
    printGraph();
}

void MST(int v){
    struct vertex *mst[v];
    for(int i=0;i<v;i++) mst[i]=NULL;
    for(int i=1;i<size;i++) mst[i]=getNode(i);
    
}

int main(){
    FILE *ip;
    ip=fopen("graph.txt","r");
    if(ip==NULL){
        printf("The data file doesn't exist ");
        exit(0);}

    while(!feof(ip)){
        int so,de,we;
        fscanf(ip,"%d %d %d",&so,&de,&we);
        arr[n][0]=so;
        arr[n][1]=de;
        arr[n][2]=we;
        n++;
    }
    matrixGraph();      //Matrix representation
    printf("%d is the total cost of the graph\n",cost);
    linkedListGraph();  //Linked list
    printf("\nDFS\n");
    DFS();
    reset();
    printf("\nBFS\n");
    BFS();
    MST(size);
    fclose(ip);
}