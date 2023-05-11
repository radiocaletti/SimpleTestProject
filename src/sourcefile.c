#include "stdio.h"

int function_f(int);

int function_f(int x){
    return x*x + 1;
}

int main(void){
    printf("Execute.\n");
    int y = function_f(2);
    printf("y = %i.\n", y);
    return 0;
}