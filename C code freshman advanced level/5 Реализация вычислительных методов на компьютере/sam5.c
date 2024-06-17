#include <stdio.h>
#include <math.h>
int main()
{
    double med=0, x=2.0, y=4.0,su,v;
    int i=1;
    while (fabs(0.4 - sin(med))>0.0000001){
        med = (x+y)/2;
        if ((sin(med) - 0.4)<0){
            y = med;
        }
        else{
            x = med;
        }

    }
    printf("%.7f\n%.8lf\n",med,y-x);
    su=med;
    y = med;
    x = 1;
    v=med;
    while (fabs(sin(med) - v)>0.000001){
        y *= pow(-1,i)*med*med;
        x *= (i+1)*(i+2);
        su = y/x;
        i+=2;
        v+=su;
    }
    printf("%.6f\n%d",v,i);

    return 0;
}
