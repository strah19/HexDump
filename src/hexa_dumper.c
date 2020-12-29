#include "..\include\hexa_dumper.h"

void DumpFile(FILE* fp, const char* file_path) {
    if (fp) {
        printf("File name: %s\n", file_path);
        LoopThroughFile(fp);

        fclose(fp);
    }
    else {
        printf("Could not open file: %s\n", file_path);
    }
}

void LoopThroughFile(FILE* fp) {
    unsigned char buffer[BUFFER_SIZE];
    while(!feof(fp)) {
        size_t bytes_read = GetNextBuffer(fp, buffer);

        PrintBufferAddress(fp);
        
        for(int i = 0; i < bytes_read; i++){
            if(i == BUFFER_SIZE / 2)
                printf(" | ");
            printf(" %02X ", buffer[i]);
        }

        FillEmptyHexValues(bytes_read, buffer);

        printf(" ");

        PrintContentsInText(bytes_read, buffer);

        printf("\n");
    }
}

int GetNextBuffer(FILE* fp, char* buffer) {
    return (fread(buffer, sizeof(unsigned char), BUFFER_SIZE, fp));
}

void PrintBufferAddress(FILE* fp) {
    printf("0x%08X ", ftell(fp));
}

void FillEmptyHexValues(int bytes_read, char* buffer) {
    for(int i = 0; i < BUFFER_SIZE - bytes_read; i++){
        if(bytes_read + i == BUFFER_SIZE / 2) {
            printf(" | ");
        }

        printf(" ** ");
    }
}

void PrintContentsInText(int bytes_read, char* buffer) {
    for(int i = 0; i < bytes_read; i++){
        if(i == BUFFER_SIZE / 2) {
            printf(" ");
        }
        if(buffer[i] <= 0xFE && buffer[i] >= 22) {
            printf("%c", buffer[i]);
        }
        else {
            printf(".");
        }
        
        buffer[i] = ' ';
    }
}