#include <stdio.h>
int a[100], n,m;
int check(int y, int k){
    for(int j = 1; j<=k-1; j++){
        if(y==a[j]) return 0;
    }
    return 1;
}
void printSol(){
    for(int i = 1; i <= n; i++) printf("%d", a[i]);
    printf("\n");
}
void Try(int k){
    for(int i = 0; i <=n; i++){
        if(check(i,k)==1){
            a[k] = i;
            if(k==n) printSol();
            else Try(k+1);
        }
    }
}
int main(){
    scanf("%d", &n);
    Try(1);
}