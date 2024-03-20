#include "arithmetic.h" 
#include "stdio.h"
#include "string.h"

int main(void){
    static char* equation = "-100+2";
    printf("%d\n", calc(equation));
}
