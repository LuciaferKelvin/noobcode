#ifndef MAIN_H
#define MAIN_H

#include <led_dirver.h>
#include "stdio.h"
#include "stdbool.h"

typedef struct MULL_LED{
    HSV MULL_LED_HSV;
    RGB MULL_LED_RGB;

} MULL_LED;

typedef struct MULL
{
    MULL_LED MULL_LED;
}MULL;

extern MULL MULL_WORK;
extern bool Test_flag;

#endif // MAIN_H
