/**
Jogo das Cores
@author Gabriela de Campos Trevisan
*/

#include "Image.h"
Image::Image(int w, int h)
{
	width = w;
	height = h;
	pixels = new unsigned int[width*height];
}

Image::~Image()
{
	delete pixels;
}

void Image::setPixel(char *rgb, int x, int y) {
	unsigned int pix = rgb[0] << 24 | (rgb[1] & 0xFF) << 16 | (rgb[2] & 0xFF) << 8 | (rgb[3] & 0xFF);
	pixels[x + y*width] = pix;
}

void Image::setPixelsLine(unsigned int *rgb, int size, int x, int y) {
	unsigned int* pixelpointer = pixels;
	pixelpointer += x + y * width;
	memcpy(pixelpointer, rgb, size * sizeof(int));		
}

int Image::getPixel(int x, int y) {
	return pixels[x + y*getWidth()];
}

unsigned int *Image::getPixels() {
	return pixels;
}

unsigned int *Image::getPixelsLine(int x, int y) {
	unsigned int* pixelspointer = pixels;
	pixelspointer += x + y * width;
	return pixelspointer;
}