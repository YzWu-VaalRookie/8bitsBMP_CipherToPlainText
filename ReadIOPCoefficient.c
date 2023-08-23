#include <stdio.h>
#include <stdlib.h>
#include "BMP_DataStructure.h"

void ReadIOPCoefficient(char *IPCoetxtfilename, char IPbmpfilename[], char OPPlaintxtfilename[], BMPHeaderData *BMP8b_HDptr)
{
	FILE *fin;
	fin = fopen(IPCoetxtfilename, "r+");
	while(fin == NULL)
	{
		printf("%s is no exist.\n", IPCoetxtfilename);
		printf("Input IOPtxt file name:\n");
		scanf("%s\n", &IPCoetxtfilename);
		fin = fopen(IPCoetxtfilename, "r+");
	}
	
	char buffer[350];
	
	fgets(buffer, 350, fin);
	fscanf(fin, "%s\n\n", IPbmpfilename);
	
	fgets(buffer, 350, fin);
	fscanf(fin, "%s\n\n", OPPlaintxtfilename);
	
	fgets(buffer, 350, fin);
	fscanf(fin, "%d\n\n", &BMP8b_HDptr->biWidth_integer);
	
	fgets(buffer, 350, fin);
	fscanf(fin, "%d\n\n", &BMP8b_HDptr->biHeight_integer);
	
	fclose(fin);
}
