#include<stdio.h>

int main()
{
    int n,i,tong; 

    printf("Moi ban nhâp giai thừa muốn tính");
    scanf("%d",&n);
    tong=1;
    for (i=1;i<=n;i=i+1)
    {
        tong=tong*i;
    }
    printf("Giai thua can tinh la %d",tong);

return 0;
}   