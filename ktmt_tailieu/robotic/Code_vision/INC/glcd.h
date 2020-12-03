//*****************************************************************************
// Library functions for graphic LCDs
// (C) 2010-2014 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.10+
//*****************************************************************************

#ifndef _GLCD_INCLUDED_
#define _GLCD_INCLUDED_

#if defined _GLCD_CTRL_ILI9325_
#include <glcd_ili9325.h>
#elif defined _GLCD_CTRL_ILI9340_
#include <glcd_ili9340.h>
#elif defined _GLCD_CTRL_ILI9341_
#include <glcd_ili9341.h>
#elif defined _GLCD_CTRL_KS0108_
#include <glcd_ks0108.h>
#elif defined _GLCD_CTRL_PCD8544_
#include <glcd_pcd8544.h>
#elif defined _GLCD_CTRL_S1D13700_
#include <glcd_s1d13700.h>
#elif defined _GLCD_CTRL_S6D1121_
#include <glcd_s6d1121.h>
#elif defined _GLCD_CTRL_SED1335_
#include <glcd_sed1335.h>
#elif defined _GLCD_CTRL_SED1520_
#include <glcd_sed1520.h>
#elif defined _GLCD_CTRL_SED1530_
#include <glcd_sed1530.h>
#elif defined _GLCD_CTRL_SPLC501_
#include <glcd_splc501.h>
#elif defined _GLCD_CTRL_SSD1289_
#include <glcd_ssd1289.h>
#elif defined _GLCD_CTRL_SSD1303_
#include <glcd_ssd1303.h>
#elif defined _GLCD_CTRL_SSD1322_
#include <glcd_ssd1322.h>
#elif defined _GLCD_CTRL_SSD1963_
#include <glcd_ssd1963.h>
#elif defined _GLCD_CTRL_SSD2119_
#include <glcd_ssd2119.h>
#elif defined _GLCD_CTRL_ST7565_
#include <glcd_st7565.h>
#elif defined _GLCD_CTRL_ST7567_
#include <glcd_st7567.h>
#elif defined _GLCD_CTRL_ST7920_
#include <glcd_st7920.h>
#elif defined _GLCD_CTRL_T6963_
#include <glcd_t6963.h>
#elif defined _GLCD_CTRL_UC1608_
#include <glcd_uc1608.h>
#elif defined _GLCD_CTRL_UC1701_
#include <glcd_uc1701.h>
#elif defined _GLCD_CTRL_XG7100_
#include <glcd_xg7100.h>
#else
#error No graphic controller specified in the project configuration
#endif

#include <graphics.h>
#include <glcd_types.h>

#ifndef NULL
#define NULL 0
#endif

#endif
