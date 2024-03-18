//DE CUOI KI 20202

#include <stdio.h>
#include <string.h>

typedef struct 
{
	int id;
	char nation[4];
    char name[30];
	float r[3];
    float fr;
} person;

person  list[20];
int so_vdv;

int check_ID(int i)
{
    if(i == 1)
    {
        return 1;
    }
    for (int j = 1; j < i; j++)
    {
        
        if (list[j].id == list[i].id)
        {
            return 0
        }
    }
    return 1;
}

void nhapthongtin()
{
    while (1)
    {
        printf("Nhap vao so van dong vien thi dau:\n");
        fflush(stdin);
        scanf("%d", &so_vdv);
        if(so_vdv <= 0)
        {
            printf("\n<!> So van dong vien phai lon hon 0!\n");
            printf(">>Xin vui long nhap lai>>\n");
        }
        else
        {
            break;
        }
    }
    for (int i = 1; i <= so_vdv; ++i)
    {
        while (1)
        {
            printf("ID %d: ", i);
            fflush(stdin);
            scanf("%d", &list[i].id);
            if(check_ID(i) == 0)
            {
                printf("\n<!> ID bi trung!\n\n");
            }
            else
            {
                break;
            }
        }
        
        printf("Nation: ");
        scanf("%s", list[i].nation);
        fflush(stdin);
        printf("Name: ");
        fflush(stdin);
        scanf("%[^\n]%*c", list[i].name);
    }
}

void inthongtin()
{
    printf("ID    Nation  Name                R1    R2    R3    FR\n");
    for (int i = 1; i <= so_vdv; ++i)
    {
        printf("%-2d    %-3s   %-16s\n", list[i].id, list[i].nation, list[i].name);                
        
    }
    
}

void tinh_FR(int i)
{
    
        if (list[i].r[0] >= list[i].r[1])
        {
            if (list[i].r[0] >= list[i].r[2])
            {
                list[i].fr = list[i].r[0];
            }
            else
            {
                list[i].fr = list[i].r[2];
            }
        }
        else if(list[i].r[1] > list[i].r[0])
        {
            if (list[i].r[1] >= list[i].r[2])
            {
                list[i].fr = list[i].r[1];
            }
            else
            {
                list[i].fr = list[i].r[2];
            }
        }
    
}

void thidau()
{
    for (int i = 1; i <= 3; ++i) // i la luot 
                                // j la nguoi
    {
        //luot 
        printf("Luot %d\n", i);
        for (int j = 1; j <= so_vdv; ++j)
        {
            printf("Thi sinh %d: %s\n", j, list[j].name);
            while (1)
            {
                printf("R%d: ", i);
                fflush(stdin);
                scanf("%f", &list[j].r[i-1]);
                if(list[j].r[i-1] < 0 || list[j].r[i-1] >= 20)
                {
                    printf("\n<!> Nhap khong hop le!\n\n");
                }
                else
                {
                    break;
                }
            }
            tinh_FR(j);
        }
        if (i == 1)
        {
            printf("\n");
            printf("Ket qua luot %d\n", i);
            printf("ID    Nation  Name                R1    R2    R3    FR\n");
            for (int k = 1; k <= so_vdv; ++k)
            {
            printf("%-2d    %-3s   %-16s    %3.2f   \n", list[k].id, list[k].nation, list[k].name, list[k].r[i-1]);                
            }
            
        }
        else if (i == 2)
        {
            printf("\n");
            printf("Ket qua luot %d\n", i);
            printf("ID    Nation  Name                R1    R2    R3    FR\n");
            for (int k = 1; k <= so_vdv; ++k)
            {
            printf("%-2d    %-3s   %-16s    %3.2f   %3.2f   \n", list[k].id, list[k].nation, list[k].name, list[k].r[0],list[k].r[i-1]);                
            }
        }
        else if(i == 3)
        {
            printf("\n");
            printf("Ket qua luot %d\n", i);
            printf("ID    Nation  Name                R1    R2    R3    FR\n");
            for (int k = 1; k <= so_vdv; ++k)
            {
            printf("%-2d    %-3s   %-16s    %3.2f   %3.2f   %3.2f   %3.2f\n", list[k].id, list[k].nation, list[k].name, list[k].r[0],list[k].r[1],list[k].r[i-1], list[k].fr);                
            }
        }
    }
}

