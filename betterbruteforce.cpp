#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int maxSum(int a[], int n)
{
    int maxSum = a[0];
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    return maxSum;
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

int main()
{
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