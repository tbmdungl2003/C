#include <stdio.h>
#include <math.h>

int main()

{
    int choice;

printf("Menu:"):
printf("\n1. Giai Phuong trinh bac 2");
printf("\n2. Tim max cua 3 so");
printf("\n3. Thoat chuong trinh");
printf("\n Hay lua chon chuc nang: ");
scanf("%d",&choice);
float a,b,c;
switch(choice)

{
 case 1:
  {

        printf("\n Nhap he so phuong trinh bac 2: ");

        scanf("%f%f%f",&a,&b,&c);

        float delta = b*b-4*a*c;

        if(delta<0)

            printf("\n Phuong trinh vo nghiem");

        else if (delta==0)

            printf("\n Phuong trinh co nghiem kep %.2f",(-b)/(2*a));

        else

            printf("\n Phuong trinh co 2 nghiem phan biet: %.2f va %.2f", (-b+sqrt(delta))/(2*a), (-b-sqrt(delta))/(2*a));

        break;

    }



    case 2:

    {

        printf("\n Nhap 3 so thuc: ");

        scanf("%f%f%f",&a,&b,&c);

        float max =a;

        if(max<b)

            max =b;

        if(max<c)

            max=c;

        printf("\n Gia tri lon nhat la: %.2f", max);

        break;

    }

    default:

        printf("\n Ket thuc!");

}

    return 0;

}

