#include <stdio.h>
void solve(int n, int a[]){
    int count = 0;
    int dem[n];
    dem[0] = 0;
    for(int i = 1; i < n; i++){
        int k = i-1;
        while(a[k]<a[i]){
            k--;
        }
        dem[i] = i-k-1;
    }
    for(int i = 0; i < n; i++){
        printf("%d ", dem[i]);
    }
}
int main(){
    int n; 
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    solve(n, a);
}