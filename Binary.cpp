#include <stdio.h>
int a[100], n,m;
void printSol(){
    for(int i = 1; i <= n; i++) printf("%d", a[i]);
    printf("\n");
}
void Try(int k){
    for(int i = 0; i<=1; i++){
        a[k]=i;
        if(k==n) printSol();
        else Try(k+1);
    }
}
int main(){
    scanf("%d", &n);
    Try(1);
}