#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "BMP_DataStructure.h"

void MonitorOutput(BMPHeaderData *Mon_FHptr, BMPHeaderData *Mon_IHptr, RGBQUAD *Mon_CMptr, int imgwidth, int imgheight, unsigned char *bPixel)
{
	MonOP_FH(Mon_FHptr);
	MonOP_IH(Mon_IHptr);
	MonOP_CM(Mon_CMptr);
	MonOP_DB(imgwidth, imgheight, bPixel);
	
}

void MonOP_FH(BMPHeaderData *Mon_FHptr)
{
	printf("\"BMP File Header:14 Bytes\"\n\n");
	printf("--Plain(Dec):\n");
	printf("bfType = %c, %c\n", Mon_FHptr->bfType[0], Mon_FHptr->bfType[1]);
	printf("bfSize = %d\n", (int)(((Mon_FHptr->bfSize[0]%16)*pow(16,0)) + ((Mon_FHptr->bfSize[0]/16)*pow(16,1)) + 
								  ((Mon_FHptr->bfSize[1]%16)*pow(16,2)) + ((Mon_FHptr->bfSize[1]/16)*pow(16,3)) + 
								  ((Mon_FHptr->bfSize[2]%16)*pow(16,4)) + ((Mon_FHptr->bfSize[2]/16)*pow(16,5)) + 
								  ((Mon_FHptr->bfSize[3]%16)*pow(16,6)) + ((Mon_FHptr->bfSize[3]/16)*pow(16,7))));
	printf("bfReserved1 = %d\n", (int)(((Mon_FHptr->bfReserved1[0]%16)*pow(16,0)) + ((Mon_FHptr->bfReserved1[0]/16)*pow(16,1)) + 
									   ((Mon_FHptr->bfReserved1[1]%16)*pow(16,2)) + ((Mon_FHptr->bfReserved1[1]/16)*pow(16,3))));
	printf("bfReserved2 = %d\n", (int)(((Mon_FHptr->bfReserved2[0]%16)*pow(16,0)) + ((Mon_FHptr->bfReserved2[0]/16)*pow(16,1)) + 
									   ((Mon_FHptr->bfReserved2[1]%16)*pow(16,2)) + ((Mon_FHptr->bfReserved2[1]/16)*pow(16,3))));
	printf("bfOffBits = %d\n\n", (int)(((Mon_FHptr->bfOffBits[0]%16)*pow(16,0)) + ((Mon_FHptr->bfOffBits[0]/16)*pow(16,1)) + 
									   ((Mon_FHptr->bfOffBits[1]%16)*pow(16,2)) + ((Mon_FHptr->bfOffBits[1]/16)*pow(16,3)) + 
									   ((Mon_FHptr->bfOffBits[2]%16)*pow(16,4)) + ((Mon_FHptr->bfOffBits[2]/16)*pow(16,5)) + 
									   ((Mon_FHptr->bfOffBits[3]%16)*pow(16,6)) + ((Mon_FHptr->bfOffBits[3]/16)*pow(16,7))));
}

