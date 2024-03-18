#include<stdio.h>

void getSale( double *arr, int size){
    int i;

    for (i =0 ; i<size; i++){
        printf("Nhap doanh so moi quy %d:", i+1);
        scanf("%lf",arr+i);
    }
}

double totalSale(double *arr, int size){
    int i;
    double sum;
    for (i=0; i<size ; i++){
        sum= sum + *arr;
        arr++;
    }
return sum;
}

int main()
{
    double sales[4];
    getSale(sales,4);
    printf("Tong doanh thu cua nam là: %0.1lf", totalSale(sales,4));
return 0;
}   