void search_name()
{
    int dem = 0;
    char timkiem[30];
    printf("Nhap ten van dong vien can tim: ");
    fflush(stdin);
    scanf("%[^\n]%*c", timkiem);
    printf("ID    Nation  Name                R1    R2    R3    FR\n");
    for (int i = 1; i <=so_vdv; ++i)
    {
        if(stricmp(list[i].name, timkiem) == 0)
        {
            dem++;
                printf("%-2d    %-3s   %-16s    %3.2f   %3.2f   %3.2f   %3.2f\n", list[i].id, list[i].nation, list[i].name, list[i].r[0],list[i].r[1],list[i].r[i-1], list[i].fr);                
                break;

        }
    }
    if (dem == 0)
    {
        printf("\nKhong co van dong vien nao duoc tim thay!\n\n");
    }
}

void search_nation()
{
    int count = 0;
    char search[30];
    printf("Nhap quoc tich cua van dong vien can tim: ");
    fflush(stdin);
    scanf("%[^\n]%*c", search);
    printf("ID    Nation  Name                R1    R2    R3    FR\n");
    for (int i = 1; i <=so_vdv; ++i)
    {
        if(stricmp(list[i].name, search) == 0)
        {
            count++;
                        printf("%-2d    %-3s   %-16s    %3.2f   %3.2f   %3.2f   %3.2f\n", list[i].id, list[i].nation, list[i].name, list[i].r[0],list[i].r[1],list[i].r[i-1], list[i].fr);                
            break;
        }
    }
    if (count == 0)
    {
        printf("\nKhong co van dong vien nao duoc tim thay!\n\n");
    }
}

