#include<stdio.h>

double* maximum(double* a, int size){
    double *max;
    double *p; 
    int i;
    max=a;
    if (a==NULL) return NULL;
    for(p=a+1; p<a+size; p++) 
        if (*p > *max){
                max = p;
            }
return max;
}

int main()
 {
    double arr[10];
    int i,n;

    printf("Nhap so phan tu cua mang"); scanf("%d",&n);
    for (i=0;   i<n;   i++) 
       scanf("%lf",&arr[i]);
    printf("phan tu lon nhat trong mang là %lf", *maximum(arr,n));
    return 0;
 }
