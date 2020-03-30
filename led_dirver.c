#include <led_dirver.h>

volatile int TIM1_WOKING[TIM1_MAX] = {0};
volatile int TIM2_WOKING[TIM2_MAX] = {0};

void HSVtoRGB(RGB * RGB,HSV * HSV)
{
    // R,G,B from 0-255, H from 0-360, S,V from 0-100
    int i;
    float RGB_min, RGB_max;
    RGB_max =  HSV->V*2.55f;
    RGB_min = RGB_max*(100 - HSV->S) / 100.0f;

    i = HSV->H / 60;
    int difs = HSV->H % 60; // factorial part of h

                       // RGB adjustment amount by hue
    float RGB_Adj = (RGB_max - RGB_min)*difs / 60.0f;

    switch (i)
    {
    case 0:
        RGB->R = (int)RGB_max;
        RGB->G = (int)(RGB_min + RGB_Adj);
        RGB->B = (int)RGB_min;
        break;
    case 1:
        RGB->R = (int)(RGB_max - RGB_Adj);
        RGB->G = (int)RGB_max;
        RGB->B = (int)RGB_min;
        break;
    case 2:
        RGB->R = (int)RGB_min;
        RGB->G = (int)RGB_max;
        RGB->B = (int)(RGB_min + RGB_Adj);
        break;
    case 3:
        RGB->R = (int)RGB_min;
        RGB->G = (int)(RGB_max - RGB_Adj);
        RGB->B = (int)RGB_max;
        break;
    case 4:
        RGB->R = (int)(RGB_min + RGB_Adj);
        RGB->G = (int)RGB_min;
        RGB->B = (int)RGB_max;
        break;
    default:		// case 5:
        RGB->R = (int)RGB_max;
        RGB->G = (int)RGB_min;
        RGB->B = (int)(RGB_max - RGB_Adj);
        break;
    }
    printf("R:%d G:%d B%d",RGB->R,RGB->G,RGB->B);
}

int Light_doc_open()
{
    int Get_R_doc=0,Get_G_doc=0,Get_B_doc=0;
    int Res=0;

    printf("Working now!");

    Get_R_doc=open(Red_light_PATH,O_WRONLY);
    if(Get_R_doc<0)
    {
        printf("Fail to open %s device",Red_light_PATH);
    }
    else {
        Res++;
    }

    Get_G_doc=open(Bule_light_PATH,O_WRONLY);
    if(Get_R_doc<0)
    {
        printf("Fail to open %s device",Bule_light_PATH);
    }
    else {
        Res++;
    }


    Get_B_doc=open(Green_light_PATH,O_WRONLY);
    if(Get_R_doc<0)
    {
        printf("Fail to open %s device",Green_light_PATH);
    }

    else {
        Res++;
    }

    write(Get_R_doc,"0",1);
    write(Get_G_doc,"0",1);
    write(Get_B_doc,"0",1);

    return Res;

}

void Light_reflush(RGB * Resault)
{
    int Get_R_doc=0,Get_G_doc=0,Get_B_doc=0;
    int size_num=0;

    Get_R_doc=open(Red_light_PATH,O_WRONLY);
    Get_G_doc=open(Red_light_PATH,O_WRONLY);
    Get_B_doc=open(Red_light_PATH,O_WRONLY);

        if(Resault->R>9)
            size_num=2;
        else if(Resault->R>99)
            size_num=3;
        else {
            size_num=1;
        }

        write(Get_R_doc,&Resault->R,(size_t)size_num);

        if(Resault->B>9)
            size_num=2;
        else if(Resault->B>99)
            size_num=3;
        else {
            size_num=1;
        }

        write(Get_R_doc,&Resault->B,(size_t)size_num);

        if(Resault->G>9)
            size_num=2;
        else if(Resault->G>99)
            size_num=3;
        else {
            size_num=1;
        }

        write(Get_R_doc,&Resault->G,(size_t)size_num);


}

void time_resing(int sig)
{
    static int TIM1_COUNT = 0;
    TIM1_COUNT ++;
  //  printf("%d \n",TIM1_COUNT);

    if(TIM1_COUNT == 99)
    {
     for(int i = 0 ; i < TIM1_MAX;i++ )
     {
         if(TIM1_WOKING[i]<65535)
             TIM1_WOKING[i]++;
     }
     TIM1_COUNT = 0;
    }
    for(int j = 0 ; j < TIM2_MAX;j++ )
    {
        if(TIM2_WOKING[j]<65535)
            TIM2_WOKING[j]++;
    }
}

void timer_init()
{
    struct itimerval itv;

    itv.it_interval.tv_sec=0;
    itv.it_interval.tv_usec=100;
    itv.it_value.tv_sec=1;
    itv.it_value.tv_usec=0;

    setitimer(ITIMER_REAL,&itv,NULL);

}
