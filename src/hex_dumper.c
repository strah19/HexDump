/**
 * @file hex_dumper.c
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
 * This file contains the code for all the hex dumping, including
 * opening file, reading, and displaying.
 */

#include "..\include\hex_dumper.h"

void dump_file(FILE* fp, const char* file_path) {
    if (fp) {
        printf("file name: '%s'.\n", file_path);

        loop_file(fp);
    }
    else {
        printf("could not open file: '%s'.\n", file_path);
    }
}

void loop_file(FILE* fp) {
    bool same = true;
    bool star_printed = false;

    unsigned char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    unsigned char previous_buffer[BUFFER_SIZE];
    memset(previous_buffer, 0, BUFFER_SIZE);

    size_t bytes_read = get_buffer(fp, buffer);
    print_line(bytes_read, buffer, fp);

    while(!feof(fp)) {
        bytes_read = get_buffer(fp, buffer);
        if (bytes_read == 0)
            break;
 
        same = true;
        for (int i = 0; i < bytes_read; i++) {
            if (previous_buffer[i] != buffer[i]) {
                same = false;
            }
            previous_buffer[i] = buffer[i];
        }

        if (!same) {
            print_line(bytes_read, buffer, fp);
            star_printed = false;
        }
        else if (same && !star_printed) {
            printf("*\n");
            star_printed = true;
        }
    }
}

void print_line(size_t bytes_read, unsigned char* buffer, FILE* fp) {
    print_address(fp);
    
    for(int i = 0; i < bytes_read; i++){
        if(i == BUFFER_SIZE / 2)
            printf(" | ");
        printf(" %02X ", buffer[i]);
    }

    fill_empty(bytes_read, buffer);

    printf(" ");

    print_text(bytes_read, buffer);

    printf("\n");
}

void print_address(FILE* fp) {
    printf("0x%08X ", ftell(fp));
}

void print_text(int bytes_read, char* buffer) {
    for(int i = 0; i < bytes_read; i++){
        if(i == BUFFER_SIZE / 2) {
            printf(" ");
        }
        if(buffer[i] <= 0xFE && buffer[i] >= 0x20) {
            printf("%c", buffer[i]);
        }
        else {
            printf(".");
        }
        
        buffer[i] = ' ';
    }
}

int get_buffer(FILE* fp, char* buffer) {
    return (fread(buffer, sizeof(unsigned char), BUFFER_SIZE, fp));
}

void fill_empty(int bytes_read, char* buffer) {
    for(int i = 0; i < BUFFER_SIZE - bytes_read; i++){
        if(bytes_read + i == BUFFER_SIZE / 2) {
            printf(" | ");
        }

        printf(" ** ");
    }
}