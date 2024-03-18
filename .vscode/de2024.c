#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40

typedef struct Node
{
   char name[MAX];
   
   int data0;
   int data;
   struct Node* next; 
}node;

node* last;
node* first;

void initList(){
    first=NULL;
    last=NULL;
}
int listEmpty(){
    return first==NULL&&last==NULL;
}

node* makeNode(char* name,int data0,int data){
    node* p=(node*)malloc(sizeof(node));
    strcpy(p->name,name);
    p->data0=data0;
    p->data=data;
    
    p->next=NULL;
    return p;
}
void insertLast(char* name, int data0 ,int data){
    node* p=makeNode(name,data0,data);
    if(last==NULL&&first==NULL){
        first=p,
        last=p;
    }else{
        last->next=p;
        last=p;
    }

}


void printList(){
    node* p=first;
    for(node* p=first;p!=NULL;p=p->next){
        printf("%s %d %d\n",p->name,p->data0,p->data);
    }
    
}
void Tktheoten(){
    char name[256];
    scanf("%s",name);
    int count=0;
    

    for(node* p=first;p!=NULL;p=p->next){
        if(strcmp(p->name,name)==0){
            printf("%d %d\n",p->data0,p->data);
            count++;
        }
    }
if(count==0){
    printf("khong tim thay");
} 
}

int sosanh(node* a,int dt1,int dt2){
    if((a->data0>dt1)||(a->data0==dt1&&a->data>=dt2)){
        return 1;
    }
    return 0;
} 
int sosanhnho(node* a,int dt1,int dt2){
    if((a->data0<dt1)||(a->data0==dt1&&a->data<=dt2)){
        return 1;
    }
    return 0;
} 


void Tktheotime(){
    int hour,min;
    do{
        printf("Nhap thoi gian");
        scanf("%d%d",&hour,&min);
    }while (hour<0||hour>24||min<0||min>60);

    

    if(sosanh(first,hour,min)==1){
        printf("khong ton tai");
    }
    

    for(node* p=first;p->next!=NULL;p=p->next){
        if((sosanh(p->next,hour,min)==1)&&sosanhnho(p,hour,min)==1){
            printf("%s",p->name);
        }
    }

}

void load(char* filename){
    FILE* f=fopen(filename,"r");
    if(f==NULL) printf("Not found\n");
    while (!feof(f))
    {
        char name[256];
        int data,data0;
        fscanf(f,"%s%d%d",name,&data0,&data);
        insertLast(name,data0,data);
    }
    fclose(f);
}
void Nhap(){
    char filename[256];
    scanf("%s",filename);
    load(filename);
}





int main(){
    initList();
    printf("====================\n");
    int c;
    while (1)
    {
        printf("\t\tCHUONG TRINH TRUY VET COVID19\t\t\n");
        printf("1.Nap file log lich su di chuyen\n");
        printf("2.In ra lich su di chuyen\n");
        printf("3.Tim kiem lich su theo dia diem\n");
        printf("4.Tim kiem lich su theo thoi gian\n");
        printf("5.Thoat\n");
        printf("Enter: ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            Nhap();
            break;
        case 2:
            printList();
            break;
        case 3:
            Tktheoten();
            break;
        case 4: 
            Tktheotime();
            break;
        case 5:
            return 0;
            break;
        default:
            break;
        }
    }
    
}