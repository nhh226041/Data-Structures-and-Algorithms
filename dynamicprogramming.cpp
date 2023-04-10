#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int max(int a, int b){
    return (a>=b)?a:b;
}
int maxSum(int a[], int n){
    int smax = a[0];
    int ei = a[0];
    for(int i = 0; i < n; i++){
        ei = max(a[i], ei+a[i]);
        smax = max(smax, ei);
    }
    return smax;
}
double calculateTime(int a[], int n)
{
    clock_t start, end;
    double time_used;
    start = clock();

    int result = maxSum(a, n);

    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Max sum: %d\n", result);
    printf("Time taken: %f seconds\n", time_used);
    return time_used;
}
int main(){
    system("clear");
    int a[100000], n;
    scanf("%d", &n);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 201 - 100;
    }
    calculateTime(a, n);
    return 0;
}