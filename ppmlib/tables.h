#pragma once

/**
 * Lookup table for converting PPM bytes to Playdate framebuffer bytes
 * (bits have to be flipped to go from decompressed ppm layer -> playdate framebuffer)
 * (since we're using a lookup table anyway, we may as well have a couple of variants to apply dithering patterns here as well)
 * 
 * To generate the first half of the main table:
 * 	u8 rev(x)
 * 	{
 * 		x = (x & 0x55) << 1 | (x & 0xAA) >> 1;
 * 		x = (x & 0x33) << 2 | (x & 0xCC) >> 2;
 * 		x = (x & 0x0F) << 4 | (x & 0xF0) >> 4;
 * 		return x;
 * 	}
 * 
 * 	for (int i = 0; i < 255; i++)
 * 	{
 * 		printf("0x%.2x", rev(i));
 * 	}
 * 
 * Since patterns need to be 2 pixels high, the first half of the table is used for even lines, and the other half for odd lines
 */
static const u8 LUT_ppmDitherNone[512] =
{
	// odd row (totally full)
	0x00, 0x80, 0x40, 0xc0, 0x20, 0xa0, 0x60, 0xe0, 0x10, 0x90, 0x50, 0xd0, 0x30, 0xb0, 0x70, 0xf0,
	0x08, 0x88, 0x48, 0xc8, 0x28, 0xa8, 0x68, 0xe8, 0x18, 0x98, 0x58, 0xd8, 0x38, 0xb8, 0x78, 0xf8,
	0x04, 0x84, 0x44, 0xc4, 0x24, 0xa4, 0x64, 0xe4, 0x14, 0x94, 0x54, 0xd4, 0x34, 0xb4, 0x74, 0xf4,
	0x0c, 0x8c, 0x4c, 0xcc, 0x2c, 0xac, 0x6c, 0xec, 0x1c, 0x9c, 0x5c, 0xdc, 0x3c, 0xbc, 0x7c, 0xfc,
	0x02, 0x82, 0x42, 0xc2, 0x22, 0xa2, 0x62, 0xe2, 0x12, 0x92, 0x52, 0xd2, 0x32, 0xb2, 0x72, 0xf2,
	0x0a, 0x8a, 0x4a, 0xca, 0x2a, 0xaa, 0x6a, 0xea, 0x1a, 0x9a, 0x5a, 0xda, 0x3a, 0xba, 0x7a, 0xfa,
	0x06, 0x86, 0x46, 0xc6, 0x26, 0xa6, 0x66, 0xe6, 0x16, 0x96, 0x56, 0xd6, 0x36, 0xb6, 0x76, 0xf6,
	0x0e, 0x8e, 0x4e, 0xce, 0x2e, 0xae, 0x6e, 0xee, 0x1e, 0x9e, 0x5e, 0xde, 0x3e, 0xbe, 0x7e, 0xfe,
	0x01, 0x81, 0x41, 0xc1, 0x21, 0xa1, 0x61, 0xe1, 0x11, 0x91, 0x51, 0xd1, 0x31, 0xb1, 0x71, 0xf1,
	0x09, 0x89, 0x49, 0xc9, 0x29, 0xa9, 0x69, 0xe9, 0x19, 0x99, 0x59, 0xd9, 0x39, 0xb9, 0x79, 0xf9,
	0x05, 0x85, 0x45, 0xc5, 0x25, 0xa5, 0x65, 0xe5, 0x15, 0x95, 0x55, 0xd5, 0x35, 0xb5, 0x75, 0xf5,
	0x0d, 0x8d, 0x4d, 0xcd, 0x2d, 0xad, 0x6d, 0xed, 0x1d, 0x9d, 0x5d, 0xdd, 0x3d, 0xbd, 0x7d, 0xfd,
	0x03, 0x83, 0x43, 0xc3, 0x23, 0xa3, 0x63, 0xe3, 0x13, 0x93, 0x53, 0xd3, 0x33, 0xb3, 0x73, 0xf3,
	0x0b, 0x8b, 0x4b, 0xcb, 0x2b, 0xab, 0x6b, 0xeb, 0x1b, 0x9b, 0x5b, 0xdb, 0x3b, 0xbb, 0x7b, 0xfb,
	0x07, 0x87, 0x47, 0xc7, 0x27, 0xa7, 0x67, 0xe7, 0x17, 0x97, 0x57, 0xd7, 0x37, 0xb7, 0x77, 0xf7,
	0x0f, 0x8f, 0x4f, 0xcf, 0x2f, 0xaf, 0x6f, 0xef, 0x1f, 0x9f, 0x5f, 0xdf, 0x3f, 0xbf, 0x7f, 0xff,
	// even row (totally full)
	0x00, 0x80, 0x40, 0xc0, 0x20, 0xa0, 0x60, 0xe0, 0x10, 0x90, 0x50, 0xd0, 0x30, 0xb0, 0x70, 0xf0,
	0x08, 0x88, 0x48, 0xc8, 0x28, 0xa8, 0x68, 0xe8, 0x18, 0x98, 0x58, 0xd8, 0x38, 0xb8, 0x78, 0xf8,
	0x04, 0x84, 0x44, 0xc4, 0x24, 0xa4, 0x64, 0xe4, 0x14, 0x94, 0x54, 0xd4, 0x34, 0xb4, 0x74, 0xf4,
	0x0c, 0x8c, 0x4c, 0xcc, 0x2c, 0xac, 0x6c, 0xec, 0x1c, 0x9c, 0x5c, 0xdc, 0x3c, 0xbc, 0x7c, 0xfc,
	0x02, 0x82, 0x42, 0xc2, 0x22, 0xa2, 0x62, 0xe2, 0x12, 0x92, 0x52, 0xd2, 0x32, 0xb2, 0x72, 0xf2,
	0x0a, 0x8a, 0x4a, 0xca, 0x2a, 0xaa, 0x6a, 0xea, 0x1a, 0x9a, 0x5a, 0xda, 0x3a, 0xba, 0x7a, 0xfa,
	0x06, 0x86, 0x46, 0xc6, 0x26, 0xa6, 0x66, 0xe6, 0x16, 0x96, 0x56, 0xd6, 0x36, 0xb6, 0x76, 0xf6,
	0x0e, 0x8e, 0x4e, 0xce, 0x2e, 0xae, 0x6e, 0xee, 0x1e, 0x9e, 0x5e, 0xde, 0x3e, 0xbe, 0x7e, 0xfe,
	0x01, 0x81, 0x41, 0xc1, 0x21, 0xa1, 0x61, 0xe1, 0x11, 0x91, 0x51, 0xd1, 0x31, 0xb1, 0x71, 0xf1,
	0x09, 0x89, 0x49, 0xc9, 0x29, 0xa9, 0x69, 0xe9, 0x19, 0x99, 0x59, 0xd9, 0x39, 0xb9, 0x79, 0xf9,
	0x05, 0x85, 0x45, 0xc5, 0x25, 0xa5, 0x65, 0xe5, 0x15, 0x95, 0x55, 0xd5, 0x35, 0xb5, 0x75, 0xf5,
	0x0d, 0x8d, 0x4d, 0xcd, 0x2d, 0xad, 0x6d, 0xed, 0x1d, 0x9d, 0x5d, 0xdd, 0x3d, 0xbd, 0x7d, 0xfd,
	0x03, 0x83, 0x43, 0xc3, 0x23, 0xa3, 0x63, 0xe3, 0x13, 0x93, 0x53, 0xd3, 0x33, 0xb3, 0x73, 0xf3,
	0x0b, 0x8b, 0x4b, 0xcb, 0x2b, 0xab, 0x6b, 0xeb, 0x1b, 0x9b, 0x5b, 0xdb, 0x3b, 0xbb, 0x7b, 0xfb,
	0x07, 0x87, 0x47, 0xc7, 0x27, 0xa7, 0x67, 0xe7, 0x17, 0x97, 0x57, 0xd7, 0x37, 0xb7, 0x77, 0xf7,
	0x0f, 0x8f, 0x4f, 0xcf, 0x2f, 0xaf, 0x6f, 0xef, 0x1f, 0x9f, 0x5f, 0xdf, 0x3f, 0xbf, 0x7f, 0xff,	
};

