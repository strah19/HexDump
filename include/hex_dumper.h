#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

#define BUFFER_SIZE 16
#define LOWEST_ASCII_POINT 22
#define HIGHEST_ASCII_POINT 0x7E

#define RESET_COLOR_ATTRIB 7
#define ADDRESS_COLOR_ATTRIB 2
#define ASCII_COLOR_ATTRIB 4

static HANDLE h_console;

extern void DumpFile(FILE* fp, const char* file_path);

static void LoopThroughFile(FILE* fp);

static int GetNextBuffer(FILE* fp, char* buffer);

static void PrintBufferAddress(FILE* fp);

static void FillEmptyHexValues(int bytes_read, char* buffer);

static void PrintContentsInText(int bytes_read, char* buffer);