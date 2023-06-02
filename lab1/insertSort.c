/*
Question 2.Array sorting using insertion sort
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int arr[], int n){
    int count=0,j,key;
    for(int i = 1;i<n;i++) {
        key = arr[i];
        j = i - 1;
        while(j>=0 && arr[j]> key){
            arr[j + 1] = arr[j];
            count++;
            j = j - 1;
        }
        arr[j+1]=key;
    }
    printf("The number of operations involved in sorting is %d",count);
    printf("\nNumber of insertions are %d ",n);
    printf("\nTotal number of operations is %d",n+count);
}

int main(){
    FILE *ip;
    clock_t startTime,endTime;
    double execTime;
    ip=fopen("insert.txt","r");
    if(ip==NULL){
        printf("Error in opening the insert.txt file\nThat file Doesn't exist");
        exit(0);}
    int n;
    fscanf(ip,"%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) fscanf(ip,"%d",&arr[i]);
    startTime=clock();
    insertionSort(arr,n);
    endTime=clock();
    execTime=(double)(endTime-startTime)/CLOCKS_PER_SEC;
    printf("\nExecution time is %lf\n",execTime);
    fclose(ip);
}