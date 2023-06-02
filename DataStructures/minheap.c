//MIN HEAP
#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)

int arr[100],size=0;

void heapifyInsert(int val){
    size++;
    int c=size;
    arr[c]=val;
    while(c>1){
        if(arr[c]<arr[c/2]){
            int temp=arr[c];
            arr[c]=arr[c/2];
            arr[c/2]=temp;
        }
        c=c/2;
    }
}

int ind(int a,int b,int c){
    if(arr[a]<arr[b] && arr[a]<arr[c]) return a;
    if(arr[b]<arr[a] && arr[b]<arr[c]) return b;
    if(arr[c]<arr[a] && arr[c]<arr[b]) return c;
}

void heapify(){
    int l=size/2,root;
    for(int j=0;j<3;j++){
        l=size/2;
        while(l>0){
            root=arr[l];
            if((l*2)+1<size){
                int i=ind(l,l*2,l*2+1);
                arr[l]=arr[i];
                arr[i]=root;
            }else{
                if(arr[l]>arr[l*2]){
                  arr[l]=arr[l*2];
                  arr[l*2]=root;
                }
            }
            l--;
        }
    }
}

void heapifyDelete(){
    arr[1]=arr[size];
    arr[size]=0;
    size--;
    int c=1,root;
    heapify();
}

int main(){
    FILE *ip;
    ip=fopen("heap.txt","r");
    if(ip==NULL){
        printf("The file doesn't exist");
        exit(0);
    }
    while(!feof(ip)){
        fscanf(ip,"%d",&arr[size+1]);
        size++;
    }
    heapify();
    for(int i=0;i<size;i++) printf("%d ",arr[i+1]);
    heapifyInsert(5);
    printf("\n");
    for(int i=0;i<size;i++) printf("%d ",arr[i+1]);
    heapifyDelete();
    printf("\n");
    for(int i=0;i<size;i++) printf("%d ",arr[i+1]);
}