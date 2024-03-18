//De thi cuoi ky
#include<stdio.h>
#include<string.h>
//#include <stdio_ext.h>
typedef struct 
{
    char name[31];
    float   Grade;
} lophoc;

lophoc SV1[41],SV2[41];

void Data ( lophoc &SV1 )
{   
	printf("Enter name: ");
	gets(SV1.name);
}
void nhap(){
    int n=0,i;
    printf("Nhap so luong sinh vien lop 1") scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Nhap thong tin sinh vien thu %d lop 1:",i)
		Data(SV1[i])
        printf("/n");
    }
    printf("Nhap so luong sinh vien lop 2") scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Nhap thong tin sinh vien thu %d lop 2:",i)
        Data(SV2[i]);
        printf("/n");
    }
}

int main()
{
	nhap();
	return 0;
}
