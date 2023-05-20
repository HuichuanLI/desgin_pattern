#include "BitmapPlus.h"

#include <stdlib.h>
#include <string.h>

BitmapPlus::BitmapPlus()
{

}

BitmapPlus::BitmapPlus(int w, int h)
{
	width = w;
	height = h;
	data = (uint8_t *)malloc(width * height * 4);
}

BitmapPlus::BitmapPlus(const BitmapPlus& bitmap)
{
	*this = bitmap;
}

BitmapPlus & BitmapPlus::operator = (const BitmapPlus & bitmap)
{
	if (data != nullptr) {
		free(data);
		data = nullptr;
	}

	width = bitmap.width;
	height = bitmap.height;
	data = (uint8_t *)malloc(width * height * 4);
	memcpy(data, bitmap.data, width * height * 4);

	return *this;
}

BitmapPlus::~BitmapPlus()
{
	if (data != nullptr) {
		free(data);
		data = nullptr;
	}
}

int BitmapPlus::getWidth()
{
	return width;
}

int BitmapPlus::getHeight()
{
	return height;
}