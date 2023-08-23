#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "BMP_DataStructure.h"

void WriteBMPPlain(char *OPPlaintxtfilename, char *IPbmpfilename, BMPHeaderData *Mon_FHptr, BMPHeaderData *Mon_IHptr, RGBQUAD *Mon_CMptr, int imgwidth, int imgheight, unsigned char *bPixel)
{
	WritePlain_FH(OPPlaintxtfilename, IPbmpfilename, Mon_FHptr);
	WritePlain_IH(OPPlaintxtfilename, Mon_IHptr);
	WritePlain_CM(OPPlaintxtfilename, Mon_CMptr);
	WritePlain_DB(OPPlaintxtfilename, imgwidth, imgheight, bPixel);
}

void WritePlain_FH(char *OPPlaintxtfilename, char *IPbmpfilename, BMPHeaderData *Mon_FHptr)
{
	FILE *fin6;
	fin6 = fopen(OPPlaintxtfilename, "w");
	while(fin6 == NULL)
	{
		printf("%s is no exist.\n", OPPlaintxtfilename);
		printf("Input Output Plain txt file name:\n");
		scanf("%s\n", &OPPlaintxtfilename);
		fin6 = fopen(OPPlaintxtfilename, "w");
	}
	
	fprintf(fin6, "--Image Name:%s\n", IPbmpfilename);
	fprintf(fin6, "--Image bitCount:%d\n", (int)(((Mon_FHptr->biBitCount[0]%16)*pow(16,0)) + ((Mon_FHptr->biBitCount[0]/16)*pow(16,1)) + 
								  			((Mon_FHptr->biBitCount[1]%16)*pow(16,2)) + ((Mon_FHptr->biBitCount[1]/16)*pow(16,3))));
	fprintf(fin6, "--Image Resolution:%d*%d\n\n", Mon_FHptr->biWidth_integer, Mon_FHptr->biHeight_integer);
	fprintf(fin6, "\"BMP File Header:14 Bytes\"\n\n");
	fprintf(fin6, "--Cipher(Hex):\nbfType = %x, %x\n", (int)Mon_FHptr->bfType[0], (int)Mon_FHptr->bfType[1]);
	fprintf(fin6, "bfSize = %02x %02x %02x %02x\n", Mon_FHptr->bfSize[0], Mon_FHptr->bfSize[1], Mon_FHptr->bfSize[2], Mon_FHptr->bfSize[3]);
	fprintf(fin6, "bfReserved1 = %02x %02x\n", Mon_FHptr->bfReserved1[0], Mon_FHptr->bfReserved1[1]);
	fprintf(fin6, "bfReserved2 = %02x %02x\n", Mon_FHptr->bfReserved2[0], Mon_FHptr->bfReserved2[1]);
	fprintf(fin6, "bfOffBits = %02x %02x %02x %02x\n\n", Mon_FHptr->bfOffBits[0], Mon_FHptr->bfOffBits[1], Mon_FHptr->bfOffBits[2], Mon_FHptr->bfOffBits[3]);
	fprintf(fin6, "--Plain(Dec):\n");
	fprintf(fin6, "bfType = %c, %c\n", Mon_FHptr->bfType[0], Mon_FHptr->bfType[1]);
	fprintf(fin6, "bfSize = %d\n", (int)(((Mon_FHptr->bfSize[0]%16)*pow(16,0)) + ((Mon_FHptr->bfSize[0]/16)*pow(16,1)) + 
								  		 ((Mon_FHptr->bfSize[1]%16)*pow(16,2)) + ((Mon_FHptr->bfSize[1]/16)*pow(16,3)) + 
								  		 ((Mon_FHptr->bfSize[2]%16)*pow(16,4)) + ((Mon_FHptr->bfSize[2]/16)*pow(16,5)) + 
								   		 ((Mon_FHptr->bfSize[3]%16)*pow(16,6)) + ((Mon_FHptr->bfSize[3]/16)*pow(16,7))));
	fprintf(fin6, "bfReserved1 = %d\n", (int)(((Mon_FHptr->bfReserved1[0]%16)*pow(16,0)) + ((Mon_FHptr->bfReserved1[0]/16)*pow(16,1)) + 
									   		  ((Mon_FHptr->bfReserved1[1]%16)*pow(16,2)) + ((Mon_FHptr->bfReserved1[1]/16)*pow(16,3))));
	fprintf(fin6, "bfReserved2 = %d\n", (int)(((Mon_FHptr->bfReserved2[0]%16)*pow(16,0)) + ((Mon_FHptr->bfReserved2[0]/16)*pow(16,1)) + 
									   		  ((Mon_FHptr->bfReserved2[1]%16)*pow(16,2)) + ((Mon_FHptr->bfReserved2[1]/16)*pow(16,3))));
	fprintf(fin6, "bfOffBits = %d\n\n", (int)(((Mon_FHptr->bfOffBits[0]%16)*pow(16,0)) + ((Mon_FHptr->bfOffBits[0]/16)*pow(16,1)) + 
									   		  ((Mon_FHptr->bfOffBits[1]%16)*pow(16,2)) + ((Mon_FHptr->bfOffBits[1]/16)*pow(16,3)) + 
									   		  ((Mon_FHptr->bfOffBits[2]%16)*pow(16,4)) + ((Mon_FHptr->bfOffBits[2]/16)*pow(16,5)) + 
									   		  ((Mon_FHptr->bfOffBits[3]%16)*pow(16,6)) + ((Mon_FHptr->bfOffBits[3]/16)*pow(16,7))));
	fclose(fin6);
	printf("WritePlain_FH  OK\n");
}

