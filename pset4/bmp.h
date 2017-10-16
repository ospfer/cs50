/**
 * BMP-related data types based on Microsoft's own.
 */

#include <stdint.h>

/**
 * Common Data Types
 *
 * The data types in this section are essentially aliases for C/C++
 * primitive data types.
 *
 * Adapted from https://msdn.microsoft.com/en-us/library/cc230309.aspx.
 * See http://en.wikipedia.org/wiki/Stdint.h for more on stdint.h.
 */
typedef uint8_t  BYTE; //1 byte, 8 bits
typedef uint32_t DWORD; //4 bytes, 32 bits
typedef int32_t  LONG; //4 bytes, 32 bits
typedef uint16_t WORD; //2 bytes, 16 bits

/**
 * BITMAPFILEHEADER
 *
 * The BITMAPFILEHEADER structure contains information about the type, size,
 * and layout of a file that contains a DIB [device-independent bitmap].
 *
 * Adapted from https://msdn.microsoft.com/en-us/library/dd183374(v=vs.85).aspx.
 */
typedef struct
{
    WORD bfType; //2 bytes
    DWORD bfSize; //4 bytes
    WORD bfReserved1; //2 bytes
    WORD bfReserved2; //2 bytes
    DWORD bfOffBits; //4 bytes
} __attribute__((__packed__))
BITMAPFILEHEADER; //14 bytes

/**
 * BITMAPINFOHEADER
 *
 * The BITMAPINFOHEADER structure contains information about the
 * dimensions and color format of a DIB [device-independent bitmap].
 *
 * Adapted from https://msdn.microsoft.com/en-us/library/dd183376(v=vs.85).aspx.
 */
typedef struct
{
    DWORD biSize; //4 bytes
    LONG biWidth; //4 bytes
    LONG biHeight; //4 bytes
    WORD biPlanes; //2 bytes
    WORD biBitCount; //2 bytes
    DWORD biCompression; //4 bytes
    DWORD biSizeImage; //4 bytes
    LONG biXPelsPerMeter; //4 bytes
    LONG biYPelsPerMeter; //4 bytes
    DWORD biClrUsed; //4 bytes
    DWORD biClrImportant; //4 bytes
} __attribute__((__packed__))
BITMAPINFOHEADER; //40 bytes

/**
 * RGBTRIPLE
 *
 * This structure describes a color consisting of relative intensities of
 * red, green, and blue.
 *
 * Adapted from https://msdn.microsoft.com/en-us/library/dd162939(v=vs.85).aspx.
 */
typedef struct
{
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;
