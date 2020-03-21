#ifndef LED_DIRVER_H
#define LED_DIRVER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>

#define Red_light_PATH "/sys/class/leds/red/brightness"
#define Bule_light_PATH "/sys/class/leds/bule/brightness"
#define Green_light_PATH "/sys/class/leds/green/brightness"


typedef struct RGB{
    int Red_Value;
    int Blue_Value;
    int Green_Value;
}RGB_Value;

typedef struct HSV{
    int H;
    float S;
    float V;
} HSV_Value;

RGB_Value HSV_TO_RGB(HSV_Value * InitValue,RGB_Value * Resault);

static int time_count = 0;

void Light_reflush(RGB_Value  Resault);
int Light_doc_open();
void timer_init();
void time_resing(int sig);


#endif // LED_DIRVER_H
