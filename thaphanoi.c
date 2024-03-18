#include<stdio.h>

int main()
{
    int n,k,i,j;

    n=4;
    k=2;
    for (i=1; i<=n-k; i++){
        for (j=i+2;j<=n;j++)
            printf("(%d,%d)",i,j);

    }
 return 0;
}