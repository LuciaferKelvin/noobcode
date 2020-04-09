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

enum
{
    TIM1_WORK = 0,
    TIM1_LEDS,
    TIM1_MAX
};

enum
{
    TIM2_WORK = 0,
    TIM2_MAX

};

#define TIM1_1MS(index,count) (count < TIM1_WOKING[index] ? 1 : 0 )
#define TIM1_StatusClear(index) (TIM1_WOKING[index]=0)

#define TIM2_1US(index,count) (count < TIM2_WOKING[index] ? 1 : 0 )
#define TIM2_StatusClear(index) (TIM2_WOKING[index]=0)

extern volatile int TIM1_WOKING[TIM1_MAX];
extern volatile int TIM2_WOKING[TIM2_MAX];

typedef struct RGB{
    int R;
    int G;
    int B;
}RGB;

typedef struct HSV{
    int H;
    int S;
    int V;
} HSV;


void HSVtoRGB(RGB * RGB,HSV * HSV);


void Light_reflush(RGB * Resault);
int Light_doc_open();
void timer_init();
void time_resing(int sig);


#endif // LED_DIRVER_H
