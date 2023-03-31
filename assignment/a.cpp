#include <stdio.h>
#include <stdlib.h>

void next_numbers(int n, int a,int b, int c){
    for(int i=0;i<n;i++){
        int next = (a+b+c)/c;
        a=b;
        b=c;
        c=next;
        printf("%d ",next);
    }
}


int main(){
    int n,a,b,c;
    printf("Enter range: ");
    scanf("%d",&n);
    printf("Enter 1st number: ");
    scanf("%d",&a);
    printf("Enter 2nd number: ");
    scanf("%d",&b);
    printf("Enter 3rd number: ");
    scanf("%d",&c);
    next_numbers(n-3,a,b,c);
}