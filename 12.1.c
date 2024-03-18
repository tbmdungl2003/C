#include<stdio.h>

int counteven(int* arr, int size){
int i;
int count =0;
for (i=0; i<size; i++)
if (*(arr+i)%2==0) count++;
return count;
}

int main()
 {
    int arr[10];
    int i,n;

    printf("Nhap so phan tu cua mang"); scanf("%d",&n);
    for (i=0;   i<n;   i++) 
        scanf("%d",&arr[i]);
    printf("So phan tu chan cua mang la %d", counteven(arr,n));
    return 0;
 }