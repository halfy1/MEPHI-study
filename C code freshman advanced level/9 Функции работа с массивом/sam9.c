#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
int vnesh1[6];
void zapol_random(int a[], int k){
    srand(time(NULL)); 
    int i;
    for (i=0; i<k;i++){
        a[i] = 10 + (rand() %(6));
    }
    sleep(1);
}
void obnul(int a[],int k){
    int i;
    for (i=0; i<k; i++){
        a[i] = 0;
    }
}
/*void zapol(int *a[], int k){
    int i;
    for (i=0; i<k;i++){
        scanf("%d", a[i]);
    }
}
*/
void vivod(int a[],int k){
    int i;
    for (i=0;i<k;i++){
        printf("%2d", a[i]);
        if (i != k-1){
            printf(" ");
        }
        else("\n");
    }
    printf("\n");
}
int summa(int a[], int k){
    int s=0,i=0;
    for (i = 0; i<k; i++){
        s+=a[i];
    }
    return s;
}
void povtori(int a[], int k, int b[], int j, int c[], int h){
    int i,x;
    for (i=0;i<k;i++){
        x = a[i] % 10;
        if (vnesh1[x]==0){
            vnesh1[x]++;
        }
    }
    for (i=0;i<j;i++){
        x = b[i] % 10;
        if (vnesh1[x]==1 ){
            vnesh1[x]++;
        }
    }
    for (i=0;i<h;i++){
        x = c[i] % 10;
        if (vnesh1[x]==2){
            vnesh1[x]++;
        }
    }
    for (i=0;i<6;i++){
        if (vnesh1[i]==3){
            printf("%2d", i+10);
            if (i != k-1){
                printf(" ");
            }
            else("\n");
        }
    }
    printf("\n");
}
int main()
{
    int a[5],b[6],c[8];
    zapol_random(a,5);
    vivod(a,5);
    zapol_random(b,6);
    vivod(b,6);
    zapol_random(c,8);
    vivod(c,8);
    printf("%d %d %d\n",summa(a,5),summa(b,6),summa(c,8));
    povtori(a,5,b,6,c,8);
    return 0;
}