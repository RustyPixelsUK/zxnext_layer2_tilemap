
#ifndef _ZCONFIG_H
#define _ZCONFIG_H

#define RES_256x192				0
#define RES_320x256				1
#define RES_640x256				2

#define SCREEN_RES				RES_320x256

#define RTM_28MHZ				0x03

#define WFRAMES					4

#define TILE_X					8
#define TILE_Y					8
#define TILE_SIZE				(TILE_X * TILE_Y)
#define TILE_BANK_COUNT			(BANKSIZE_16K / TILE_SIZE)

#if (SCREEN_RES == RES_256x192)
#define SCREEN_X				256
#define SCREEN_Y				192
#elif (SCREEN_RES == RES_320x256)
#define SCREEN_X				320
#define SCREEN_Y				256
#elif (SCREEN_RES == RES_640x256)
#define SCREEN_X				640
#define SCREEN_Y				256
#endif

#define SCREEN_SIZE				(SCREEN_X * SCREEN_Y)
#define SCREEN_TILES_X			(SCREEN_X / TILE_X)
#define SCREEN_TILES_Y			(SCREEN_Y / TILE_Y)
#define SCREEN_TILES_COUNT		(SCREEN_TILES_X * SCREEN_TILES_Y)

#define SCREEN_BANK_X			(BANKSIZE_16K / SCREEN_Y)
#define SCREEN_BANK_Y			(BANKSIZE_16K / SCREEN_X)

#define NEXTREG_REGISTER_SELECT_PORT	0x243b
#define RASTER_LINE_MSB_REGISTER		0x1e
#define RASTER_LINE_LSB_REGISTER		0x1f

#define LOOP_INFINITE                   0xff

#define MMU_LAYER2				MMU_0000
#define PAGE_LAYER2				9

#define MMU_LAYER2_MAP			MMU_4000
#define PAGE_LAYER2_MAP			17

#define MMU_LAYER2_TILES		MMU_C000
#define PAGE_LAYER2_TILES		32

#define USE_ASM_VERSION			1

#define USE_INTERNAL_FONT       0

#define ALIGN_MOD_LUT		    1

#define MAP_Y_FIRST		        0

#define CRT_6000				0

#endif
