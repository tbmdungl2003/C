#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char reversed[argc-1][100];
    for (int i = 1; i < argc; i++) {
        strcpy(reversed[argc-i-1], argv[i]);
    }
    for (int i = 0; i < argc-1; i++) {
        printf("%s ", reversed[i]);
    }
    printf("\n");
    return 0;
}
