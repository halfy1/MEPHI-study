#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void zapol_random(int *a[], int k){
  int i;
  for (i=0; i<k;i++){
      *a[i] = 12 + (rand() %(9));
  }
}

void vivod(int *a,int k){
  int i;
  for (i=0;i<k;i++){
    printf("%3d",i+1);
  }
  printf("\n");
  for (i=0;i<k;i++){
      printf("%3d", a[i]);
  }
  printf("\n");
}
void sort1 (int *arr,int n){
    int i,min=*arr,j,k,pr=0,sr=0,q;
    for (i=0;i<n-1;i++){
        for (j=i;j<n;j++){
            if (*(arr+j)<min){
                k = j;
                min = *(arr+j);
                pr+=3;
            }
            else{
                sr++;
                
            }
        }
        if (min != *(arr+i)){
            q = *(arr+i);
            arr[i] = min;
            arr[k] = q;
        }
        min = *(arr+i+1);
        vivod(arr,n);
        if (i == n-2){
            printf("%d %d\n",pr,sr);
        }
        else{
            printf("\n");
        }
    }
}
int main(void) {
  int i,n;
  scanf("%d",&n);
  int *arr;
  arr=(int*) malloc (n*sizeof(int));
  if (arr==NULL){
    exit(EXIT_FAILURE);
  }
  for (i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  vivod(arr,n);
  printf("\n");
  sort1(arr, n);
  return 0;
}