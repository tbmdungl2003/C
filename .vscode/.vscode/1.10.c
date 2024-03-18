#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        printf("Sai cu phap. Vui long nhap lai.\n");
        return 1;
    }
	double exponent = atof(argv[1]);
    if (argc == 3) {
        double tolerance = atof(argv[2]);
        double result = exp(exponent);
        printf("Ket qua luy thua cua e^%.2f voi sai so cho phép %.6f là %.6f\n", exponent, tolerance, result);
    } else {
        double result = exp(exponent);
        printf("Ket qua luy thua cua e^%.2f là %.6f\n", exponent, result);
    }

    return 0;
}
