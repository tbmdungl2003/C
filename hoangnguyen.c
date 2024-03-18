#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct vandong_vien{  
	int id;
	char nation[4], name[31];
	float a[3];
};

void nhap1vdv ( vandong_vien &vdv )
{   
	printf("\nEnter ID: ");
	scanf("%d",&vdv.id);
    getchar();
	printf("Enter nation: ");
	gets(vdv.nation);
	
	printf("Enter name: ");
	gets(vdv.name);
}

void nhapvdv ( vandong_vien vdv[] , int n )
{
	for(int i=0;i<n;i++)
	{
		printf("Nhap thong tin van dong vien thu %d: ",i+1);
		nhap1vdv(vdv[i]);
		printf("\n");
	}
}

void nhapdiemlan1 (vandong_vien vdv[],int n)
{
	 for(int i=0;i<n;i++)
	 {
	     printf("Nhap diem thi lan 1 cua vdv thu %d: ",i+1);
	     scanf("%f",&vdv[i].a[0]);
	 }
}

void xuat1 ( vandong_vien vdv[],int n)
{   
     printf("Danh sach thi sau lan thi thu nhat:\n");
     printf("%-8s%-10s%-20s%-8s%-8s%-8s%-8s","ID","Nation","Name","R1","R2","R3","FR");
	 for(int i=0;i<n;i++)
	 {
	 	printf("\n%-8d%-10s%-20s%-5.2f",vdv[i].id,vdv[i].nation,vdv[i].name,vdv[i].a[0]);
	 }
}

void nhapdiemlan2 (vandong_vien vdv[],int n)
{
	 for(int i=0;i<n;i++)
	 {
	     printf("Nhap diem thi lan 2 cua vdv thu %d: ",i+1);
	     scanf("%f",&vdv[i].a[1]);
	 }
}

void xuat2 ( vandong_vien vdv[],int n)
{   
     printf("Danh sach thi sau lan thi thu nhat:\n");
     printf("%-8s%-10s%-20s%-8s%-8s%-8s%-8s","ID","Nation","Name","R1","R2","R3","FR");
	 for(int i=0;i<n;i++)
	 {
	 	printf("\n%-8d%-10s%-20s%-8.2f%-5.2f",vdv[i].id,vdv[i].nation,vdv[i].name,vdv[i].a[0] , vdv[i].a[1]);
	 }
}

void nhapdiemlan3 (vandong_vien vdv[],int n)
{
	 for(int i=0;i<n;i++)
	 {
	     printf("Nhap diem thi lan 3 cua vdv thu %d: ",i+1);
	     scanf("%f",&vdv[i].a[2]);
	 }
}

void xuat3 ( vandong_vien vdv[],int n)
{   
     printf("Danh sach thi sau lan thi thu nhat:\n");
     printf("%-8s%-10s%-20s%-8s%-8s%-8s%-8s","ID","Nation","Name","R1","R2","R3","FR");
	 for(int i=0;i<n;i++)
	 {
	 	printf("\n%-8d%-10s%-20s%-8.2f%-8.2f%-5.2f",vdv[i].id,vdv[i].nation,vdv[i].name,vdv[i].a[0]  ,vdv[i].a[1],vdv[i].a[2]);
	 }
}
int main()
{
  int n;
  
  do
   {
    printf("Nhap so luong van dong vien: ");
	scanf("%d",&n);
   }while(n<=0); 
   
   vandong_vien vdv[n];
   nhapvdv(vdv,n);
   nhapdiemlan1(vdv,n);
   xuat1(vdv,n);
   printf("\n");
   nhapdiemlan2(vdv,n);
   xuat2(vdv,n);
   printf("\n");
   nhapdiemlan3(vdv,n);
   xuat3(vdv,n);
}