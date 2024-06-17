#include <stdio.h>
#include <stdlib.h>

void func1(int high, int low, int m, int n, int matrix[][n]);
void func2(int m, int n, int matrix[][n]);
void func31(int m, int n, int matrix[][n]);
void func32();
void func4(int m, int n, int matrix[m][n], int matrixT[n][m]);
void func5(int m, int n, int matrix1[m][n], int matrix2[m][n], int matrixS[m][n]);
void func6(int m1, int n1, int m2, int n2, int matrix1[m1][n1], int matrix2[m2][n2], int matrixM[m1][n2]);
void func7(int m, int n, int matrix[][n], int matrixD[][m], int degree);


int main(){
  int m, n,a,b;
  scanf("%d%d", &m, &n);
  int matrix[m][n],
  matrixT[n][m],
  matrixD[m][m],
  matrixQ[m][n];
  int high=3, low=1;

  func1(high, low, m, n, matrix);
  scanf("%d%d", &a, &b);
    //func2(m,n,matrix);
    //printf ("\n");
  int matrix2[a][b],
  matrixM[m][b],
  matrixS[m][b];
  func1(high, low, m, n, matrix2);
    //func2(a, b, matrix2);
    //printf ("\n");
      //func31(m, n, matrix); func32();
  func4(m, n, matrix, matrixT);
    //func2(n,m,matrixT);
    //printf ("\n");
      //func5(m, n, matrix, matrix, matrixS); func2(m, n, matrixS);
  func6(m, n, n, m, matrix, matrixT, matrixM); // произведение обычной на транспонированную
    //func2(m,m,matrixM);
    //printf ("\n");
  func6(m,n,a,b,matrix,matrix2,matrixD);
  func7(m, m, matrixD, matrixQ, 2);
    //func2(m,m,matrixM);
    //printf ("\n");
  func5(m,m,matrixM,matrixQ,matrixS);
  func2(m, m, matrixS);
  return 0;
}

void func1(int high, int low, int m, int n, int matrix[][n]){
    int q=1;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            //matrix[i][j] = rand()%(high-low+1) + low;
            //matrix[i][j] = q++;
            scanf("%d", &matrix[i][j]);
        }
    }
}

void func2(int m, int n, int matrix[][n]){
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            printf ("%6d", matrix[i][j]);
        }
        printf ("\n");
    }
}

void func31(int m, int n, int matrix[][n]){
    FILE *f;
    f=fopen("f.txt", "w");
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            fprintf(f, "%6d", matrix[i][j]);
        }
    fprintf(f, "\n");
    }
    fprintf(f, "\n");
    fclose(f);
}

void func32(){
    FILE *f;
    f=fopen("f.txt", "r");
    int ch;
    while ((ch = getc(f)) != EOF) putchar(ch);
    printf("\n");
    fclose(f);
}

void func4(int m, int n, int matrix[m][n], int matrixT[n][m]){
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            matrixT[j][i]=matrix[i][j];
        }
    }
}

void func5(int m, int n, int matrix1[m][n], int matrix2[m][n], int matrixS[m][n]){
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            matrixS[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }
}

void func6(int m1, int n1, int m2, int n2, int matrix1[m1][n1], int matrix2[m2][n2], int matrixM[m1][n2]){
    for (int i=0; i<m1; i++)
    {
        for(int k=0; k<n2; k++)
        {
            matrixM[i][k]=0;
            for (int j=0; j<n1; j++)
            {
                matrixM[i][k]+=matrix1[i][j]*matrix2[j][k];
            }
        }
    }
}

void func7(int m, int n, int matrix[][n], int matrixD[][m], int degree){
    int matrixDOP[m][n];
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            matrixDOP[i][j]=matrix[i][j];
        }
    }
    while(degree!=1)
    {
        for (int i=0; i<m; i++)
        {
            for(int k=0; k<n; k++)
            {
                matrixD[i][k]=0;
                for (int j=0; j<n; j++)
                {
                    matrixD[i][k]+=matrix[i][j]*matrixDOP[j][k];
                }
            }
        }
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                matrixDOP[i][j]=matrixD[i][j];
            }
        }
    degree-=1;
    }
}
