#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_SIZE 16

void HexDump(FILE* fp, const char* file_path) {
 if(fp) {
    printf("File name: %s\n", file_path);
    unsigned char buffer[BUFFER_SIZE];
    while(!feof(fp)){
        size_t bytes_read = 0;
        bytes_read = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, fp);
        printf("0x%08X ", ftell(fp));
        for(int i = 0; i < bytes_read; i++){
            if(i == BUFFER_SIZE / 2){
                printf(" | ");
            }
            printf(" %02X ", buffer[i]);
        }
        for(int i = 0; i < BUFFER_SIZE - bytes_read; i++){
            if(bytes_read + i == BUFFER_SIZE / 2){
                printf(" | ");
            }
            printf(" ** ");
        }
        printf(" ");
        for(int i = 0; i < bytes_read; i++){
            if(i == BUFFER_SIZE / 2){
                printf(" ");
            }
            if(buffer[i] <= 0x7E && buffer[i] >= 22) {
                printf("%c", buffer[i]);
            }
            else{
                printf(".");
            }

            buffer[i] = ' ';
        }
        printf("\n");
        }
        fclose (fp);
    }
    else {
        printf("Could not open file: %s\n", file_path);
    }
}

int main(int argc, char **argv) {
    char* file_path;
    FILE* fp;
    bool open = true;

    while(open){
        printf("File: ");
        scanf("%s", file_path);
        fp = fopen(file_path, "rb");
        HexDump(fp, file_path);
    }

    return 0;
}