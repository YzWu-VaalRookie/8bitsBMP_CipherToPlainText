#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BMP_DataStructure.h"

int main(int argc, char *argv[])
{
	char IPCoetxtfilename[350]; 
	char IPbmpfilename[350];
	char OPbmpfilename[350];
	char OPPlaintxtfilename[350];
	int i, j;
	
	BMP_DataStructure *BMP_8bit = (BMP_DataStructure*)malloc(sizeof(BMP_DataStructure));
	BMP_8bit->BMPHeaderDataPtr = (BMPHeaderData*)malloc(sizeof(BMPHeaderData));
	BMP_8bit->ColorMap = (RGBQUAD*)malloc(sizeof(RGBQUAD)*256);
	
	ReadIOPCoefficient("IPCoefficient.txt", IPbmpfilename, OPPlaintxtfilename, BMP_8bit->BMPHeaderDataPtr);
	printf("IPCoefficient txt Read  ...OK\n");
	
	int Imgwidth = BMP_8bit->BMPHeaderDataPtr->biWidth_integer;
	int Imgheight = BMP_8bit->BMPHeaderDataPtr->biHeight_integer;
	BMP_8bit->BMPHeaderDataPtr->bPixel = (unsigned char*)malloc(sizeof(unsigned char)*Imgwidth*Imgheight);
	
	ReadBMPCipher(IPbmpfilename, BMP_8bit->BMPHeaderDataPtr, BMP_8bit->BMPHeaderDataPtr, BMP_8bit->ColorMap, Imgwidth, Imgheight, BMP_8bit->BMPHeaderDataPtr->bPixel);
	printf("BMP Cipher Read  ...OK\n");
	
	//MonitorOutput(BMP_8bit->BMPHeaderDataPtr, BMP_8bit->BMPHeaderDataPtr, BMP_8bit->ColorMap, Imgwidth, Imgheight, BMP_8bit->BMPHeaderDataPtr->bPixel);
	//printf("Monitor Output BMP Plain Code  ...OK\n");
	
	WriteBMPPlain(OPPlaintxtfilename, IPbmpfilename, BMP_8bit->BMPHeaderDataPtr, BMP_8bit->BMPHeaderDataPtr, BMP_8bit->ColorMap, Imgwidth, Imgheight, BMP_8bit->BMPHeaderDataPtr->bPixel);
	printf("Write BMP Plain Text  ...OK\n");
	
	free(BMP_8bit->ColorMap);
	free(BMP_8bit->BMPHeaderDataPtr);
	free(BMP_8bit);
	
	system("pause");
	return 0;
}
