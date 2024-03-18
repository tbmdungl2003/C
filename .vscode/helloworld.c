#include <stdio.h>
#include<math.h>

int lapphuong( double m )
{
    return m * m * m ;
}

void uoc( int m)
{
    int i ;
    for (i =1 ;i<=sqrt(m);i=i+1)
        {
            if (m % i ==0)
            {
                printf("%lf, %lf ", i , m /i );
            }
        }
}

void bphoanhao( double m )
{
    int i ;
    for (i=1; i<=m; i=i+1)
    {
        printf("%d", i*i);
    }
}

int main ()

{   
    int i;
    printf("Moi ban nhap yeu cau muon thuc hien \n 1: tinh lap phuong \n 2: tim uoc\n 3: tim n so binh phuong hoan hao\n ");
    scanf("%d",&i);
    if ( i ==1)
    {   
        double  n;
        printf("moi ban nhap so can tinh");
        scanf("%lf",n);
        printf("lap phuong của %lf la %lf",n, lapphuong(n));
    }
        else
        {
            if (i ==2)  
                {   int n;
                    printf("Moi ban tim so can tim uoc");
                    scanf("%d",&n);
                    printf(" so uoc cua %d la : \n",n);
                    uoc(n);
                }
            else     
                {   double n; 
                    printf("MOi ban nhap n");
                    scanf("%lf",&n);
                    bphoanhao(n);
                }
        }
        
    return 0;
}