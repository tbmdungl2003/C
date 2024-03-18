#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct lophoc{  
	char name[31];
	float grade[3];
};

void nhap1sv ( lophoc &sv) 
{	
	printf("Enter name: ");
	gets(sv.name);
	printf("Enter Grade: ")'
	gets(sv.grade);
}

void nhapsv ( lophoc SV[] , int n )
{
	for(int i=0;i<n;i++)
	{
		printf("Nhap thong tin sinh vien  thu %d: ",i+1);
		nhap1sv(sv[i]);
		printf("\n");
	}
}
void nhapdiem(lophoc sv[],int n)
{
	 for(int i=0;i<n;i++)
	 {
	     printf("Nhap diem thi lan 1 cua vdv thu %d: ",i+1);
	     scanf("%f",&sv[i].a[0]);
	 }
}
void xuat1 ( lophoc sv[],int n)
{   
     printf("Danh sach thi sau lan thi thu nhat:\n");
     printf("%-8s%-10s%-20s%-8s%-8s%-8s%-8s","ID","Nation","Name","R1","R2","R3","FR");
	 for(int i=0;i<n;i++)
	 {
	 	printf("\n%-8d%-10s%-20s%-5.2f",vdv[i].id,vdv[i].nation,vdv[i].name,vdv[i].a[0]);
	 }
}

int main()
{
  int n;
  
  do
   {
    printf("Nhap so luong sinh vien lop 1: ");
	scanf("%d",&n);
   }while(n<=0); 
   
   lophoc sv[n];
   nhapsv(sv,n);
   nhapdiem(sv,n);
   xuat1(sv,n);
   printf("\n");
   
}
