// England, Devin CS230 Section 10989 04/17/2026
// Lab 3 - Bresenham's Algorithm BIT MAP
// Visual Studios build in Win32

#include <iostream>
#include <fstream>
#include "windows.h"
#include <cstdlib>
using namespace std;

#define IMAGE_SIZE 256

void setPixel(char bits[IMAGE_SIZE][IMAGE_SIZE / 8], int x, int y)
{
    if (x < 0 || x >= IMAGE_SIZE || y < 0 || y >= IMAGE_SIZE)
        return;
    bits[y][x / 8] |= (0x80 >> (x % 8));
}

void drawLine(char bits[IMAGE_SIZE][IMAGE_SIZE / 8], int x1, int y1, int x2, int y2)
{
    int deltaX = abs(x2 - x1);
    int deltaY = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = deltaX - deltaY;
    int e2 = 0;

    while (true)
    {
        setPixel(bits, x1, y1);

        if (x1 == x2 && y1 == y2)
            break;

        __asm {
            mov eax, err
            add eax, eax
            mov e2, eax
        }

        if (e2 > -deltaY)
        {
            __asm {
                mov eax, err
                sub eax, deltaY
                mov err, eax
            }
            x1 += sx;
        }

        if (e2 < deltaX)
        {
            __asm {
                mov eax, err
                add eax, deltaX
                mov err, eax
            }
            y1 += sy;
        }
    }
}

int main(int argc, char* argv[])
{
    BITMAPFILEHEADER bmfh;
    BITMAPINFOHEADER bmih;
    char colorTable[8] = { 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff };
    char bits[IMAGE_SIZE][IMAGE_SIZE / 8];

    cout << "Pierce College CS230 Spring 2026 Lab Assignment 3 - England, Devin\n";
    cout << "Enter two pairs of point coordinates in the range of 0-" << IMAGE_SIZE - 1 << ".\n";

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    bool bad = false;

    if (x1 < 0 || x1 >= IMAGE_SIZE) {
        cout << "Value " << x1 << " out of range, ending.\n";
        bad = true;
    }
    if (y1 < 0 || y1 >= IMAGE_SIZE) {
        cout << "Value " << y1 << " out of range, ending.\n";
        bad = true;
    }
    if (x2 < 0 || x2 >= IMAGE_SIZE) {
        cout << "Value " << x2 << " out of range, ending.\n";
        bad = true;
    }
    if (y2 < 0 || y2 >= IMAGE_SIZE) {
        cout << "Value " << y2 << " out of range, ending.\n";
        bad = true;
    }

    if (bad)
        return 0;

    ofstream bmpOut("foo.bmp", ios::out | ios::binary);
    if (!bmpOut) {
        cout << "...could not open file, ending.";
        return -1;
    }

    bmfh.bfType = 0x4d42;
    bmfh.bfReserved1 = 0;
    bmfh.bfReserved2 = 0;
    bmfh.bfOffBits = sizeof(bmfh) + sizeof(bmih) + sizeof(colorTable);
    bmfh.bfSize = bmfh.bfOffBits + sizeof(bits);

    bmih.biSize = 40;
    bmih.biWidth = IMAGE_SIZE;
    bmih.biHeight = IMAGE_SIZE;
    bmih.biPlanes = 1;
    bmih.biBitCount = 1;
    bmih.biCompression = 0;
    bmih.biSizeImage = 0;
    bmih.biXPelsPerMeter = 2835;
    bmih.biYPelsPerMeter = 2835;
    bmih.biClrUsed = 0;
    bmih.biClrImportant = 0;

    // clear image to black
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE / 8; j++) {
            bits[i][j] = 0x00;
        }
    }

    drawLine(bits, x1, y1, x2, y2);

    char* workPtr;
    workPtr = (char*)&bmfh;
    bmpOut.write(workPtr, 14);

    workPtr = (char*)&bmih;
    bmpOut.write(workPtr, 40);

    workPtr = &colorTable[0];
    bmpOut.write(workPtr, 8);

    workPtr = &bits[0][0];
    bmpOut.write(workPtr, IMAGE_SIZE * IMAGE_SIZE / 8);

    bmpOut.close();

    system("start foo.bmp");
    return 0;
}