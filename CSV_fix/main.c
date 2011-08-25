//
//  main.c
//  CSV_fix
//
//  Created by Jacob Sachs on 8/24/11.
//  Copyright 2011 University of Chicago. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "parsing.h"
#include <limits.h>
#define BUFFER   8000
#define MAXLINES 200000

int main(int argc, char *argv[])
{
    FILE* fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL) exit(0);
    
    char dm;
    printf("Enter delimiter: ");
    scanf("%c", &dm);
    
    analyzeBlock(fp, dm);
    
    // need to configure to analyze certain size chunks at a time.
    
    
    fclose(fp);
    
    return 0;
}

