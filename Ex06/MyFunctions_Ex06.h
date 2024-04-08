#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

struct BmpSignature {
	unsigned char data[2];
};

#pragma pack(1)

struct BmpHeader {
	BmpSignature signature;
	uint32_t fileSize;
	uint16_t reserved1;
	uint16_t reserved2;
	uint32_t dataOffset;
};

struct BmpDib {
	uint32_t dibsize;
	int32_t imageWidth;
	int32_t imageHeight;
	uint16_t colorPlaneCount;
	uint16_t pixelSize;
	uint32_t compressMethod;
	uint32_t bitmapByteCount;
	int32_t horizontalResolution;
	int32_t verticalResolution;
	uint32_t colorCount;
	uint32_t importantColorCount;
};

struct Color {
	unsigned char blue;
	unsigned char green;
	unsigned char red;
};

struct colorTable {
	Color* colors;
	uint32_t lenght;
};

struct PixelArray {
	Color** pixels;
	uint32_t rowCount;
	uint32_t columnCount;
};

void releaseBmpPixelArray(PixelArray data);
void writeBmpFile(const char* filename, int width, int height);