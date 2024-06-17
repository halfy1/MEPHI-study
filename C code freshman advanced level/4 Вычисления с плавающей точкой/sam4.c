#include <math.h>
#include <stdio.h>
int main()
{
    int n,k,i,s1,q1,c=0;
    double e,s=0.0,q,delta;
    scanf("%d",&k);
    q = (double) 1/3;
    for(i=1;i<k;i++){
        e=(double) 1/((3*i-2)*(3*i+1));
        s+=e;
    }
    delta=q-s;
    s1=s*pow(10,9);
    q1=q*pow(10,9);
    if (s1%10>=5){
        s1=s1/10 +1;
    }
    while (s1>0){
        if (s1%10 == q1%10){
            c+=1;
        }
        s1/=10;
        q1/=10;
    }
    
    
    printf("%.8f\n%.8f\n%.8f\n%d\n", q,s,delta,c);
    

    return 0;
}
