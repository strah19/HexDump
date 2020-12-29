#include "../include/hexa_dumper.h"

int main(int argc, char **argv) {
    char* file_path;
    FILE* fp;
    bool open = true;

    while(open) {
        printf("File: ");
        scanf("%s", file_path);
        fp = fopen(file_path, "rb");
        DumpFile(fp, file_path);
    }

    return 0;
}