/*******************************************************************************
 * Size: 94 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef DIGIFACEWIDE
#define DIGIFACEWIDE 1
#endif

#if DIGIFACEWIDE

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0030 "0" */
    0x0, 0x7, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x0,
    0x3, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x3,
    0xff, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x1, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x0, 0x0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xc0, 0x0, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x0, 0xf0, 0xff, 0xff, 0xff,
    0xff, 0xc3, 0xc0, 0x7e, 0x1f, 0xff, 0xff, 0xff,
    0xe1, 0xf8, 0x7f, 0xe0, 0x0, 0x0, 0x0, 0x1,
    0xff, 0xbf, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xff, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x1, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0x1f, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0x80, 0x0, 0x0,
    0x0, 0x0, 0x7, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xfd, 0xff, 0x80, 0x0, 0x0,
    0x0, 0x7, 0xfe, 0x1f, 0x87, 0xff, 0xff, 0xff,
    0xf8, 0x7e, 0x3, 0xc3, 0xff, 0xff, 0xff, 0xff,
    0xf, 0x0, 0x3, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x1, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0,
    0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0,
    0xf, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0, 0x0,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x1f,
    0xff, 0xff, 0xff, 0xe0, 0x0,

    /* U+0031 "1" */
    0x0, 0x10, 0x3, 0x0, 0xf0, 0x1f, 0x7, 0xf0,
    0xff, 0x3f, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x7f, 0xf1, 0xff, 0x3, 0xf0, 0xf,
    0x0, 0x10, 0x0, 0x0, 0x0, 0x1, 0x0, 0xf0,
    0x7f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x7f, 0xf3, 0xff, 0xf, 0xf0, 0x7f,
    0x1, 0xf0, 0xf, 0x0, 0x30, 0x1,

    /* U+0032 "2" */
    0x0, 0x7, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x0,
    0x7, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x3,
    0xff, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x3, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x0, 0x3, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xc0, 0x3, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x1, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xc3, 0xc1, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xe1, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
    0xff, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xf0, 0x0, 0x7f, 0xff, 0xff, 0xff, 0x81,
    0xfc, 0x0, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x1f,
    0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xc1,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe2, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0xf0, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0x80, 0x3f, 0x83, 0xff, 0xff,
    0xff, 0xff, 0x0, 0xf, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3, 0xff, 0xc0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0xff, 0x80, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1f, 0x87, 0xff, 0xff, 0xff,
    0xfe, 0x0, 0x3, 0xc3, 0xff, 0xff, 0xff, 0xff,
    0xe0, 0x0, 0x3, 0xff, 0xff, 0xff, 0xff, 0xfc,
    0x0, 0x1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,
    0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0,
    0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x1f,
    0xff, 0xff, 0xff, 0xff, 0xfe,

    /* U+0033 "3" */
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x0, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0xe0, 0x0, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xe0, 0x0, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xe0, 0x0, 0x1f, 0xff, 0xff, 0xff, 0xff,
    0x0, 0x0, 0x1f, 0xff, 0xff, 0xff, 0xf8, 0x78,
    0x0, 0xf, 0xff, 0xff, 0xff, 0xe1, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xfc, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x1,
    0xff, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1f, 0xfe, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff,
    0xe0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xc0,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0x80, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xfe, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x7f, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0xe0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xc0, 0xf,
    0xff, 0xff, 0xff, 0xf0, 0x3f, 0x80, 0x7f, 0xff,
    0xff, 0xff, 0xfc, 0x1f, 0x7, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x6, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x10,
    0x1f, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xe0, 0x7,
    0xff, 0xff, 0xff, 0xfc, 0x1f, 0xc0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xff, 0x80, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1f, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xf8,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0xff, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x3, 0xff, 0xc0, 0x0, 0x0, 0x0,
    0x0, 0x7, 0xff, 0x80, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1f,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x7, 0xff, 0x80, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7f, 0xe0, 0x1, 0xff, 0xff,
    0xff, 0xfc, 0x3f, 0x0, 0xf, 0xff, 0xff, 0xff,
    0xfc, 0x3c, 0x0, 0x3f, 0xff, 0xff, 0xff, 0xfe,
    0x0, 0x1, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0,
    0x7, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0, 0x3f,
    0xff, 0xff, 0xff, 0xff, 0xf0, 0x0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x80, 0x3, 0xff, 0xff, 0xff,
    0xff, 0xfe, 0x0, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3e, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xe0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xfc, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xff, 0x80, 0x0, 0x0,
    0x0, 0x0, 0x7, 0xff, 0xf8, 0x0, 0x0, 0x0,
    0x0, 0x7, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xff, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0x81,
    0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x1f,
    0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xc1,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc1, 0x0, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0x83, 0xc0, 0x3, 0xff, 0xff,
    0xff, 0xff, 0x7, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xc0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1c, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1,

    /* U+0035 "5" */
    0x0, 0x7, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0,
    0x3, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0, 0x3,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x0, 0x1, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x80, 0x0, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x0, 0xf0, 0xff, 0xff, 0xff,
    0xff, 0xc0, 0x0, 0x7e, 0x1f, 0xff, 0xff, 0xff,
    0xe0, 0x0, 0x7f, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0x80,
    0x3, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0,
    0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x1,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc1, 0x0, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0x83, 0xc0, 0x3, 0xff, 0xff,
    0xff, 0xff, 0x7, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7, 0xfe, 0x0, 0x1f, 0xff, 0xff, 0xff,
    0xf8, 0x7e, 0x0, 0x1f, 0xff, 0xff, 0xff, 0xff,
    0xf, 0x0, 0xf, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0,
    0x7, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x3,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x3, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x1, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xe0, 0x0,

    /* U+0036 "6" */
    0x0, 0x7, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0,
    0x3, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0, 0x3,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x0, 0x1, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x80, 0x0, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x0, 0xf0, 0xff, 0xff, 0xff,
    0xff, 0xc0, 0x0, 0x7e, 0x1f, 0xff, 0xff, 0xff,
    0xe0, 0x0, 0x7f, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0x80,
    0x3, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0,
    0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x1,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe2, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc1, 0xf0, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0x83, 0xff, 0x83, 0xff, 0xff,
    0xff, 0xff, 0x7, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xfd, 0xff, 0x80, 0x0, 0x0,
    0x0, 0x7, 0xfe, 0x1f, 0x87, 0xff, 0xff, 0xff,
    0xf8, 0x7e, 0x3, 0xc3, 0xff, 0xff, 0xff, 0xff,
    0xf, 0x0, 0x3, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x1, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0,
    0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0,
    0xf, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0, 0x0,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x1f,
    0xff, 0xff, 0xff, 0xe0, 0x0,

    /* U+0037 "7" */
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x1f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc3, 0x3, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x87, 0x1, 0xff, 0xff, 0xff,
    0xff, 0xfe, 0x1f, 0x0, 0x7f, 0xff, 0xff, 0xff,
    0xfc, 0x3f, 0x0, 0x3f, 0xff, 0xff, 0xff, 0xf0,
    0xff, 0x0, 0xf, 0xff, 0xff, 0xff, 0xe1, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1,

    /* U+0038 "8" */
    0x0, 0x7, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x0,
    0x3, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x3,
    0xff, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x1, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x0, 0x0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xc0, 0x0, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x0, 0xf0, 0xff, 0xff, 0xff,
    0xff, 0xc3, 0xc0, 0x7e, 0x1f, 0xff, 0xff, 0xff,
    0xe1, 0xf8, 0x7f, 0xe0, 0x0, 0x0, 0x0, 0x1,
    0xff, 0xbf, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xff, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0x81,
    0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x1f,
    0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xc1,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe2, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc1, 0xf0, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0x83, 0xff, 0x83, 0xff, 0xff,
    0xff, 0xff, 0x7, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xfd, 0xff, 0x80, 0x0, 0x0,
    0x0, 0x7, 0xfe, 0x1f, 0x87, 0xff, 0xff, 0xff,
    0xf8, 0x7e, 0x3, 0xc3, 0xff, 0xff, 0xff, 0xff,
    0xf, 0x0, 0x3, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x1, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0,
    0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0,
    0xf, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0, 0x0,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x1f,
    0xff, 0xff, 0xff, 0xe0, 0x0,

    /* U+0039 "9" */
    0x0, 0x7, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x0,
    0x3, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x3,
    0xff, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x1, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x0, 0x0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xc0, 0x0, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x0, 0xf0, 0xff, 0xff, 0xff,
    0xff, 0xc3, 0xc0, 0x7e, 0x1f, 0xff, 0xff, 0xff,
    0xe1, 0xf8, 0x7f, 0xe0, 0x0, 0x0, 0x0, 0x1,
    0xff, 0xbf, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xff, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x0,
    0xff, 0xff, 0xf0, 0x7f, 0xff, 0xff, 0xff, 0x83,
    0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x1f,
    0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xc1,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x0, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0x81, 0xc0, 0x3, 0xff, 0xff,
    0xff, 0xff, 0x3, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x7, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7, 0xfe, 0x0, 0x7, 0xff, 0xff, 0xff,
    0xf8, 0x7e, 0x0, 0x3, 0xff, 0xff, 0xff, 0xff,
    0xf, 0x0, 0x3, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x1, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0,
    0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x0, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0xe0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 1117, .box_w = 58, .box_h = 68, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 493, .adv_w = 1117, .box_w = 12, .box_h = 68, .ofs_x = 29, .ofs_y = 0},
    {.bitmap_index = 595, .adv_w = 1117, .box_w = 58, .box_h = 68, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 1088, .adv_w = 1117, .box_w = 55, .box_h = 68, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1556, .adv_w = 1117, .box_w = 58, .box_h = 68, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 2049, .adv_w = 1117, .box_w = 58, .box_h = 68, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 2542, .adv_w = 1117, .box_w = 58, .box_h = 68, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 3035, .adv_w = 1117, .box_w = 56, .box_h = 68, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3511, .adv_w = 1117, .box_w = 58, .box_h = 68, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 4004, .adv_w = 1117, .box_w = 58, .box_h = 68, .ofs_x = 6, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 48, .range_length = 10, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t digifacewide = {
#else
lv_font_t digifacewide = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 68,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = 0,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .fallback = NULL,
    .user_data = NULL,
};



#endif /*#if DIGIFACEWIDE*/

