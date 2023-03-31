#include <stdio.h>
#include <limits.h>
#include <math.h>
int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a<b?a:b;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n][m+1];
    for(int i=0;i<n;i++){
        arr[i][0]=0;
        for(int j=1;j<=m;j++){
            scanf("%d",&arr[i][j]);
            arr[i][j]+=arr[i][j-1];
        }
    }
    for(int i=0;i<5;i++){
        int a,b,x,y;
        scanf("%d %d %d %d",&a,&b,&x,&y);
        // a++,b++,x++,y++;
        b++,y++;
        if(a>x || b>y){
            printf("Error: Inappropriate user input\n%d\n",INT_MIN);
        }else{
            int res=0;
            a=max(a,0);
            b=max(b,1);
            a=min(a,n-1);
            b=min(b,m);
            x=max(x,0);
            y=max(y,1);
            x=min(x,n-1);
            y=min(y,m);
            for(int j=a;j<=x;j++){
                res+=arr[j][y]-arr[j][b-1];
            }
            printf("%d\n",res);
        }
    }
}