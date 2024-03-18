#include<stdio.h>

void main()
{
    int a[100],n,i,k;
    printf("n = "); scanf("%d",&n);
    
    for( i=0;i<n;i++)
    {
        printf("\na[%d] = ",i);scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        printf("\n%d",a[i]);
        for (int j=i;j<n-1;j++)
            {
                printf("\n");
                for( k=i;k<=j+1;k++)
                printf("%d\t",a[k]);
            }
    }
}
