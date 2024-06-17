#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int t=1,i=0,x,y,z,m,med;
	scanf("%d%d%d%d",&x,&y,&z,&m);
	if (x>=y && y>=z){
			med=y;}
	else if (z>=y && y>=x){
			med=y;}
	else if (y>=x && x>=z){
			med=x;}
	else if (y>=z && z>=x){
			med=z;}
	else if (z>=x && x>=y){
			med=x;}
	else if (x>=z && z>=y){
			med=z;}
 if (x==y && y==z){printf("%d=%d=%d\n",x,y,z);}
	else if(x==y && x!=z){
	if (x<z){printf("%d=%d<%d\n",x,y,z);}
	else if (x>z){printf("%d=%d>%d\n",x,y,z);}
	} 
	else if(x==z && x!=y){
	if (x<y){printf("%d=%d<%d\n",x,z,y);}
	else if (x>y){printf("%d=%d>%d\n",x,z,y);}
	} 
	else if(y==z && z!=x){
	if (z<x){printf("%d=%d<%d\n",y,z,x);}
	else if (z>x){printf("%d=%d>%d\n",y,z,x);}
	} 
	else{
		printf("%d\n",med);}
	while(t<=m){t=t*5;i++;}
	printf("\n%d\n\n",i);
	int o=1;
	for (i=1;i<=12;i++){printf("%3d  %d\n",i,o=o*5);}
    return 0;
}

