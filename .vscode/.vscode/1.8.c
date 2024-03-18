#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
        double  width, height;
        if ( argc!=3){
            printf("nhap sai");
            printf("CORRECT SYNAX: RECT <WIDTH> <HEIGHT?>\n");
            return 1;
        }
 width =atof(argv[1]);
 height = atof(argv[2]);
 printf("The rectangle's area is %f\n", width *height);
 printf("The rectangle's perimeter is %f\n",2*(height+width));
 return 0;
 }