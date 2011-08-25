//
//  parsing.c
//  CSV_fix
//
//  Created by Jacob Sachs on 8/25/11.
//  Copyright 2011 University of Chicago. All rights reserved.
//

#include <stdio.h>
#include "parsing.h"
#define BUFFER   8000
#define MAXLINES 200000

int delimitersPerLine(FILE* file, char delim, int* is_done)
{
    char line[BUFFER] = {'\0'};          // Initialize a line buffer,
    fgets(line, BUFFER, file);           // and get the first line from a file.
    
    int count = 0;
    int i = 0;
    int c;
    
    if (line[0] == NULL) *is_done = 1;   // finish reading the file on null line
    
    while ((c = line[i]) != NULL) {
        if (c == delim)                  // Increment the count with every
            count++;                     // delimiter found.
        i++;
    }
    return count;
}


int determineNorm(int array[])
{
    int max=0, i, j, entries;
    int array2[MAXLINES];
    
    for (i=0; (j = array[i]) != NULL; i++) {
        array2[j]++;
    }
    
    entries = i;
    
    for (i=0; i < entries; i++) {
        if (array2[i] > max)
            max = i;
    }
    
    return max;
}

void printMalformed(int array[], int norm)
{
    static int l = 0;
    
    for (int i = 0; array[i] != NULL; i++, l++) {
        if (array[i] != norm)
            printf("Line %i is malformed.\n", l + 1);
    }
}


void analyzeBlock(FILE* fp, char dm)
{
    int delim_counts[MAXLINES] = {'\0'};
    int done_flag = 0;
    
    
    // Read the number of delimiters on each line into an array.
    int k = 0;
    
    do {
        delim_counts[k] = delimitersPerLine(fp, dm, &done_flag);
        k++;
    } while (!done_flag);
    
    
    // Determine the most commonly occuring number of delimiters on each line.
    int the_norm = determineNorm(delim_counts);
    printf("The normal number of delimiters is %i.\n", the_norm);
    
    
    // Print the line numbers containing irregular data.
    printMalformed(delim_counts, the_norm);
    
    return;
}






