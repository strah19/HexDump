#include "../include/hex_dumper.h"

int main(int argc, char **argv) {
    char* file_path;
    FILE* fp;

    if (argv[1] == NULL) {
        fprintf(stderr, "error: must pass input file for dump.\n");
        exit(EXIT_FAILURE);
    }
    else {
        fp = fopen(argv[1], "rb");
        DumpFile(fp, argv[1]);
    }

    fclose(fp);
    return 0;
}