#include <stdio.h>
#include <math.h>

// Định nghĩa cấu trúc hình tròn
typedef struct Circle {
    double x; // Tọa độ x của tâm
    double y; // Tọa độ y của tâm
    double radius; // Bán kính
} Circle;

// Hàm kiểm tra xem hai hình tròn có giao nhau hay không
int circlesIntersect(const Circle *c1, const Circle *c2) {
    double distance = sqrt(pow(c1->x - c2->x, 2) + pow(c1->y - c2->y, 2));
    return distance < (c1->radius + c2->radius);
}

int main() {
    Circle circle1, circle2;

    // Nhập thông tin cho hình tròn 1
    printf("Nhập thông tin cho hình tròn 1:\n");
    printf("Tọa độ x của tâm: ");
    scanf("%lf", &circle1.x);
    printf("Tọa độ y của tâm: ");
    scanf("%lf", &circle1.y);
    printf("Bán kính: ");
    scanf("%lf", &circle1.radius);

    // Nhập thông tin cho hình tròn 2
    printf("Nhập thông tin cho hình tròn 2:\n");
    printf("Tọa độ x của tâm: ");
    scanf("%lf", &circle2.x);
    printf("Tọa độ y của tâm: ");
    scanf("%lf", &circle2.y);
    printf("Bán kính: ");
    scanf("%lf", &circle2.radius);

    // Kiểm tra xem hai hình tròn có giao nhau hay không
    if (circlesIntersect(&circle1, &circle2)) {
        printf("Hai hình tròn giao nhau.\n");
    } else {
        printf("Hai hình tròn không giao nhau.\n");
    }

    return 0;
}