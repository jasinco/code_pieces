#ifndef ARITH_H 
#define ARITH_H
//https://en.wikipedia.org/wiki/Shunting_yard_algorithm
#include <stdlib.h>

struct unit{
    char opr;
    float num;
};

// x greater or equal to y
bool ge(char x, char y){
    // if it is * or /, it must be the greatest operator in this case.
    return (x=='*' || x == '/') || !(y=='*' || y == '/'); 
}

bool is_opr(struct unit x){
    return x.num == 0 && (x.opr == '/' || x.opr == '*' || x.opr == '+' || x.opr == '-');
}
bool is_opr_char(char x){
    return (x == '/' || x == '*' || x == '+' || x == '-');
}


float calc(char* equation){
    struct unit *units = calloc(51, sizeof(struct unit));
    int unitslen = 0;

    char *opr = calloc(50, sizeof(char));
    int oprlen = 0;
    float answer = 0;

    //Parse to reverse polish notation
    //Shunting Yard Algorithm
    
    int delta = 1; // manage that if the number is a negative number
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
                    opr[oprlen] = equation[i];
                    oprlen++;
                    break;
                }

                // update units length to another unit
                unitslen++;
                delta = 1;
                if (oprlen > 0){
                    while (oprlen != 0){
                        if (equation[i] == '-' && is_opr_char(equation[i-1])){
                                delta = -1;
                                unitslen--;
                                break;
                        }
                        if (ge(opr[oprlen-1], equation[i])){
                            units[unitslen].opr = opr[oprlen-1];
                            unitslen++;
                            oprlen--;
                            continue;
                        }
                        break;
                    }
                }
                if (delta  == 1){
                    opr[oprlen] = equation[i];
                    oprlen++;
                }
                //check append
                //negative two statement
                // in the first of this array 
                // and the middle of it
                break;
            default:
                struct unit *u =  &units[unitslen]; 
                u->num = u->num * (float)10 + (float)(equation[i]-'0') * (float)delta;
                break;
        }
    }

    for (;oprlen>0;oprlen--){
        unitslen++;
        units[unitslen].opr  = opr[oprlen-1];
    }
    unitslen++;
    free(opr);

    // caculate the result 
    for (int i = 0; i < unitslen; i++){
        if (is_opr(units[i]) && i > 1 && !(is_opr(units[i-1]) || is_opr(units[i-2]))){
            float result = 0;
            switch (units[i].opr){
                case '+':
                    result = units[i-2].num + units[i-1].num;
                    break;
                case '-':
                    result = units[i-2].num - units[i-1].num;
                    break;
                case '*':
                    result = units[i-2].num * units[i-1].num;
                    break;
                case '/':
                    result = units[i-2].num / units[i-1].num;
                    break;
            }
            struct unit pending;
            pending.num = result;
            pending.opr = '\0';
            units[i-2] =  pending;
            for (int j = i+1;j < unitslen; j++){
                units[j-2] = units[j];
            }
            unitslen -= 2;
            i -= 4;
        }
    }

    answer = units[0].num;
    free(units);
    return answer; 
}

#endif
