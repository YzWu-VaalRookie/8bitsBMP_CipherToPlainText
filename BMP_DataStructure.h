typedef struct
{
	//BMP_FILE HEADER
	unsigned char	bfType[2];
	unsigned char	bfSize[4];
	unsigned char	bfReserved1[2];
	unsigned char	bfReserved2[2];
	unsigned char	bfOffBits[4];
	//BMP_INFO HEADER
	unsigned char	biSize[4];
	unsigned char	biWidth[4];
	unsigned char	biHeight[4];
	unsigned char	biPlanes[2];
	unsigned char	biBitCount[2];
	unsigned char	biCompression[4];
	unsigned char	biSizeImage[4];
	unsigned char	biXPelsPerMeter[4];
	unsigned char	biYPelsPerMeter[4];
	unsigned char	biClrUsed[4];
	unsigned char	biClrImportant[4];
	//BMP_Bitmap Data
	unsigned char	*bPixel;
	//Read Coe of Width/Height 
	int				biWidth_integer;
	int				biHeight_integer;
}BMPHeaderData;

typedef struct
{
	int rgbBlue;
	int rgbGreen;
	int rgbRed;
	int reserved;
}RGBQUAD; //BMP_ColorMap

typedef struct
{
	BMPHeaderData	*BMPHeaderDataPtr;
	RGBQUAD			*ColorMap;
	char			BMPFileName[50];
}BMP_DataStructure;

void ReadIOPCoefficient(char *IPCoetxtfilename, char IPbmpfilename[], char OPPlaintxtfilename[], BMPHeaderData *BMP8b_HDptr);
void ReadBMPCipher(char *IPbmpfilename, BMPHeaderData *FH_ptr, BMPHeaderData *IH_ptr, RGBQUAD *CM_ptr, int Imgwidth, int Imgheight, unsigned char *bpixel);
void ReadBMPCipher_FH(char *IPbmpfilename, BMPHeaderData *FH_ptr);
void ReadBMPCipher_IH(char *IPbmpfilename, BMPHeaderData *IH_ptr, int Imgwidth, int Imgheight);
void ReadBMPCipher_CM(char *IPbmpfilename, RGBQUAD *CM_ptr);
void ReadBMPCipher_DB(char *IPbmpfilename, int Imgwidth, int Imgheight, unsigned char *bpixel);
void MonitorOutput(BMPHeaderData *Mon_FHptr, BMPHeaderData *Mon_IHptr, RGBQUAD *Mon_CMptr, int imgwidth, int imgheight, unsigned char *bPixel);
void MonOP_FH(BMPHeaderData *Mon_FHptr);
void MonOP_IH(BMPHeaderData *Mon_IHptr);
void MonOP_CM(RGBQUAD *Mon_CMptr);
void MonOP_DB(int imgwidth, int imgheight, unsigned char *bpixel);
void WriteBMPPlain(char *OPPlaintxtfilename, char *IPbmpfilename, BMPHeaderData *Mon_FHptr, BMPHeaderData *Mon_IHptr, RGBQUAD *Mon_CMptr, int imgwidth, int imgheight, unsigned char *bPixel);
void WritePlain_FH(char *OPPlaintxtfilename, char *IPbmpfilename, BMPHeaderData *Mon_FHptr);
void WritePlain_IH(char *OPPlaintxtfilename, BMPHeaderData *Mon_IHptr);
void WritePlain_CM(char *OPPlaintxtfilename, RGBQUAD *Mon_CMptr);
void WritePlain_DB(char *OPPlaintxtfilename, int imgwidth, int imgheight, unsigned char *bpixel);
