#ifndef ARITH_H 
#define ARITH_H
//https://en.wikipedia.org/wiki/Shunting_yard_algorithm
#include <stdlib.h>

struct unit{
    char opr;
    int num;
};

// x greater or equal to y
bool ge(char x, char y){
    // if it is * or /, it must be the greatest operator in this case.
    // and or x==y means that if both x and y is '+' or '-', it will return equal
    return x=='*' || x == '/' || x==y;
}

int calc(char* equation){
    struct unit *units = calloc(51, sizeof(struct unit));
    int unitslen = 0;

    char *opr = calloc(50, sizeof(char));
    int oprlen = 0;
    int answer = 0;

    //Shunting Yard Algorithm
    for (int i = 0; i<100;i++){
        if (equation[i] == 0x00){
            break;
        }
        
        switch (equation[i]){
            case '+':
            case '-':
            case '*':
            case '/':
                //if it is +, -, *, / then run down stuff

                if (i == 0 && (equation[0] == '-' || equation[0] == '+')){
                    /* (&units[0])->num = 0; */
                    // The units was reseted to 0 so it represent the upper one 
                    // and just append a 0 into the stack
                    unitslen++;
                    oprlen++;
                    break;
                }

                unitslen++;

                if (oprlen > 0){
                    while (oprlen != 0){
                        if (ge(opr[oprlen-1], equation[i])){
                            units[unitslen].opr = opr[oprlen-1];
                            unitslen++;
                            oprlen--;
                            continue;
                        }
                        break;
                    }
                }
                opr[oprlen] = equation[i];
                oprlen++;
                //check append
                //negative two statement
                // in the first of this array 
                // and the middle of it
                break;
            default:
                struct unit *u =  &units[unitslen]; 
                u->num = u->num * 10 + (equation[i]-'0');
                break;
        }
    }

    for (;oprlen>0;oprlen--){
        unitslen++;
        units[unitslen].opr  = opr[oprlen-1];
    }

    answer = units[0].num;
    free(units);
    free(opr);
    return answer; 
}

#endif