void in_ketqua()
{
    for (int i = 1; i <= so_vdv; ++i)
    {
        for (int j = i+1; j <= so_vdv; ++j)
        {
            if(list[i].fr <= list[j].fr)
            {
                person tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
        
    }

    printf("ID    Nation  Name                R1    R2    R3    FR\n");
    for (int i = 1; i <= so_vdv; ++i)
    {
            printf("%-2d     %-3s     %16s    %3.2f   %3.2f   %3.2f   %3.2f\n", list[i].id, list[i].nation, list[i].name, list[i].r[0],list[i].r[1],list[i].r[2], list[i].fr);                

        
    }
}
void main()
{
    int chon;
    int tim;
    int luachon = 0;
    printf("\t\t\t***CHUONG TRINH ___***\n");
    printf("<Menu chuong trinh>\n");
    do
    {
        printf("<1> Nhap thong tin truoc khi thi dau\n");
        printf("<2> Bang thong tin van dong vien\n");
        printf("<3> Thi dau\n");
        printf("<4> Tim kiem theo lua chon\n");
        printf("<5> Ket qua vong chung ket\n");
        printf("<6> Thoat\n");
        printf("\nHay nhap lua chon cua ban: ");
        scanf("%d", &chon);
        switch (chon)
        {
        case 1:
            nhapthongtin();
            luachon++;
            break;
        case 2:
            if (luachon != 0)
            {
                inthongtin();
            }
            else
            {
                printf("\n<!> Phai nhap thong tin van dong vien truoc\n\n");
            }
            break;
        case 3:
            if (luachon != 0)
            {
                thidau();
            }
            else
            {
                printf("\n<!> Phai nhap thong tin van dong vien truoc\n\n");
            }
            break;
        case 4:
            if (luachon != 0)
            {
                printf("<7> De tim theo ten\n<8> de tim theo quoc tich\n<9> De thoat\n");
                fflush(stdin);
                scanf("%d", &tim);
                do
                {
                    switch (tim)
                    {
                    case 7:
                        search_name();
                        break;
                    case 8:
                        search_nation();
                        break;
                    case 9:
                        break;
                    default:
                        break;
                    }
                } while (tim != 9);
            }
            else
            {
                printf("\n<!> Phai nhap thong tin van dong vien truoc\n\n");

            }
            
            break;
        case 5:
            if (luachon != 0)
            {    
                in_ketqua();
            }
            else
            {
                printf("\n<!> Phai nhap thong tin van dong vien truoc\n\n");

            }
            break;
        case 6:
            break;
        default:
            printf("Ban nen chon tu 1 -> 5");
            break;
        }
    } while (chon != 6);
    
}




// 
//DE THUC HANH C 2014-2015

#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define max 100

typedef struct 
{
    long int mssv;
    char hodem[30];
    char ten[12];
    float hd, pb, hd1, hd2, hd3;
    float gk, ck;
} sinhvien;

char ten[19][30];
sinhvien diem[19]; //máº£ng bao gá»“m cÃ¡c Ä‘iá»ƒm cá»§a sinh viÃªn

void input(sinhvien diem[], int i, int m);
void gkck(sinhvien diem[], int m);
void output(sinhvien diem[], int j);
void baove(sinhvien diem[], int j, int m);
void sapxep(sinhvien diem[], int m);


void main()
{
    int a;
    int n; //Vá»›i n lÃ  sá»‘ sinh viÃªn nháº­p thÃªm
    int i = 0;
    int m = 0;// Vá»›i m lÃ  sá»‘ sinh viÃªn sau khi Ä‘Ã£ nháº­p thÃªm
    int chon; // chon lÃ  biáº¿n menu
    int j;//Vá»›i j lÃ  sá»‘ sinh viÃªn cháº¡y tá»« 0
    printf("\t\t\t\t>>CHUONG TRINH TINH DIEM TOT NGHIEP SINH VIEN<<\n\n");
    do
    {

    printf("Menu:\n");
    printf("1 >> Nhap diem cho sinh vien\n2 >> Bang sinh vien tot nghiep\n3 >> Sap xep danh sach theo ten\n");
    scanf("%d", &chon);
    
    switch (chon)
    {
    case 1:
    do
    {
        do
        {
            printf("Nhap so sinh vien:\n");
            scanf("%d", &n);
            if (n <= 0 )
            {
                printf("Ban da nhap sai!\nVui long nhap lai.\n");
            }
        } while (n <= 0);
        m += n;
            if (m >= 20)
            {
                printf("So sinh vien qua gioi han! Vui long nhap lai.\n");
                m -= n;
                a = 1;
            } 
            else
            {
                a = 0;
            }
    } while (a != 0);

    for (; i < m ; i++)
    {
        input(diem, i, m);
    }
    i = i + (n-2);

    gkck(diem, m);

    for ( j = 0; j < m; j++)
    {
        output(diem, j);
    }
        break;
    case 2:
        baove(diem, j, m);
        break;
    case 3:
        sapxep(diem, m);
        for ( j = 0; j < m; j++)
        {
            output(diem, j);
        }
        break;
    case 4:
        printf("\t\t\t\t>>Exit>>\n");
        break;
    default:
        break;
    }

    } while (chon != 4);
}


void input(sinhvien diem[], int i, int m)  //Vá»›i i lÃ  sá»‘ sinh viÃªn cháº¡y tá»« 0 
{
    printf("Sinh vien %d:\n", i+1);
        for (; i < m; i++)
        {
            printf("MSSV(Chi 5 so): ");
            fflush(stdin);
            scanf("%ld", &diem[i].mssv);
            if(diem[i].mssv == diem[i-1].mssv)
            {
                printf("Ban da nhap sai MSSV! Vui long nhap lai.\n");
                i--;
            }
            else
            {
                break;
            }
        }
    printf("Ho va ten dem: ");
    fflush(stdin);
    scanf("%[^\n]%*c", &diem[i].hodem);
    printf("Ten: ");
    fflush(stdin);
    scanf("%[^\n]%*c", &diem[i].ten);

    do
    {
        printf("Diem HD: ");
        fflush(stdin);
        scanf("%f", &diem[i].hd);
        if (diem[i].hd < 0.0 || diem[i].hd >10.0)
        {
            printf("Nhap sai! Vui long nhap lai.\n");
        }
    } while (diem[i].hd < 0.0 || diem[i].hd > 10.0);

    do
    {
        printf("Diem PB: ");
        fflush(stdin);
        scanf("%f", &diem[i].pb);
        if (diem[i].pb < 0.0 || diem[i].pb >10.0)
        {
            printf("Nhap sai! Vui long nhap lai.\n");
        }
    } while (diem[i].pb < 0.0 || diem[i].pb > 10.0);

    do
    {
        printf("Diem HD1: ");
        fflush(stdin);
        scanf("%f", &diem[i].hd1);
        if (diem[i].hd1 < 0.0 || diem[i].hd1 >10.0)
        {
            printf("Nhap sai! Vui long nhap lai.\n");
        }
    } while (diem[i].hd1 < 0.0 || diem[i].hd1 > 10.0);

    do
    {
        printf("Diem HD2: ");
        fflush(stdin);
        scanf("%f", &diem[i].hd2);
        if (diem[i].hd2 < 0.0 || diem[i].hd2 >10.0)
        {
            printf("Nhap sai! Vui long nhap lai.\n");
        }
    } while (diem[i].hd2 < 0.0 || diem[i].hd2 > 10.0);

    do
    {
        printf("Diem HD3: ");
        fflush(stdin);
        scanf("%f", &diem[i].hd3);
        if (diem[i].hd3 < 0.0 || diem[i].hd3 >10.0)
        {
            printf("Nhap sai! Vui long nhap lai.\n");
        }
    } while (diem[i].hd3 < 0.0 || diem[i].hd3 > 10.0);       
}

void gkck(sinhvien diem[], int m)
{
    for (int i = 0; i < m; i++)
    {
        if (diem[i].hd <= 5.5 || diem[i].pb <= 5.5 || diem[i].hd1 <= 5.5 || diem[i].hd2 <= 5.5 || diem[i].hd3 <= 5.5)
        {
            diem[i].gk = 0;
            diem[i].ck = 0;
        }
        else
        {
            diem[i].gk = (diem[i].hd + diem[i].pb)/2;
            diem[i].ck = (diem[i].hd1 + diem[i].hd2 + diem[i].hd3)/3;
        }
    }
}

void output(sinhvien diem[], int j) // HÃ m in ra thÃ´ng tin
{

    printf("MSSV      Ho va ten                HD  PB  HD1  HD2  HD3  GIUAKY  CUOIKY\n");
    printf("%ld   %s %s               %.1f  %.1f  %.1f  %.1f  %.1f  %.1f  %.1f\n", diem[j].mssv, diem[j].hodem, diem[j].ten, diem[j].hd, diem[j].pb, diem[j].hd1, diem[j].hd2, diem[j].hd3, diem[j].gk, diem[j].ck);
    
}

void baove(sinhvien diem[], int j, int m)
{
    for (j = 0; j < m; j++)
    {
        if (diem[j].gk != 0)
        {
            output(diem, j);
        }
    }
}

void sapxep(sinhvien diem[], int m)
{
    sinhvien tmp;
    sinhvien tmp1;
    for (int i = 0; i < m; i++)
    {
        for (int j = i+1; j < m; j++)
        {
            if (strcmp(diem[j].ten, diem[i].ten) == 0)
            {
                if (strcmp(diem[j].hodem, diem[i].hodem) < 0)
                {
                    tmp = diem[i];
                    diem[i] = diem[j];
                    diem[j] = tmp;
                }
            } 
            else if(strcmp(diem[j].ten, diem[i].ten) < 0)
            {
                
                    tmp1 = diem[i];
                    diem[i] = diem[j];
                    diem[j] = tmp1;
                
            }
        }
    }
}