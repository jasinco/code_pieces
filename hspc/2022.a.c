#include <stdio.h>

int main(void){
    int px,py,cx,cy,sx,sy,hx,hy,total = 0, num1, num2;

    scanf("%d %d", &px,&py);
    scanf("%d %d", &cx,&cy);
    scanf("%d %d", &sx,&sy);
    scanf("%d %d", &hx,&hy);

    if (px > cx)
    {
        total += (px-cx) * sx;
        num1 = sx;
        
    }else{
        total += (px-cx) * hx;
        num1 = hx;
    }
    if (py > cy)
    {
        total += (py-cy) * sy;
        num2 = sy;
    }else{
        total += (py-cy) * hy;
        num2 = hy;
    }


    printf("%d\n%d %d\n", total, num1, num2);

    return 0;
}
