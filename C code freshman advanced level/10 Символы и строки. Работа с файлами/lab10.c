#include <stdio.h>
#include <ctype.h>
int main(void) {
    char n, buf,f[100]= " ";
    int j=0,max=0,i=0,sr1=0,sr2=0,srm1,srm2,k;
    while (buf!='\n'){
        n=getchar();
        if (isgraph(n)){
            f[i]=n;
            if (isspace(buf)){
                sr1=i;
            }
            putchar(n);
            j++;
            i++;
        }
        if (isspace(n)&&isalpha(buf)){
            if (max<j){
                max = j;
                srm1 = sr1;
                srm2 = i;
            }
            j=0;
            printf("\n");
        }
        buf=n;
    }
    printf("\n");
    for(k=srm1;k<srm2;k++){
        putchar(f[k]);
    }
    printf("\n");
    return 0;
}