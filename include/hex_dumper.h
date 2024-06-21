#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_SIZE 16
#define LOWEST_ASCII_POINT 22
#define HIGHEST_ASCII_POINT 0x7E

extern void dump_file(FILE* fp, const char* file_path);

static void loop_file(FILE* fp);

static void print_line(size_t bytes_read, unsigned char* buffer, FILE* fp);

static void print_address(FILE* fp);

static void print_text(int bytes_read, char* buffer);

static int get_buffer(FILE* fp, char* buffer);

static void fill_empty(int bytes_read, char* buffer);