//  Created by:
//  Jacob Sachs
//     8/24/11
//  parsing.h
//  CSV_fix

#ifndef CSV_fix_parsing_h
#define CSV_fix_parsing_h

void analyzeBlock(FILE* file, char delim, int* first_time);

int delimitersPerLine(FILE* file, char delim, int* is_done);

int determineNorm(int array[]);

void printMalformed(int array[], int norm);

#endif