void WritePlain_IH(char *OPPlaintxtfilename, BMPHeaderData *Mon_IHptr)
{
	FILE *fin7;
	fin7 = fopen(OPPlaintxtfilename, "a");
	while(fin7 == NULL)
	{
		printf("%s is no exist.\n", OPPlaintxtfilename);
		printf("Input Output Plain txt file name:\n");
		scanf("%s\n", &OPPlaintxtfilename);
		fin7 = fopen(OPPlaintxtfilename, "a");
	}

	fprintf(fin7, "\"BMP Info Header:40 Bytes\"\n\n");
	fprintf(fin7, "--BMP Size:\nbiSize = %d\n", (int)(((Mon_IHptr->biSize[0]%16)*pow(16,0)) + ((Mon_IHptr->biSize[0]/16)*pow(16,1)) + 
								  				   		  ((Mon_IHptr->biSize[1]%16)*pow(16,2)) + ((Mon_IHptr->biSize[1]/16)*pow(16,3)) + 
								  				   		  ((Mon_IHptr->biSize[2]%16)*pow(16,4)) + ((Mon_IHptr->biSize[2]/16)*pow(16,5)) + 
								  				   		  ((Mon_IHptr->biSize[3]%16)*pow(16,6)) + ((Mon_IHptr->biSize[3]/16)*pow(16,7))));
	fprintf(fin7, "--BMP Width:\nbiWidth = %d\n", (int)(((Mon_IHptr->biWidth[0]%16)*pow(16,0)) + ((Mon_IHptr->biWidth[0]/16)*pow(16,1)) + 
								  				   	  	  ((Mon_IHptr->biWidth[1]%16)*pow(16,2)) + ((Mon_IHptr->biWidth[1]/16)*pow(16,3)) + 
								  				   		  ((Mon_IHptr->biWidth[2]%16)*pow(16,4)) + ((Mon_IHptr->biWidth[2]/16)*pow(16,5)) + 
								  				   		  ((Mon_IHptr->biWidth[3]%16)*pow(16,6)) + ((Mon_IHptr->biWidth[3]/16)*pow(16,7))));
	fprintf(fin7, "--BMP Height:\nbiHeight = %d\n", (int)(((Mon_IHptr->biHeight[0]%16)*pow(16,0)) + ((Mon_IHptr->biHeight[0]/16)*pow(16,1)) + 
								  					 ((Mon_IHptr->biHeight[1]%16)*pow(16,2)) + ((Mon_IHptr->biHeight[1]/16)*pow(16,3)) + 
								  					 ((Mon_IHptr->biHeight[2]%16)*pow(16,4)) + ((Mon_IHptr->biHeight[2]/16)*pow(16,5)) + 
								  					 ((Mon_IHptr->biHeight[3]%16)*pow(16,6)) + ((Mon_IHptr->biHeight[3]/16)*pow(16,7))));
	fprintf(fin7, "--BMP Panes:\nbiPanes = %d\n", (int)(((Mon_IHptr->biPlanes[0]%16)*pow(16,0)) + ((Mon_IHptr->biPlanes[0]/16)*pow(16,1)) + 
								  					   		  ((Mon_IHptr->biPlanes[1]%16)*pow(16,2)) + (Mon_IHptr->biPlanes[1]/16)*pow(16,3)));
	fprintf(fin7, "--BMP Bit Count:\nbiBitCount = %d\n", (int)(((Mon_IHptr->biBitCount[0]%16)*pow(16,0)) + ((Mon_IHptr->biBitCount[0]/16)*pow(16,1)) + 
								  					 			  		 ((Mon_IHptr->biBitCount[1]%16)*pow(16,2)) + ((Mon_IHptr->biBitCount[1]/16)*pow(16,3))));
	fprintf(fin7, "--Compression Method:\nbiCompression = %d\n", (int)(((Mon_IHptr->biCompression[0]%16)*pow(16,0)) + ((Mon_IHptr->biCompression[0]/16)*pow(16,1)) + 
								  					  		 ((Mon_IHptr->biCompression[1]%16)*pow(16,2)) + ((Mon_IHptr->biCompression[1]/16)*pow(16,3)) + 
								  					  		 ((Mon_IHptr->biCompression[2]%16)*pow(16,4)) + ((Mon_IHptr->biCompression[2]/16)*pow(16,5)) + 
								  					  		 ((Mon_IHptr->biCompression[3]%16)*pow(16,6)) + ((Mon_IHptr->biCompression[3]/16)*pow(16,7))));
	fprintf(fin7, "--BMP Size Image:\nbiSizeImage = %d\n", (int)(((Mon_IHptr->biSizeImage[0]%16)*pow(16,0)) + ((Mon_IHptr->biSizeImage[0]/16)*pow(16,1)) + 
								  					 		  		 ((Mon_IHptr->biSizeImage[1]%16)*pow(16,2)) + ((Mon_IHptr->biSizeImage[1]/16)*pow(16,3)) + 
								  					 		  		 ((Mon_IHptr->biSizeImage[2]%16)*pow(16,4)) + ((Mon_IHptr->biSizeImage[2]/16)*pow(16,5)) + 
								  					 		  		 ((Mon_IHptr->biSizeImage[3]%16)*pow(16,6)) + ((Mon_IHptr->biSizeImage[3]/16)*pow(16,7))));
	fprintf(fin7, "--BMP X resolution:\nbiXPelsPerMeter = %d\n", (int)(((Mon_IHptr->biXPelsPerMeter[0]%16)*pow(16,0)) + ((Mon_IHptr->biXPelsPerMeter[0]/16)*pow(16,1)) + 
								  					 	  		 ((Mon_IHptr->biXPelsPerMeter[1]%16)*pow(16,2)) + ((Mon_IHptr->biXPelsPerMeter[1]/16)*pow(16,3)) + 
								  					 	  		 ((Mon_IHptr->biXPelsPerMeter[2]%16)*pow(16,4)) + ((Mon_IHptr->biXPelsPerMeter[2]/16)*pow(16,5)) + 
								  					 	  		 ((Mon_IHptr->biXPelsPerMeter[3]%16)*pow(16,6)) + ((Mon_IHptr->biXPelsPerMeter[3]/16)*pow(16,7))));
	fprintf(fin7, "--BMP Y resolution:\nbiYPelsPerMeter = %d\n", (int)(((Mon_IHptr->biYPelsPerMeter[0]%16)*pow(16,0)) + ((Mon_IHptr->biYPelsPerMeter[0]/16)*pow(16,1)) + 
								  					 	  		 ((Mon_IHptr->biYPelsPerMeter[1]%16)*pow(16,2)) + ((Mon_IHptr->biYPelsPerMeter[1]/16)*pow(16,3)) + 
								  					 	  		 ((Mon_IHptr->biYPelsPerMeter[2]%16)*pow(16,4)) + ((Mon_IHptr->biYPelsPerMeter[2]/16)*pow(16,5)) + 
								  					 	  		 ((Mon_IHptr->biYPelsPerMeter[3]%16)*pow(16,6)) + (Mon_IHptr->biYPelsPerMeter[3]/16)*pow(16,7)));
	fprintf(fin7, "--BMP Color Used:\nbiClrUsed = %d\n", (int)(((Mon_IHptr->biClrUsed[0]%16)*pow(16,0)) + ((Mon_IHptr->biClrUsed[0]/16)*pow(16,1)) + 
								  					 				   ((Mon_IHptr->biClrUsed[1]%16)*pow(16,2)) + ((Mon_IHptr->biClrUsed[1]/16)*pow(16,3)) + 
								  					 				   ((Mon_IHptr->biClrUsed[2]%16)*pow(16,4)) + ((Mon_IHptr->biClrUsed[2]/16)*pow(16,5)) + 
								  					 				   ((Mon_IHptr->biClrUsed[3]%16)*pow(16,6)) + ((Mon_IHptr->biClrUsed[3]/16)*pow(16,7))));
	fprintf(fin7, "--BMP Important Color:\nbiClrImportant = %d\n\n", (int)(((Mon_IHptr->biClrImportant[0]%16)*pow(16,0)) + ((Mon_IHptr->biClrImportant[0]/16)*pow(16,1)) + 
								  					 			   		  ((Mon_IHptr->biClrImportant[1]%16)*pow(16,2)) +  ((Mon_IHptr->biClrImportant[1]/16)*pow(16,3)) + 
								  					 			   		  ((Mon_IHptr->biClrImportant[2]%16)*pow(16,4)) + ((Mon_IHptr->biClrImportant[2]/16)*pow(16,5)) + 
								  					 			   		  ((Mon_IHptr->biClrImportant[3]%16)*pow(16,6)) + ((Mon_IHptr->biClrImportant[3]/16)*pow(16,7))));
	fclose(fin7);
	printf("WritePlain_IH OK\n");
}

