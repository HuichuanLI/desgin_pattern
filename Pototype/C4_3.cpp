#include "BitmapPlus.h"

#include <stdio.h>

int main() {
    BitmapPlus bitmap1(128, 128);
    BitmapPlus bitmap2(256, 256);

    bitmap1 = bitmap2;

    printf("bitmap1 w: %d, h: %d\n", bitmap1.getWidth(), bitmap1.getHeight());
    printf("bitmap2 w: %d, h: %d\n", bitmap2.getWidth(), bitmap2.getHeight());
    return 0;
}