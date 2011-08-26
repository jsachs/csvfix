//  Created by:
//  Jacob Sachs
//     8/24/11
//  main.c
//  CSV_fix

#include <stdio.h>
#include <stdlib.h>
#include "parsing.h"
#include <limits.h>
#define BUFFER   8000
#define MAXLINES 200000

int main(int argc, char *argv[])
{
    
    // Procedure for opening file into readable chunks.
    FILE* fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL) exit(0);
    
    
    
    // Procedure for choosing delimiter to use.
    char dm;
    printf("Enter delimiter: ");
    scanf("%c", &dm);
    
    
    
    // Procedure for analyzing the file chunks.
    // Will determine correct number of delimiters from the first chunk alone.
    
    int ft = 1;
    
    while (!feof(fp))
        analyzeBlock(fp, dm, &ft);
    
 
    // Close files at conclusion of runtime.
    fclose(fp);
    
    return 0;
}

