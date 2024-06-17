#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include<time.h>
#include <unistd.h>
struct studCard {
    char SurName[20];
    char Name[20];
    struct adres {
        char city[20];
        char street[20];
        int house;
        int flat;
    } adr;
    char section[20];
    int ball;
};




void func1(int n, int fin, struct studCard stud[n], char m[20], int *pr)
{
    int b[n],i,j;
    for (i=0;i<n;i++)
        b[i]=0;
    for (i=0;i<n;i++){
            if ( strcmp(stud[i].section, m)==0)
                for (j=0; j<5; j++)
                    if (stud[i].ball>b[j])
                {
                    b[j+4]=b[j+3];
                    b[j+3]=b[j+2];
                    b[j+2]=b[j+1];
                    b[j+1]=b[j];
                    b[j]=stud[i].ball;
                    break;
                }

    }
    *pr=b[4];
    printf("%s %d\n", m, *pr);
}

void func2(int n, int fin, int pr, struct studCard stud[n], char m[20])
{ int i, k;
k=0;
printf("%s\n", m);
for (i=0;i<n;i++)
{
if ((stud[i].ball>=pr) && ( strcmp(stud[i].section, m)==0))
{k++;
printf(" %s\n",stud[i].SurName);
stud[i].SurName[0]='0';
if (k==5)
break; }
}
}

void func3(int n,  struct studCard stud[n])
{ int i,j,max;
char m[n];
for (i=0;i<n;i++)
    m[i]=1;
max=0;
for (i=0;i<n;i++)
{
    if (stud[i].SurName[0]=='0')
        for  (j=i+1;j<n;j++)
            if (stud[j].SurName[0]=='0')
            {if (strcmp(stud[i].adr.city,stud[j].adr.city)==0)
                        m[i]++;
                  if (m[i]> max)
                        max=m[i];
               }
}

for (i=0;i<n;i++)
    if (m[i]==max)
    printf("%s ",stud[i].adr.city);
printf("\n");
}


int main()
{
    int n; scanf("%d", &n);
    int fin, pr1, pr2, pr3;
    struct studCard stud[n];

    /*
    FILE *f;
    f=fopen("file.txt", "r");
    int n=0; while(!feof(f)){
        fscanf(f, "%s", stud[n].SurName);
        fscanf(f, "%s", stud[n].Name);
        fscanf(f, "%s", stud[n].adr.city);
        fscanf(f, "%s", stud[n].adr.street);
        fscanf(f, "%d", &stud[n].adr.house);
        fscanf(f, "%d", &stud[n].adr.flat);
        fscanf(f, "%s", stud[n].section);
        fscanf(f, "%d", &stud[n].ball);
        n++;
    }
    fclose(f);
    */

    for(int i=0; i<n; i++){
        scanf("%s", stud[i].SurName);
        scanf("%s", stud[i].Name);
        scanf("%s", stud[i].adr.city);
        scanf("%s", stud[i].adr.street);
        scanf("%d", &stud[i].adr.house);
        scanf("%d", &stud[i].adr.flat);
        scanf("%s", stud[i].section);
        scanf("%d", &stud[i].ball);
    }
    scanf("%d", &fin);



    func1(n, fin, stud, "Physics", &pr1);
    func1(n, fin, stud, "Biology", &pr2);
    func1(n, fin, stud, "History", &pr3);
    printf("\n");

    func2(n, fin, pr1, stud, "Physics");
    func2(n, fin, pr2, stud, "Biology");
    func2(n, fin, pr3, stud, "History");
    printf("\n");

   func3(n, stud);

    return 0;
}
/*Пример
Ivanov Alex Moscow Lenina 1 2 Physics 250
Petrov Boris Saint-Petersburg Nevskaya 2 3 History 270
Sidorov Dmitry Moscow Tverskaya 3 4 Biology 280
Kuznetsov Elena Kazan Kazanskaya 4 5 Physics 290
Popov Sergey Moscow Presnenskaya 5 6 History 260
Morozova Anna Sochi Sochinskaya 6 7 Biology 270
Novikov Ivan Moscow Arbatskaya 7 8 Physics 280
Fedorova Maria Novosibirsk Novosibirskaya 8 9 History 250
Egorov Alexey Moscow Kutuzovckaya 9 10 Biology 290
Volkova Anastasia Samara Samarskaya 10 11 Physics 270
Smirnov Dmitry Moscow Lenina 11 12 History 255
Kuznetsova Maria Saint-Petersburg Nevskaya 12 13 Biology 265
Ivanova Anastasia Moscow Tverskaya 13 14 Physics 275
Petrova Elena Kazan Kazanskaya 14 15 History 285
Sidorova Anna Moscow Presnenskaya 15 16 Biology 265
*/