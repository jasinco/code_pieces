#include "arithmetic.h" 
#include "stdio.h"
#include "string.h"

int main(void){
    static char* equation = "100-2131+21323*231/2323";
    printf("%.2f\n", calc(equation));
}