void MonOP_IH(BMPHeaderData *Mon_IHptr)
{
	printf("\"BMP Info Header:40 Bytes\"\n\n");
	printf("--BMP Size:\nbiSize = %d\n", (int)(((Mon_IHptr->biSize[0]%16)*pow(16,0)) + ((Mon_IHptr->biSize[0]/16)*pow(16,1)) + 
								  				   ((Mon_IHptr->biSize[1]%16)*pow(16,2)) + ((Mon_IHptr->biSize[1]/16)*pow(16,3)) + 
								  				   ((Mon_IHptr->biSize[2]%16)*pow(16,4)) + ((Mon_IHptr->biSize[2]/16)*pow(16,5)) + 
								  				   ((Mon_IHptr->biSize[3]%16)*pow(16,6)) + ((Mon_IHptr->biSize[3]/16)*pow(16,7))));
	printf("--BMP Width:\nbiWidth = %d\n", (int)(((Mon_IHptr->biWidth[0]%16)*pow(16,0)) + ((Mon_IHptr->biWidth[0]/16)*pow(16,1)) + 
								  				   ((Mon_IHptr->biWidth[1]%16)*pow(16,2)) + ((Mon_IHptr->biWidth[1]/16)*pow(16,3)) + 
								  				   ((Mon_IHptr->biWidth[2]%16)*pow(16,4)) + ((Mon_IHptr->biWidth[2]/16)*pow(16,5)) + 
								  				   ((Mon_IHptr->biWidth[3]%16)*pow(16,6)) + ((Mon_IHptr->biWidth[3]/16)*pow(16,7))));
	printf("--BMP Height:\nbiHeight = %d\n", (int)(((Mon_IHptr->biHeight[0]%16)*pow(16,0)) + ((Mon_IHptr->biHeight[0]/16)*pow(16,1)) + 
								  					((Mon_IHptr->biHeight[1]%16)*pow(16,2)) + ((Mon_IHptr->biHeight[1]/16)*pow(16,3)) + 
								  					((Mon_IHptr->biHeight[2]%16)*pow(16,4)) + ((Mon_IHptr->biHeight[2]/16)*pow(16,5)) + 
								  					((Mon_IHptr->biHeight[3]%16)*pow(16,6)) + ((Mon_IHptr->biHeight[3]/16)*pow(16,7))));
	printf("--BMP Panes:\nbiPanes = %d\n", (int)(((Mon_IHptr->biPlanes[0]%16)*pow(16,0)) + ((Mon_IHptr->biPlanes[0]/16)*pow(16,1)) + 
								  					   ((Mon_IHptr->biPlanes[1]%16)*pow(16,2)) + (Mon_IHptr->biPlanes[1]/16)*pow(16,3)));
	printf("--BMP Bit Count:\nbiBitCount = %d\n", (int)(((Mon_IHptr->biBitCount[0]%16)*pow(16,0)) + ((Mon_IHptr->biBitCount[0]/16)*pow(16,1)) + 
								  					 			  ((Mon_IHptr->biBitCount[1]%16)*pow(16,2)) + ((Mon_IHptr->biBitCount[1]/16)*pow(16,3))));
	printf("--Compression Method:\nbiCompression = %d\n", (int)(((Mon_IHptr->biCompression[0]%16)*pow(16,0)) + ((Mon_IHptr->biCompression[0]/16)*pow(16,1)) + 
								  					  ((Mon_IHptr->biCompression[1]%16)*pow(16,2)) + ((Mon_IHptr->biCompression[1]/16)*pow(16,3)) + 
								  					  ((Mon_IHptr->biCompression[2]%16)*pow(16,4)) + ((Mon_IHptr->biCompression[2]/16)*pow(16,5)) + 
								  					  ((Mon_IHptr->biCompression[3]%16)*pow(16,6)) + ((Mon_IHptr->biCompression[3]/16)*pow(16,7))));
	printf("--BMP Size Image:\nbiSizeImage = %d\n", (int)(((Mon_IHptr->biSizeImage[0]%16)*pow(16,0)) + ((Mon_IHptr->biSizeImage[0]/16)*pow(16,1)) + 
								  					 		  ((Mon_IHptr->biSizeImage[1]%16)*pow(16,2)) + ((Mon_IHptr->biSizeImage[1]/16)*pow(16,3)) + 
								  					 		  ((Mon_IHptr->biSizeImage[2]%16)*pow(16,4)) + ((Mon_IHptr->biSizeImage[2]/16)*pow(16,5)) + 
								  					 		  ((Mon_IHptr->biSizeImage[3]%16)*pow(16,6)) + ((Mon_IHptr->biSizeImage[3]/16)*pow(16,7))));
	printf("--BMP X resolution:\nbiXPelsPerMeter = %d\n", (int)(((Mon_IHptr->biXPelsPerMeter[0]%16)*pow(16,0)) + ((Mon_IHptr->biXPelsPerMeter[0]/16)*pow(16,1)) + 
								  					 	  ((Mon_IHptr->biXPelsPerMeter[1]%16)*pow(16,2)) + ((Mon_IHptr->biXPelsPerMeter[1]/16)*pow(16,3)) + 
								  					 	  ((Mon_IHptr->biXPelsPerMeter[2]%16)*pow(16,4)) + ((Mon_IHptr->biXPelsPerMeter[2]/16)*pow(16,5)) + 
								  					 	  ((Mon_IHptr->biXPelsPerMeter[3]%16)*pow(16,6)) + ((Mon_IHptr->biXPelsPerMeter[3]/16)*pow(16,7))));
	printf("--BMP Y resolution:\nbiYPelsPerMeter = %d\n", (int)(((Mon_IHptr->biYPelsPerMeter[0]%16)*pow(16,0)) + ((Mon_IHptr->biYPelsPerMeter[0]/16)*pow(16,1)) + 
								  					 	  ((Mon_IHptr->biYPelsPerMeter[1]%16)*pow(16,2)) + ((Mon_IHptr->biYPelsPerMeter[1]/16)*pow(16,3)) + 
								  					 	  ((Mon_IHptr->biYPelsPerMeter[2]%16)*pow(16,4)) + ((Mon_IHptr->biYPelsPerMeter[2]/16)*pow(16,5)) + 
								  					 	  ((Mon_IHptr->biYPelsPerMeter[3]%16)*pow(16,6)) + (Mon_IHptr->biYPelsPerMeter[3]/16)*pow(16,7)));
	printf("--BMP Color Used:\nbiClrUsed = %d\n", (int)(((Mon_IHptr->biClrUsed[0]%16)*pow(16,0)) + ((Mon_IHptr->biClrUsed[0]/16)*pow(16,1)) + 
								  					 			((Mon_IHptr->biClrUsed[1]%16)*pow(16,2)) + ((Mon_IHptr->biClrUsed[1]/16)*pow(16,3)) + 
								  					 			((Mon_IHptr->biClrUsed[2]%16)*pow(16,4)) + ((Mon_IHptr->biClrUsed[2]/16)*pow(16,5)) + 
								  					 			((Mon_IHptr->biClrUsed[3]%16)*pow(16,6)) + ((Mon_IHptr->biClrUsed[3]/16)*pow(16,7))));
	printf("--BMP Important Color:\nbiClrImportant = %d\n", (int)(((Mon_IHptr->biClrImportant[0]%16)*pow(16,0)) + ((Mon_IHptr->biClrImportant[0]/16)*pow(16,1)) + 
								  					 			   ((Mon_IHptr->biClrImportant[1]%16)*pow(16,2)) +  ((Mon_IHptr->biClrImportant[1]/16)*pow(16,3)) + 
								  					 			   ((Mon_IHptr->biClrImportant[2]%16)*pow(16,4)) + ((Mon_IHptr->biClrImportant[2]/16)*pow(16,5)) + 
								  					 			   ((Mon_IHptr->biClrImportant[3]%16)*pow(16,6)) + ((Mon_IHptr->biClrImportant[3]/16)*pow(16,7))));
}

void MonOP_CM(RGBQUAD *Mon_CMptr)
{
	int i;
	printf("\"BMP Color Map:256 colors(0~255)\"\n\n");
	printf("\"The BMP Image is 8-bits, with color map\"\n");
	for(i=0;i<256;i++)
		printf("Num[%d] = (%d, %d, %d, %d)\n", i, Mon_CMptr[i].rgbBlue, Mon_CMptr[i].rgbGreen, Mon_CMptr[i].rgbRed, Mon_CMptr[i].reserved);
}

void MonOP_DB(int imgwidth, int imgheight, unsigned char *bpixel)
{
	int i, j;
	int ImgWidth = imgwidth;
	int ImgHeight = imgheight;
	
	printf("\"Bitmap Data Block:%d Pixels\"\n\n", ImgWidth*ImgHeight);
	
	for(j=0;j<ImgHeight;j++)
	{
		for(i=0;i<ImgWidth;i++)
		{
			printf("%d	", bpixel[i+j*ImgWidth]);
			
			if(i==ImgWidth-1)
			{
				printf("\n");
			}
		}
	}
}
