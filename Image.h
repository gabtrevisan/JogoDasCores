#pragma once
#include <string.h>
class Image
{
private:
	unsigned int *pixels;
	int width, height;

public:
	Image(int w, int h);
	~Image();

	void setPixel(char *rgb, int x, int y);
	void setPixelsLine(unsigned int *rgb, int size, int x, int y);
	int getPixel(int x, int y);
	unsigned int *getPixelsLine(int x, int y);
	unsigned int *getPixels();

	int getWidth() { return width; }
	int getHeight() { return height; }
};

