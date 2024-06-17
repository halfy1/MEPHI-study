#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void zapolneneniye_mas_random (void);
void zapolneneniye_mas (void);
void vivod_mas (int a[]);
void swap (int *, int *, int a[]);
void Merge (int, int);
void MergeSort (int, int);
void QuickSort(int, int);
void Copier();

int n , *mas, c_prisv=0, c_srav=0, *cmas;
int srav=0, prisv=0;
int main(void)
{
  srand (time(NULL));
  n = 1 + rand() % 10;
  //scanf ("%d", &n);
  mas = (int *) malloc(n * sizeof(int));
  cmas = (int *)malloc(n * sizeof(int));
  zapolneneniye_mas_random();
  Copier();
  //zapolneneniye_mas();
  vivod_mas(mas);
  printf("\n");
  QuickSort(0,n-1);
  printf("%d %d\n",prisv,srav);
  vivod_mas(mas);
  printf("\n");
  MergeSort(0, n-1);
  printf("%d %d\n",c_prisv,c_srav);

  return 0;
}
void zapolneneniye_mas_random (void){
  for (int i = 0; i < n; i++){
    mas[i] = rand() % 10;
  }
}
void Copier(void){
  for (int i = 0; i < n; i++){
    cmas[i]=*(mas+i);
  }
}
void zapolneneniye_mas (void){
  for (int i = 0; i < n; i++)
    scanf ("%d", &mas[i]);
}

void vivod_mas(int a[]){
  for (int i = 1; i <= n; i++)
    printf ("%3d", i);
  printf ("\n");
  
  for (int i = 0; i < n; i++)
    printf ("%3d", a[i]);
  printf ("\n");
}
void swap (int *x, int *y, int a[])
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
  c_prisv+=1;
  vivod_mas(a);
  printf ("\n");
}

void Merge(int first, int last){
  int B[n]; /*вспомогательный массив*/
  int k; /*индекс во вспомогательном массиве*/
  int l,r; /*левый и правый счетчики*/
  int m; /*индекс среднего элемента*/
  m=(first+last)/2;
  l=first; r=m+1;
  k=0;
  while (l<=m && r<=last) { /* Пока не закончился */
    if (mas[l]<=mas[r]) { /*хотя бы один фрагмент.*/
      c_srav+=1;
      B[k]=mas[l];
      l++;
    }
    else {
      B[k]=mas[r];
      r++;
    }
    k++;
  } /*Один из фрагментов закончился.*/
  /*Переносим остаток другого фрагмента во вспомогательный
  массив.*/
  while (l<=m) {  B[k]=mas[l]; l++; k++; }
  while (r<=last) {  B[k]=mas[r]; r++; k++; }
  for (l=0; l<k; l++){
    mas[first+l]=B[l];
    c_prisv+=1;
  }
  vivod_mas(mas);
  printf ("\n");
  }
  
void MergeSort(int fst, int lst){
  int m; /*индекс среднего элемента*/
  c_srav+=1;
  if (fst<lst){
  if (lst-fst==1) {
    if (mas[lst]<mas[fst])
      swap(&mas[fst],&mas[lst],mas);
    }
  else {
    m=(fst+lst)/2;
    MergeSort(fst,m);
    MergeSort(m+1,lst);
    Merge(fst,lst);
    }
  }
 }

void QuickSort(int first, int last){
  int sr; // средний элемент
  int l,r; // правые левые, концы
  l=first; r=last;
  sr=cmas[(l+r)/2];
  while(l<r){
		srav++;
    while(cmas[l]<sr){
  		l++; 
  		srav++;
  	}
    srav++;
    while(cmas[r]>sr){ 
  		r--; 
  		srav++;
  	}
    if(l<r){
      swap(&cmas[l],&cmas[r],cmas);
  		prisv+=3;
      l++;
  		r--;
  	}
    else{
      l++;
      r--;
  	}
  }
  if(first<r) QuickSort(first,r);
  if(l<last) QuickSort(l,last);
}
