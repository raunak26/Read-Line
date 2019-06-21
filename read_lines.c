#include <stdlib.h>
#include <stdio.h>
#include "read_lines.h"

// taken help from CSIF

// TODO: Do void read_lines


void read_lines(FILE* inFile, char*** line, int* numlines) {
  *line = NULL;
  (*line) = (char **) calloc(1, sizeof(**line)); // allocates the requested memory and returns pointer to it
  int numberOfLines = 0;
  *numlines = 0;

  for (int i = 0; i < 111111; i++) {
    (*line) = (char **) realloc((*line), (i + 25) * sizeof(*line));
    (*line)[i] = read_line(inFile);
    if ((*line)[i][0] == '\0') {
      break;
    }
    numberOfLines++; // iterates through the input file
  }
  *numlines = numberOfLines;
}

char* read_line(FILE* inFile) {
  char character;
  char *eachLine;

  character = fgetc(inFile); // retrieving character from stream
  eachLine = (char*) calloc(10, sizeof(char)); // allocates the requested memory and returns pointer to it
                                                // dynamically allocates memory
  int linex = 0;
  int liney = 1;
  int linez = 2;

  while (character != EOF) {
    eachLine = (char*) realloc(eachLine, (linex + linez) * sizeof(char));

    eachLine[linex] = character;

    if(character == '\n') {
      eachLine = realloc(eachLine, (linex + linez) * sizeof(char));
      eachLine[linex + liney] = '\0';
      return eachLine;
    }
    linex++;
    character = fgetc(inFile);  // retrieving character from stream
  }

  if(character == EOF) {
    eachLine[0] = '\0';
    return eachLine;
  }
  return eachLine;
}

