/**
 * @file main.c
 * @author strah19
 * @date June 20 2024
 * @version 1.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the MIT License as
 * published by the Free Software Foundation.
 *
 * @section DESCRIPTION
 *
 * This file contains the entry point for the hexdump application.
 */

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
        dump_file(fp, argv[1]);
    }

    fclose(fp);
    return 0;
}