#include <stdio.h>

void stockSpan(int n, int price[]) {
    int span[n]; // array to store the span values
    span[0] = 1; // span of first day is always 1
    int top = 0; // initialize stack pointer
    int stack[n]; // create stack to store index of prices
    
    stack[top] = 0; // push index of first price onto the stack
    
    for (int i = 1; i < n; i++) {
        // pop indexes of prices from the stack while the price is less than or equal to the current price
        while (top >= 0 && price[stack[top]] <= price[i]) {
            top--;
        }
        
        // calculate span of current day
        if (top < 0) {
            span[i] = i + 1; // if stack is empty, the span is the number of days including the current day
        } else {
            span[i] = i - stack[top]; // else, the span is the difference between the current day and the most recent day with a higher price
        }
        
        // push index of current price onto the stack
        top++;
        stack[top] = i;
    }
    
    // print span values
    for (int i = 0; i < n; i++) {
        printf("%d ", span[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int price[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }
    stockSpan(n, price);
    return 0;
}
