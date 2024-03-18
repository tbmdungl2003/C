//De thi cuoi ky
#include<stdio.h>
#include<string.h>
#include <stdio_ext.h>
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
        printf("Enter Name:");  fgets(SV1[i].name, 31, stdin);
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
    int exit = 0 , lchon =0;
    while (!exit){
        puts("MENU CHUC NANG");
        puts("Cac lenh thuc hien:\n1.Nhap thong tin lop hoc\n2. In thong tin lop hoc\n3.Tim kiem theo ten\n4.Sap xep")
        printf("Nhap so thuc tu lenh ");
        scanf("%d",&lchon);
        switch (lchon){
            case 1:
                Nhap();
                break;
            case 2:
                Xuat();
                break;
            case 3:
                Timkiem();
                break;
            case 4:
                Sapxep();
                break;
            case 5:
                exit = 1;
                break;
            default:
                puts("Ma da nhap khong hop le! Vui long nhap lai");
                break;
    }
}
}



