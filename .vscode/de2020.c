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

node* top;
void initList(){
    top=NULL;
    
}
int listEmpty(){
    return top==NULL;  
}

node* makeNode(char* name,int hour,int min ){
    node* p=(node*)malloc(sizeof(node));
    strcpy(p->name,name);
    p->hour=hour;
    p->min=min;
    
    p->next=NULL;
    return p;
}
void inserttop(char* name, int hour ,int min){
    node* p=makeNode(name,hour,min);
    if(top==NULL){
        top=p,
    }else{
        top->next=p;
        top=p;
    }

}


void printList(){
    node* p=top;
    for(node* p=top;p!=NULL;p=p->next){
        printf("%s %d %d\n",p->name,p->hour,p->min);
    }
    
}
void Findname(){
    char name[256];
    scanf("%s",name);
    int count=0;
    

    for(node* p=top;p!=NULL;p=p->next){
        if(strcmp(p->name,name)==0){
            printf("%d %d\n",p->hour,p->min);
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


void Findtime(){
    int hour,min;
    do{
        printf("Nhap thoi gian");
        scanf("%d%d",&hour,&min);
    }while (hour<0||hour>24||min<0||min>60);

    

    if(sosanh(top,hour,min)==1){
        printf("khong ton tai");
    }
    

    for(node* p=top;p->next!=NULL;p=p->next){
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
        inserttop(name,data0,data);
    }
    fclose(f);
}
void Load(){
    char filename[256];
    scanf("%s",filename);
    load(filename);
}





int main(){
    initList();
    printf("=====================\n");
    int c;
    while (1)
    {
        printf("\t\tCHUONG TRINH TRUY VET COVID19\t\t\n");
        printf("1.Nap file log lich su di chuyen\n");
        printf("2.In ra lich su di chuyen\n");
        printf("3.Tim kiem lich su theo di chuyen\n");
        printf("4.Tim kiem lich su theo thoi gian\n");
        printf("5.Thoat\n");
        printf("Enter: ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            Load();
            break;
        case 2:
            printList();
            break;
        case 3:
            Findname();
            break;
        case 4: 
            Findtime();
            break;
        case 5:
            return 0;
            break;
        default:
            break;
        }
    }
}