void WritePlain_CM(char *OPPlaintxtfilename, RGBQUAD *Mon_CMptr)
{
	FILE *fin8;
	fin8 = fopen(OPPlaintxtfilename, "a");
	while(fin8 == NULL)
	{
		printf("%s is no exist.\n", OPPlaintxtfilename);
		printf("Input Output Plain txt file name:\n");
		scanf("%s\n", &OPPlaintxtfilename);
		fin8 = fopen(OPPlaintxtfilename, "a");
	}
	
	int i;
	fprintf(fin8, "\"BMP Color Map:256 colors(0~255)\"\n\n");
	fprintf(fin8, "The BMP Image is 8-bits, with color map\n");
	
	for(i=0;i<256;i++)
		fprintf(fin8, "Num[%d] = (%d, %d, %d, %d)\n", i, Mon_CMptr[i].rgbBlue, Mon_CMptr[i].rgbGreen, Mon_CMptr[i].rgbRed, Mon_CMptr[i].reserved);
	
	fprintf(fin8, "\n");
	fclose(fin8);
	printf("WritePlain_CM  OK\n");
}

void WritePlain_DB(char *OPPlaintxtfilename, int imgwidth, int imgheight, unsigned char *bpixel)
{
	FILE *fin9;
	fin9 = fopen(OPPlaintxtfilename, "a");
	while(fin9 == NULL)
	{
		printf("%s is no exist.\n", OPPlaintxtfilename);
		printf("Input Output Plain txt file name:\n");
		scanf("%s\n", &OPPlaintxtfilename);
		fin9 = fopen(OPPlaintxtfilename, "a");
	}
	
	int i, j;
	int ImgWidth = imgwidth;
	int ImgHeight = imgheight;
	
	fprintf(fin9, "\"Bitmap Data Block:%d Pixels\"\n\n", ImgWidth*ImgHeight);
	
	for(j=0;j<ImgHeight;j++)
	{
		for(i=0;i<ImgWidth;i++)
		{
			fprintf(fin9, "%d	", bpixel[i+j*ImgWidth]);
			
			if(i==ImgWidth-1)
				fprintf(fin9, "\n");
		}
	}
	fclose(fin9);
	printf("WritePlain_DB  OK\n");
}
