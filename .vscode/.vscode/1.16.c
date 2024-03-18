#include <stdio.h>
enum {SUCCESS, FAIL};
void CharReadWrite(FILE *f1, FILE *f2){
	int c;
	while ((c=fgetc(f2)) != EOF){
	fputc(c, f1);
	putchar(c); 
	}
}
void main(int argc, char *argv[]) {
	FILE *fptr1, *fptr2;
	int reval = SUCCESS;
	if ((fptr1 = fopen(argv[1], "w")) == NULL){
		printf("Cannot open %s.\n", argv[1]);
		reval = FAIL;
	} else if ((fptr2 = fopen(argv[2], "r")) == NULL){
		printf("Cannot open %s.\n", argv[2]);
		reval = FAIL;
	} else {
		CharReadWrite(fptr1, fptr2);
		fclose(fptr1);
		fclose(fptr2);
	}
	return reval;
}
