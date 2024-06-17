/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
int f(int a,int b,int c, double *s,double *p){
    double q = 0;
    *p = a+b+c;
    q = *p / 2;
    *s = sqrt(q*(q-a)*(q-b)*(q-c));
    if ((a<=0) || (b<=0) || (c<=0)) {
        return 1;        
    }
    else if ((a+b==c) || (a+c==b) || (b+c == a)){
        return 2;
    }
    else if((a+b<c) || (a+c<b) || (b+c<a)){
        return 3;
    }
    return 0;
}
int main()
{   
    int a,b,c,z;
    double s=0,p=0;
    scanf("%d%d%d",&a,&b,&c);
    z = f(a,b,c,&s,&p);
    printf("%d\n%.6lf\n%.6lf\n",z,p,s);
    return 0;
}
