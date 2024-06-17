#include <stdio.h>
int main(void) {
    int x,y,i,k;
	long int b1=1,b2=2,b3;
	scanf("%d %d",&x,&y);
	scanf("%d",&k);
	if ((y>0)&&((x*x+y*y)>62500)&&(x<250)&&(y<250)&&(x>-250))
		{
		printf("inside\n\n");
	}
	else if((y<0)&&((x*x+y*y)<62500)&&((y<-x-250)||(y<x-250)))
		{
	printf("inside\n\n");
	}
	else{printf("outside\n\n");}
	printf("%3d  %ld\n",1,b1);
	for (i=2;i<=k;i++){printf("%3d  %ld\n",i,b1+b2);b3=b1;b1=b1+b2;b2=b3;}
	printf("\n");
	for (i=k+1;i<=44;i++){if(i>=42){printf("%3d  %ld\n",i,b1+b2);}b3=b1;b1=b1+b2;b2=b3;}
    return 0;
}
