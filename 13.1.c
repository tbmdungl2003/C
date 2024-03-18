#include<stdio.h>
#include<string.h>

int spacecounter(char inputline[])
{
int i = 0;
int count = 0;
while (inputline[i] != '\0') {
if (inputline[i] == ' ')
count++;
i++;
}
return count;
}



int main()
{
    char str[30];
    printf("Moi nhap xau :");
    gets(str);
    printf("So dau cach trong xau la %d", spacecounter(str));
return 0;
}