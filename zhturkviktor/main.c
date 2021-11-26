#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tomb_feltoltes(int* tomb,int n);
void tomb_kiiras(int* tomb,int n);
void forditott_kiiratas(int* tomb,int n);
void index_beolvasas(int* index);
int index_ismetlodes(int index,int* tomb,int n);

int main()
{
    const int n = 6;
    int tomb[n];
    int index;

    tomb_feltoltes(tomb,n);
    tomb_kiiras(tomb,n);
    forditott_kiiratas(tomb,n);
    index_beolvasas(&index);
    printf("%d-szor/szer szerepel a beolvasott index elem erteke",index_ismetlodes(index,tomb,n));

    return 0;
}

void tomb_feltoltes(int* tomb, int n)
{
    srand(time(NULL));
    int upper=10,lower=1;
    int i;
    for(i=0;i<n;i++)
    {
        tomb[i] = rand()%(upper-lower+1)+lower;
    }
}

void forditott_kiiratas(int* tomb,int n)
{
    printf("\nTomb forditva: ");
    int i;
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",tomb[i]);
    }
}

void index_beolvasas(int* index)
{
    int ok;
    do
    {
        ok=1;
        printf("\nKerek egy ervenyes tomb indexet(0-5):");
        if(scanf("%d",index)!=1 || *index<0 || *index>5)
        {
            ok=0;
            printf("\nHibas adat.");
            while(getchar()!='\n');
        }
    }while(!ok);
}

int index_ismetlodes(int index,int* tomb,int n)
{
    int ismetlodes=0;
    int i;
    for(i=0;i<n;i++)
    {
        if(tomb[index] == tomb[i])
        {
            ismetlodes++;
        }

    }
    return ismetlodes;
}

void tomb_kiiras(int* tomb,int n)
{
    printf("Tomb elemei:   ");
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",tomb[i]);
    }
}
