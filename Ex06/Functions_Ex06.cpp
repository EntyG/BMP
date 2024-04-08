#include "MyFunctions_Ex06.h"

void releaseBmpPixelArray(PixelArray data) {
	for (uint32_t i = 0; i < data.rowCount; i++) {
		delete[] data.pixels[i];
	}
	delete[] data.pixels;
}

void writeBmpFile(const char* filename, int width, int height) {
	FILE* bmpFile;
	if (fopen_s(&bmpFile, filename, "wb") != 0) {
		std::cerr << "Error opening file for writing.\n";
		return;
	}

	// Create BMP header
	BmpHeader header;
	header.signature.data[0] = 'B';
	header.signature.data[1] = 'M';
	header.fileSize = sizeof(BmpHeader) + sizeof(BmpDib) + width * height * sizeof(Color);
	header.reserved1 = 0;
	header.reserved2 = 0;
	header.dataOffset = sizeof(BmpHeader) + sizeof(BmpDib);

	// Create BMP DIB
	BmpDib dib;
	dib.dibsize = sizeof(BmpDib);
	dib.imageWidth = width;
	dib.imageHeight = height;
	dib.colorPlaneCount = 1;
	dib.pixelSize = 24;
	dib.compressMethod = 0;
	dib.bitmapByteCount = width * height * sizeof(Color);
	dib.horizontalResolution = 0;
	dib.verticalResolution = 0;
	dib.colorCount = 0;
	dib.importantColorCount = 0;

	// Create the flag of England
	Color white = { 255, 255, 255 };
	Color red = { 36, 17, 206 };
	PixelArray pixels;
	pixels.columnCount = width;
	pixels.rowCount = height;
	pixels.pixels = new Color * [height];
	for (int i = 0; i < height; i++) {
		pixels.pixels[i] = new Color[width];
	}
	int stripe = height / 5;
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; x++) {
			if ((x > (width - stripe) / 2 && x < (width - stripe) / 2 + stripe) || (y > (height - stripe) / 2 && y < (height - stripe) / 2 + stripe)) {
				pixels.pixels[y][x] = red;
			}
			else {
				pixels.pixels[y][x] = white;
			}
		}
	}

	// Write BMP file
	fwrite(&header, sizeof(BmpHeader), 1, bmpFile);
	fwrite(&dib, sizeof(BmpDib), 1, bmpFile);
	for (int y = 0; y < height; ++y) {
		fwrite(pixels.pixels[y], sizeof(Color), width, bmpFile);
	}

	fclose(bmpFile);

	releaseBmpPixelArray(pixels);
}