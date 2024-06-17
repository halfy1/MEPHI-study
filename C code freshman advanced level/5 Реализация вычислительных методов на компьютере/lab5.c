#include <stdio.h>
int main()
{
    double m,x=0.0,y=3.0,z;
    while(y-x>=0.0000000001){
        m =(x+y)/2;
        if ((m*m - 7*m + 8>=0) && (y*y - 7*y + 8<=0)) {x=m;}
        else if((m*m - 7*m +8<=0)&& (x*x - 7*x +8>=0)) {y=m;}

        
    }
    printf("%11.10lf\n",x);
    return 0;
}
