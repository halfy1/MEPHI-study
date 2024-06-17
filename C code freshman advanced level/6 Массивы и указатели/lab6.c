#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{   
/*
    srand(time(NULL)); 
    int x,y;
*/
    int i,a[40],min=10000000,c=0,k=0,z;
    double m=0.0;
//  scanf("%d %d",&x,&y);
    for (i=0; i<40;i++){
//      a [i] =x + (rand() %(y-x+1));
        scanf("%d",&a[i]);
    }
    scanf("%d",&z);
    for (i=0; i<40;i++){
        if (a[i]>z){
            m+=a[i];
            c++;
        }
    }
    m/=c;
    c = 0;
    for (i=0;i<40;i++){
        if (a[i]>m){
            c++;
            if (a[i]<min){
                k=1;
                min=a[i]; 
            }
            else if(a[i] == min){
                k++;
            }
        }
    }
    if (k == 0){min = k;}
    printf("%.4lf\n%d\n%d %d\n",m,c,min,k);

    return 0;
}
