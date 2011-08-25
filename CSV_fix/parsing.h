//
//  parsing.h
//  CSV_fix
//
//  Created by Jacob Sachs on 8/25/11.
//  Copyright 2011 University of Chicago. All rights reserved.
//

#ifndef CSV_fix_parsing_h
#define CSV_fix_parsing_h

void analyzeBlock(FILE* file, char delim);

int delimitersPerLine(FILE* file, char delim, int* is_done);

int determineNorm(int array[]);

void printMalformed(int array[], int norm);

#endif
