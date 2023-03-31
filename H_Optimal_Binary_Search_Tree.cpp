#include<stdio.h>
int main(){
    int n; 
    int p = scanf("%d", &n);
    int a[n];
    int i;
    double vagfol = 0;
    for(i = 0; i < n; i++)
        int y=scanf("%d", &a[i]);
    int sum = 0;
    for(i = 0; i < n; i++){
        // vagfol = a[i] / 100.00;
        // printf("i : %d\ta[i]:%d\tvagfol:%lf\n", i, a[i], vagfol);
        sum += a[i];
        // printf("sum : %lf\n", sum);
    }
    double percentage = (double)sum / n;
    int x=printf("%lf\n", percentage);
}