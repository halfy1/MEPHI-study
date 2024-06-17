#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
    double fcor,f,scor=0.0,cor=0.0,i=0.0,sum=0.0000,sum1=0.0;
	int n;
	for (n=1;n<=200000000;n++){
	    i++;
	    f=sqrt((1+3*i*i)/(3+i*i));
	    fcor=f-cor;
	    scor=sum1+fcor;
	    cor=(scor-sum1)-fcor;
	    sum1=scor;
	    sum+=f;
	    if(n%20000000==0){	printf("%9d%18.4lf%18.4lf%10.4lf\n",n,sum,sum1,sum-sum1) ;}
	}
   
	return 0;
}
