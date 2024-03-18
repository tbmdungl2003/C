#include <stdio.h>

int main() {
    FILE *input_file = fopen("input.txt", "r"); // Mở tệp đầu vào để đọc
    FILE *output_file = fopen("output.txt", "w"); // Mở tệp đầu ra để ghi

    int n;
    fscanf(input_file, "%d", &n);

    int heights[n];
    for (int i = 0; i < n; i++) {
        fscanf(input_file, "%d", &heights[i]);
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

    fprintf(output_file, "%d\n", triangle_height); // Xuất chiều cao tam giác cân vào tệp đầu ra
    fprintf(output_file, "Vị trí đầu: %d\n", start_position); // Xuất vị trí đầu vào tệp đầu ra
    fprintf(output_file, "Vị trí cuối: %d\n", end_position); // Xuất vị trí cuối vào tệp đầu ra

    fclose(input_file); // Đóng tệp đầu vào
    fclose(output_file); // Đóng tệp đầu ra

    return 0;
}


