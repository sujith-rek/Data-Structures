/*
Question 1. to find (1.12)^631 using 3 recursive functions
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

long count1=0,count2=0,count3=0;

double fpow1(double a, int n){
     count1++;
     if(n==0) return 1;
     else{
        if(n%2==0) return fpow1(a,n/2)*fpow1(a,n/2);
           else return a*fpow1(a,n/2)*fpow1(a,n/2);
           }
   }

double fpow2(double a, int n){
    count2++;
    if(n==0) return 1;
    else{
        double b=fpow2(a,n/2);
           if(n%2==0) return b*b;
           else return a*b*b;
    }
}

double fpow3(double x,int n){
    double m;
    count3++;
    if(n==0) return 1;
    else return x*fpow3(x,n-1);
}

int main(){
    double ans1,ans2,ans3;
    clock_t startTime,endTime;
    double execTime,avg1=0,avg2=0,avg3=0;
    double base=1.12;
    int power=631;
    for(int i=0;i<1000;i++){
        startTime=clock();
        ans1=fpow1(base,power);
        endTime=clock();
        execTime=(double)(endTime-startTime)/CLOCKS_PER_SEC;
        avg1=avg1+execTime;
    }
    for(int i=0;i<1000;i++){
        startTime=clock();
        ans2=fpow2(base,power);
        endTime=clock();
        execTime=(double)(endTime-startTime)/CLOCKS_PER_SEC;
        avg2=avg2+execTime;
    }
    for(int i=0;i<1000;i++){
        startTime=clock();
        ans3=fpow3(base,power);
        endTime=clock();
        execTime=(double)(endTime-startTime)/CLOCKS_PER_SEC;
        avg3=avg3+execTime;
    }
    printf("-----------------------------------------------------------------------------------------\n");
    printf("| Function number || Number of calls ||         Exponetiation           || Average time |\n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("| Recursion 1     || %ld            ||%.lf || %lf     |\n",count1/1000,ans1,avg1/1000);
    printf("| Recursion 2     || %ld              ||%.lf || %lf     |\n",count2/1000,ans2,avg2/1000);
    printf("| Recursion 3     || %ld             ||%.lf || %lf     |\n",count3/1000,ans3,avg3/1000);
    printf("-----------------------------------------------------------------------------------------\n");
}