static const u8 LUT_ppmDitherPolka[512] =
{
	// odd row (table with & 0x55 mask applied)
  0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x40, 0x40, 0x10, 0x10, 0x50, 0x50, 0x10, 0x10, 0x50, 0x50,
	0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x40, 0x40, 0x10, 0x10, 0x50, 0x50, 0x10, 0x10, 0x50, 0x50,
	0x04, 0x04, 0x44, 0x44, 0x04, 0x04, 0x44, 0x44, 0x14, 0x14, 0x54, 0x54, 0x14, 0x14, 0x54, 0x54,
	0x04, 0x04, 0x44, 0x44, 0x04, 0x04, 0x44, 0x44, 0x14, 0x14, 0x54, 0x54, 0x14, 0x14, 0x54, 0x54,
	0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x40, 0x40, 0x10, 0x10, 0x50, 0x50, 0x10, 0x10, 0x50, 0x50,
	0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x40, 0x40, 0x10, 0x10, 0x50, 0x50, 0x10, 0x10, 0x50, 0x50,
	0x04, 0x04, 0x44, 0x44, 0x04, 0x04, 0x44, 0x44, 0x14, 0x14, 0x54, 0x54, 0x14, 0x14, 0x54, 0x54,
	0x04, 0x04, 0x44, 0x44, 0x04, 0x04, 0x44, 0x44, 0x14, 0x14, 0x54, 0x54, 0x14, 0x14, 0x54, 0x54,
	0x01, 0x01, 0x41, 0x41, 0x01, 0x01, 0x41, 0x41, 0x11, 0x11, 0x51, 0x51, 0x11, 0x11, 0x51, 0x51,
	0x01, 0x01, 0x41, 0x41, 0x01, 0x01, 0x41, 0x41, 0x11, 0x11, 0x51, 0x51, 0x11, 0x11, 0x51, 0x51,
	0x05, 0x05, 0x45, 0x45, 0x05, 0x05, 0x45, 0x45, 0x15, 0x15, 0x55, 0x55, 0x15, 0x15, 0x55, 0x55,
	0x05, 0x05, 0x45, 0x45, 0x05, 0x05, 0x45, 0x45, 0x15, 0x15, 0x55, 0x55, 0x15, 0x15, 0x55, 0x55,
	0x01, 0x01, 0x41, 0x41, 0x01, 0x01, 0x41, 0x41, 0x11, 0x11, 0x51, 0x51, 0x11, 0x11, 0x51, 0x51,
	0x01, 0x01, 0x41, 0x41, 0x01, 0x01, 0x41, 0x41, 0x11, 0x11, 0x51, 0x51, 0x11, 0x11, 0x51, 0x51,
	0x05, 0x05, 0x45, 0x45, 0x05, 0x05, 0x45, 0x45, 0x15, 0x15, 0x55, 0x55, 0x15, 0x15, 0x55, 0x55,
	0x05, 0x05, 0x45, 0x45, 0x05, 0x05, 0x45, 0x45, 0x15, 0x15, 0x55, 0x55, 0x15, 0x15, 0x55, 0x55,
	// even row (totally empty)
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static const u8 LUT_ppmDitherChecker[512] =
{
	// odd row (table with & 0x55 mask applied)
	0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x40, 0x40, 0x10, 0x10, 0x50, 0x50, 0x10, 0x10, 0x50, 0x50,
	0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x40, 0x40, 0x10, 0x10, 0x50, 0x50, 0x10, 0x10, 0x50, 0x50,
	0x04, 0x04, 0x44, 0x44, 0x04, 0x04, 0x44, 0x44, 0x14, 0x14, 0x54, 0x54, 0x14, 0x14, 0x54, 0x54,
	0x04, 0x04, 0x44, 0x44, 0x04, 0x04, 0x44, 0x44, 0x14, 0x14, 0x54, 0x54, 0x14, 0x14, 0x54, 0x54,
	0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x40, 0x40, 0x10, 0x10, 0x50, 0x50, 0x10, 0x10, 0x50, 0x50,
	0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x40, 0x40, 0x10, 0x10, 0x50, 0x50, 0x10, 0x10, 0x50, 0x50,
	0x04, 0x04, 0x44, 0x44, 0x04, 0x04, 0x44, 0x44, 0x14, 0x14, 0x54, 0x54, 0x14, 0x14, 0x54, 0x54,
	0x04, 0x04, 0x44, 0x44, 0x04, 0x04, 0x44, 0x44, 0x14, 0x14, 0x54, 0x54, 0x14, 0x14, 0x54, 0x54,
	0x01, 0x01, 0x41, 0x41, 0x01, 0x01, 0x41, 0x41, 0x11, 0x11, 0x51, 0x51, 0x11, 0x11, 0x51, 0x51,
	0x01, 0x01, 0x41, 0x41, 0x01, 0x01, 0x41, 0x41, 0x11, 0x11, 0x51, 0x51, 0x11, 0x11, 0x51, 0x51,
	0x05, 0x05, 0x45, 0x45, 0x05, 0x05, 0x45, 0x45, 0x15, 0x15, 0x55, 0x55, 0x15, 0x15, 0x55, 0x55,
	0x05, 0x05, 0x45, 0x45, 0x05, 0x05, 0x45, 0x45, 0x15, 0x15, 0x55, 0x55, 0x15, 0x15, 0x55, 0x55,
	0x01, 0x01, 0x41, 0x41, 0x01, 0x01, 0x41, 0x41, 0x11, 0x11, 0x51, 0x51, 0x11, 0x11, 0x51, 0x51,
	0x01, 0x01, 0x41, 0x41, 0x01, 0x01, 0x41, 0x41, 0x11, 0x11, 0x51, 0x51, 0x11, 0x11, 0x51, 0x51,
	0x05, 0x05, 0x45, 0x45, 0x05, 0x05, 0x45, 0x45, 0x15, 0x15, 0x55, 0x55, 0x15, 0x15, 0x55, 0x55,
	0x05, 0x05, 0x45, 0x45, 0x05, 0x05, 0x45, 0x45, 0x15, 0x15, 0x55, 0x55, 0x15, 0x15, 0x55, 0x55,
	// even row (table with & 0xaa mask applied)
	0x00, 0x80, 0x00, 0x80, 0x20, 0xa0, 0x20, 0xa0, 0x00, 0x80, 0x00, 0x80, 0x20, 0xa0, 0x20, 0xa0,
	0x08, 0x88, 0x08, 0x88, 0x28, 0xa8, 0x28, 0xa8, 0x08, 0x88, 0x08, 0x88, 0x28, 0xa8, 0x28, 0xa8,
	0x00, 0x80, 0x00, 0x80, 0x20, 0xa0, 0x20, 0xa0, 0x00, 0x80, 0x00, 0x80, 0x20, 0xa0, 0x20, 0xa0,
	0x08, 0x88, 0x08, 0x88, 0x28, 0xa8, 0x28, 0xa8, 0x08, 0x88, 0x08, 0x88, 0x28, 0xa8, 0x28, 0xa8,
	0x02, 0x82, 0x02, 0x82, 0x22, 0xa2, 0x22, 0xa2, 0x02, 0x82, 0x02, 0x82, 0x22, 0xa2, 0x22, 0xa2,
	0x0a, 0x8a, 0x0a, 0x8a, 0x2a, 0xaa, 0x2a, 0xaa, 0x0a, 0x8a, 0x0a, 0x8a, 0x2a, 0xaa, 0x2a, 0xaa,
	0x02, 0x82, 0x02, 0x82, 0x22, 0xa2, 0x22, 0xa2, 0x02, 0x82, 0x02, 0x82, 0x22, 0xa2, 0x22, 0xa2,
	0x0a, 0x8a, 0x0a, 0x8a, 0x2a, 0xaa, 0x2a, 0xaa, 0x0a, 0x8a, 0x0a, 0x8a, 0x2a, 0xaa, 0x2a, 0xaa,
	0x00, 0x80, 0x00, 0x80, 0x20, 0xa0, 0x20, 0xa0, 0x00, 0x80, 0x00, 0x80, 0x20, 0xa0, 0x20, 0xa0,
	0x08, 0x88, 0x08, 0x88, 0x28, 0xa8, 0x28, 0xa8, 0x08, 0x88, 0x08, 0x88, 0x28, 0xa8, 0x28, 0xa8,
	0x00, 0x80, 0x00, 0x80, 0x20, 0xa0, 0x20, 0xa0, 0x00, 0x80, 0x00, 0x80, 0x20, 0xa0, 0x20, 0xa0,
	0x08, 0x88, 0x08, 0x88, 0x28, 0xa8, 0x28, 0xa8, 0x08, 0x88, 0x08, 0x88, 0x28, 0xa8, 0x28, 0xa8,
	0x02, 0x82, 0x02, 0x82, 0x22, 0xa2, 0x22, 0xa2, 0x02, 0x82, 0x02, 0x82, 0x22, 0xa2, 0x22, 0xa2,
	0x0a, 0x8a, 0x0a, 0x8a, 0x2a, 0xaa, 0x2a, 0xaa, 0x0a, 0x8a, 0x0a, 0x8a, 0x2a, 0xaa, 0x2a, 0xaa,
	0x02, 0x82, 0x02, 0x82, 0x22, 0xa2, 0x22, 0xa2, 0x02, 0x82, 0x02, 0x82, 0x22, 0xa2, 0x22, 0xa2,
	0x0a, 0x8a, 0x0a, 0x8a, 0x2a, 0xaa, 0x2a, 0xaa, 0x0a, 0x8a, 0x0a, 0x8a, 0x2a, 0xaa, 0x2a, 0xaa,
};

static const u8 LUT_ppmDitherInvPolka[512] =
{
  // odd row (table with & 0xaa mask applied)
  0x00, 0x80, 0x00, 0x80, 0x20, 0xa0, 0x20, 0xa0, 0x00, 0x80, 0x00, 0x80, 0x20, 0xa0, 0x20, 0xa0,
	0x08, 0x88, 0x08, 0x88, 0x28, 0xa8, 0x28, 0xa8, 0x08, 0x88, 0x08, 0x88, 0x28, 0xa8, 0x28, 0xa8,
	0x00, 0x80, 0x00, 0x80, 0x20, 0xa0, 0x20, 0xa0, 0x00, 0x80, 0x00, 0x80, 0x20, 0xa0, 0x20, 0xa0,
	0x08, 0x88, 0x08, 0x88, 0x28, 0xa8, 0x28, 0xa8, 0x08, 0x88, 0x08, 0x88, 0x28, 0xa8, 0x28, 0xa8,
	0x02, 0x82, 0x02, 0x82, 0x22, 0xa2, 0x22, 0xa2, 0x02, 0x82, 0x02, 0x82, 0x22, 0xa2, 0x22, 0xa2,
	0x0a, 0x8a, 0x0a, 0x8a, 0x2a, 0xaa, 0x2a, 0xaa, 0x0a, 0x8a, 0x0a, 0x8a, 0x2a, 0xaa, 0x2a, 0xaa,
	0x02, 0x82, 0x02, 0x82, 0x22, 0xa2, 0x22, 0xa2, 0x02, 0x82, 0x02, 0x82, 0x22, 0xa2, 0x22, 0xa2,
	0x0a, 0x8a, 0x0a, 0x8a, 0x2a, 0xaa, 0x2a, 0xaa, 0x0a, 0x8a, 0x0a, 0x8a, 0x2a, 0xaa, 0x2a, 0xaa,
	0x00, 0x80, 0x00, 0x80, 0x20, 0xa0, 0x20, 0xa0, 0x00, 0x80, 0x00, 0x80, 0x20, 0xa0, 0x20, 0xa0,
	0x08, 0x88, 0x08, 0x88, 0x28, 0xa8, 0x28, 0xa8, 0x08, 0x88, 0x08, 0x88, 0x28, 0xa8, 0x28, 0xa8,
	0x00, 0x80, 0x00, 0x80, 0x20, 0xa0, 0x20, 0xa0, 0x00, 0x80, 0x00, 0x80, 0x20, 0xa0, 0x20, 0xa0,
	0x08, 0x88, 0x08, 0x88, 0x28, 0xa8, 0x28, 0xa8, 0x08, 0x88, 0x08, 0x88, 0x28, 0xa8, 0x28, 0xa8,
	0x02, 0x82, 0x02, 0x82, 0x22, 0xa2, 0x22, 0xa2, 0x02, 0x82, 0x02, 0x82, 0x22, 0xa2, 0x22, 0xa2,
	0x0a, 0x8a, 0x0a, 0x8a, 0x2a, 0xaa, 0x2a, 0xaa, 0x0a, 0x8a, 0x0a, 0x8a, 0x2a, 0xaa, 0x2a, 0xaa,
	0x02, 0x82, 0x02, 0x82, 0x22, 0xa2, 0x22, 0xa2, 0x02, 0x82, 0x02, 0x82, 0x22, 0xa2, 0x22, 0xa2,
	0x0a, 0x8a, 0x0a, 0x8a, 0x2a, 0xaa, 0x2a, 0xaa, 0x0a, 0x8a, 0x0a, 0x8a, 0x2a, 0xaa, 0x2a, 0xaa,
  // even row (totally full)
  0x00, 0x80, 0x40, 0xc0, 0x20, 0xa0, 0x60, 0xe0, 0x10, 0x90, 0x50, 0xd0, 0x30, 0xb0, 0x70, 0xf0,
	0x08, 0x88, 0x48, 0xc8, 0x28, 0xa8, 0x68, 0xe8, 0x18, 0x98, 0x58, 0xd8, 0x38, 0xb8, 0x78, 0xf8,
	0x04, 0x84, 0x44, 0xc4, 0x24, 0xa4, 0x64, 0xe4, 0x14, 0x94, 0x54, 0xd4, 0x34, 0xb4, 0x74, 0xf4,
	0x0c, 0x8c, 0x4c, 0xcc, 0x2c, 0xac, 0x6c, 0xec, 0x1c, 0x9c, 0x5c, 0xdc, 0x3c, 0xbc, 0x7c, 0xfc,
	0x02, 0x82, 0x42, 0xc2, 0x22, 0xa2, 0x62, 0xe2, 0x12, 0x92, 0x52, 0xd2, 0x32, 0xb2, 0x72, 0xf2,
	0x0a, 0x8a, 0x4a, 0xca, 0x2a, 0xaa, 0x6a, 0xea, 0x1a, 0x9a, 0x5a, 0xda, 0x3a, 0xba, 0x7a, 0xfa,
	0x06, 0x86, 0x46, 0xc6, 0x26, 0xa6, 0x66, 0xe6, 0x16, 0x96, 0x56, 0xd6, 0x36, 0xb6, 0x76, 0xf6,
	0x0e, 0x8e, 0x4e, 0xce, 0x2e, 0xae, 0x6e, 0xee, 0x1e, 0x9e, 0x5e, 0xde, 0x3e, 0xbe, 0x7e, 0xfe,
	0x01, 0x81, 0x41, 0xc1, 0x21, 0xa1, 0x61, 0xe1, 0x11, 0x91, 0x51, 0xd1, 0x31, 0xb1, 0x71, 0xf1,
	0x09, 0x89, 0x49, 0xc9, 0x29, 0xa9, 0x69, 0xe9, 0x19, 0x99, 0x59, 0xd9, 0x39, 0xb9, 0x79, 0xf9,
	0x05, 0x85, 0x45, 0xc5, 0x25, 0xa5, 0x65, 0xe5, 0x15, 0x95, 0x55, 0xd5, 0x35, 0xb5, 0x75, 0xf5,
	0x0d, 0x8d, 0x4d, 0xcd, 0x2d, 0xad, 0x6d, 0xed, 0x1d, 0x9d, 0x5d, 0xdd, 0x3d, 0xbd, 0x7d, 0xfd,
	0x03, 0x83, 0x43, 0xc3, 0x23, 0xa3, 0x63, 0xe3, 0x13, 0x93, 0x53, 0xd3, 0x33, 0xb3, 0x73, 0xf3,
	0x0b, 0x8b, 0x4b, 0xcb, 0x2b, 0xab, 0x6b, 0xeb, 0x1b, 0x9b, 0x5b, 0xdb, 0x3b, 0xbb, 0x7b, 0xfb,
	0x07, 0x87, 0x47, 0xc7, 0x27, 0xa7, 0x67, 0xe7, 0x17, 0x97, 0x57, 0xd7, 0x37, 0xb7, 0x77, 0xf7,
	0x0f, 0x8f, 0x4f, 0xcf, 0x2f, 0xaf, 0x6f, 0xef, 0x1f, 0x9f, 0x5f, 0xdf, 0x3f, 0xbf, 0x7f, 0xff,
};


/**
 * Bitmask tables for applying dither patterns to thumbnails
 * These are indexed by the offset of a pixel within a byte
 * Since patterns need to be 2 pixels high, the first half of the table is used for even lines, and the other half for odd lines
 */
static const u8 MASK_tmbDitherNone[16] =
{
	// odd row
  0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE,
	// even row
  0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE,
};

static const u8 MASK_tmbDitherPolka[16] =
{
	// odd row
  0xFF, 0xBF, 0xFF, 0xEF, 0xFF, 0xFB, 0xFF, 0xFE,
	// even row
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};

static const u8 MASK_tmbDitherChecker[16] =
{
	// odd row
  0xFF, 0xBF, 0xFF, 0xEF, 0xFF, 0xFB, 0xFF, 0xFE,
	// even row
  0x7F, 0xFF, 0xDF, 0xFF, 0xF7, 0xFF, 0xFD, 0xFF,
};

static const u8 MASK_tmbDitherInvPolka[16] =
{
  // odd row
  0x7F, 0xFF, 0xDF, 0xFF, 0xF7, 0xFF, 0xFD, 0xFF,
	// even row
  0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE,
};