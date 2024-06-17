#include <stdio.h>
#include <stdlib.h>

void add(int **pa, int n, int a, int k);
void change(int **q, int a, int b);

int main()
{
    int i, n, a, b, k;
    int *pa, *q;
    scanf("%d", &n);
    pa = (int*)malloc((n+1)*sizeof(int));
    
    for (i=0; i<n; ++i)
        scanf("%d", &pa[i]);
        
    scanf("%d %d",&a, &k);
    k--;
    scanf("%d", &b);
    b--;

    
    for (i=0; i<n; ++i) 
        printf("%3d", i+1);
    printf("\n");
    for (i=0; i<n; ++i) 
        printf("%3d", pa[i]);
    printf("\n");
    printf("\n");
    
    add(&pa, n, a, k);
    q = (int*)realloc(pa, (n+1)*sizeof(int));
    change(&q, 0,b);
    
    for (i=0; i<n+1; ++i) 
        printf("%3d", i+1);
    printf("\n");
    for (i=0; i<n+1; ++i) 
        printf("%3d", q[i]);
    printf("\n");
    
    free(q);
        
    return 0;
    
}
void add(int **pa, int n, int a, int k)
{
    int i, temp, q;
    temp = (*pa)[k];
    (*pa)[k]=a;
    for (i=k+1; i<n+1; i++)
    {
        q = (*pa)[i];
        (*pa)[i]=temp;
        temp = q;
        
    }
}
void change(int **q, int a, int b)
{
    int temp, i;
    for (i=a; i<b; i++)
    {
        temp=(*q)[i];
        (*q)[i]=(*q)[i+1];
        (*q)[i+1]=temp;
    }
    for (i=b-1; i>a; i--)
    {
        temp=(*q)[i];
        (*q)[i]=(*q)[i-1];
        (*q)[i-1]=temp;
    }
}