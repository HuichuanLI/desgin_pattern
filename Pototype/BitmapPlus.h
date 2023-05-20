#pragma once

#include <stdint.h>

class BitmapPlus
{
public:
	BitmapPlus();
	BitmapPlus(int w, int h);
	~BitmapPlus();

	BitmapPlus(const BitmapPlus & bitmap);

	BitmapPlus & operator = (const BitmapPlus & bitmap);

	int getWidth();
	int getHeight();
private:
	int width = 0;
	int height = 0;
	uint8_t* data = nullptr;
};

