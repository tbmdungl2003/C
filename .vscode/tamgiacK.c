#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int heights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    int min_height = heights[n - 1];
    int triangle_height = 1;
    int start_position = n;
    int end_position = n;

    for (int i = n - 2; i >= 0; i--) {
        if (heights[i] >= min_height) {
            triangle_height++;
            start_position = i + 1; // Vị trí đầu của tam giác cân
        } else {
            min_height = heights[i];
        }
    }

    end_position = n - triangle_height + 1; // Vị trí cuối của tam giác cân

    printf("%d\n", triangle_height);
    printf("Vị trí đầu: %d\n", start_position);
    printf("Vị trí cuối: %d\n", end_position);

    return 0;
}

