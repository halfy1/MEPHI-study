#include <stdio.h>
#include <limits.h>

int g = 0;

long int func (long int, long int);

int main (void)
{
    long int n, m, f;
    scanf ("%ld%ld", &n, &m);
    f = func (n,m);
    if (g >= 1000)
        printf ("endless\n");
    else if (f>INT_MAX)
        printf ("overflow\n");
    else
        printf ("%ld\n", f);
    return 0;
}

long int func (long int n, long int m)
{
    if ((n+m)%2 == 0)
    {
        if (n<=m)
            return m;
        else
            return n;
    }
    else
    {
        g += 1;
        printf ("%ld  %ld\n", n,m);
        if (g >= 10000)
            return 0;
        else
            return func ((n+m+1)/2,m) + func (n, (n+m+1)/2);
    }
}
