#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{   
    int i,a[40],b[40],j,q=0,c=1,max=0;

    for (i=0; i<40;i++){
        scanf("%d",&a[i]);
    }
    
    for (i=0;i<39;i++){
        for (j=i+1;j<40;j++){
            if (a[i]==a[j]){
                c++;
            }
        }
        b[q]=c;
        q++;
        c = 1;
        printf("%d  ",a[i]);
    }
    b[39]=1;
    q=0;
    for (i=0;i<40;i++){
        if (max<b[i]){
            max=b[i];
        }
    }
    for (i=0;i<40;i++){
        if (b[i]==max){
            q++;
        }
    }
    
    printf("\n%d\n",q);
    for (i=0;i<40;i++){
        if (b[i]==max){
            printf("%d ",a[i]);    
        }

    }
    printf("\n");
    
    return 0;
}
