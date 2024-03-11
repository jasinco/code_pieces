#ifndef __ARITH.H__
#define __ARITH.H__
//https://en.wikipedia.org/wiki/Shunting_yard_algorithm
extern char equaition[100];
extern int size;

bool ge(char x, char y){
    int precedure[3] = {1,1};
    if (x == '*' || x == '/'){
        precedure[0] = 2;
    }
    if (y == '*' || y == '/'){
        precedure[1] = 2;
    }
    return precedure[0] >= precedure[1];
}

void calc(){
    int output[50];
    int output_size = 0;
    char opr[50];
    int opr_size = 0;
    for(int i =0; i< size; i++){
        char x = equaition[i];
        if (x >= 48 && x <= 57){
            output[output_size] = x-48;
            output_size ++;
        }else{
            while (opr_size > 0 && ge(opr[opr_size], x)) {
                
            }
        }

    }
}

#endif
