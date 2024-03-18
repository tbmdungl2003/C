// Sap xep mang theo thu tu tang dan

#include <stdio.h>

void swap(int &a, int &b)
{
	int tam = a;
	a = b;
	b = tam;
}

void Sort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (A[j] > A[j + 1])
                swap(A[j], A[j + 1]); // d?i ch? A[j] và A[j + 1]
}

int main()
{
	int a[100], n;
	printf("So phan tu cua mang:");
	scanf("%d", &n);
	printf("\nCac phan tu cua mang la:");
	for (int i=0;i<n;i++){
		printf("\na[%d] =", i);
		scanf("%d", &a[i]);
	}
	printf("Mang tang dan la:");
	Sort(a,n);
	for (int i=0;i<n;i++)
	printf("%d",a[i]);
}		
