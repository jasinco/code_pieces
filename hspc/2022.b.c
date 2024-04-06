#include <stdio.h>


int main(void){
    int n,m;
    scanf("%d %d", &n, &m);
    int radar[n][2];
    for (int i = 0; i < n; i++){
        scanf("%d %d", radar[i][0], radar[i][1]);
    }
    if (n == m){
        printf("%d\n", n);
        return 0;
    }
    if (m == 0){
        printf("0\n");
        return 0;
    }

}
