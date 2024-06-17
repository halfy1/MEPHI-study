#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
int main(){
int m,n,i=0,sum=0,number[i],max=0,k=0,j=0;
scanf("%d%d",&m,&n);
int mas[m][n];
for(i=0;i<n;i++){
 if(i%2==0){
  for(j=0;j<m;j++){ 
   scanf("%d",&mas[j][i]);
   //scanf("%d",*(mas+j));
  }
 }
   else{
    for(j=(m-1);j>=0;j--){
	 scanf("%d",&mas[j][i]);
	//scanf("%d",*(mas+j));
	}
   }
}
for(i=0;i<m;i++){
 for(j=0;j<n;j++){
  printf("%3d",mas[i][j]);
  //printf("%3",*(*(mas+j)+i));
  }
 printf("\n");
}
printf("\n");
for(i=0;i<n;i++){
 for(j=0;j<m;j++){
  sum+=mas[j][i];
 }
 number[i]=sum;
 sum=0;
}
for(i=0;i<n;i++){
 if(number[i]>max){
  max=number[i];
 }
}
for(i=0;i<n;i++){
 if(number[i]==max){
  k++;
  if(k==1){
   printf("%d",i+1);
  }
  else{
  printf(" %d",i+1);
  }
 }
}
printf("\n");
return 0;
}
