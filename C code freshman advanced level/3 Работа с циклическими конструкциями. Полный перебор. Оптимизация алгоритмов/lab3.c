#include <stdio.h>

int main(int argc, char *argv[])
{
	int a,d,c,del,i,j,max1,max;
	for (a=180; a<=210; a++){
	    if (a<100){
	        printf(" ");
	    }
		for(i=2;i<a;i++){
			if (a%i==0){break;}
		}
		del = 0;
		c = 0;
		printf("%d  ",a);
		for (d=2; d<a; d++){
			if (a%d==0){
				del++;
				c+=d;
                if (c>=max){
                    max = c;
                    max1 = a;
                }
				// last deletile'
				if (i*d==a){
					printf("%3d ",d);
				}
				else {
					printf("%3d,",d);
				}
				// summa deletilev
				if (del%4==0 && i*d ==a){
				    printf("%5d", c);
				}
				else if (del%4==0){
					printf("\n     "); 
				}
			}
		}
	if (del==0 || (del>0 && del%4>0)){
	    for (j=1; 5-(del % 4)>j;j++){
		    printf("    ");
		}
	    printf("%5d",c);
	}
	printf("\n");	
	}
	printf("\n%d\n",max1);
    return 0;
}