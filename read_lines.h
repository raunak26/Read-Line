#ifndef READ_LINES
#define READ_LINES
#include <stdio.h>

char* read_line(FILE* inFile);
void read_lines(FILE* inFile, char*** line, int* numlines);

#endif
