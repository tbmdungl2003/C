#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc cho từ điển
struct DictionaryEntry {
    char key[100];
    char value[100];
};

// Hàm chuyển đổi dữ liệu từ tệp văn bản sang nhị phân
void textToBinary(const char* textFilePath, const char* binaryFilePath) {
    FILE* textFile = fopen(textFilePath, "r");
    if (textFile == NULL) {
        perror("Không thể mở tệp văn bản");
        exit(1);
    }

    FILE* binaryFile = fopen(binaryFilePath, "wb");
    if (binaryFile == NULL) {
        perror("Không thể mở tệp nhị phân");
        exit(1);
    }

    struct DictionaryEntry entry;
    while (fscanf(textFile, "%99[^:] : %99[^\n]\n", entry.key, entry.value) == 2) {
        fwrite(&entry, sizeof(struct DictionaryEntry), 1, binaryFile);
    }

    fclose(textFile);
    fclose(binaryFile);
}

// Hàm đọc và hiển thị các từ từ tệp nhị phân
void readAndDisplayBinary(const char* binaryFilePath, int start, int end) {
    FILE* binaryFile = fopen(binaryFilePath, "rb");
    if (binaryFile == NULL) {
        perror("Không thể mở tệp nhị phân");
        exit(1);
    }

    struct DictionaryEntry entry;
    int entryIndex = 0;
    while (fread(&entry, sizeof(struct DictionaryEntry), 1, binaryFile) == 1) {
        if (entryIndex >= start && entryIndex <= end) {
            printf("%s : %s\n", entry.key, entry.value);
        }
        entryIndex++;
    }

    fclose(binaryFile);
}

int main() {
    const char* textFilePath = "vnedict.txt";
    const char* binaryFilePath = "vnedict.bin";

    // Chuyển đổi dữ liệu từ tệp văn bản sang nhị phân
    textToBinary(textFilePath, binaryFilePath);

    int start, end;
    printf("Nhập vị trí bắt đầu: ");
    scanf("%d", &start);
    printf("Nhập vị trí kết thúc: ");
    scanf("%d", &end);

    // Đọc và hiển thị các từ từ tệp nhị phân
    readAndDisplayBinary(binaryFilePath, start, end);

    return 0;
}
