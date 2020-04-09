#include <main.h>

MULL MULL_WORK;
bool Test_flag = false;

int main()
{
    struct itimerval itv;
    signal(SIGALRM,time_resing);
    timer_init();
    MULL_WORK.MULL_LED.MULL_LED_HSV.H = 0;
    MULL_WORK.MULL_LED.MULL_LED_HSV.S = 100;
    MULL_WORK.MULL_LED.MULL_LED_HSV.V = 100;

    while(1)
    {
        if(TIM1_1MS(TIM1_WORK,2))
        {
            printf("%d\t",MULL_WORK.MULL_LED.MULL_LED_HSV.H);


             HSVtoRGB(&MULL_WORK.MULL_LED.MULL_LED_RGB,&MULL_WORK.MULL_LED.MULL_LED_HSV) ;

             if(Test_flag)
                 MULL_WORK.MULL_LED.MULL_LED_HSV.H --;
             else
             {
                  MULL_WORK.MULL_LED.MULL_LED_HSV.H++;
             }
             if(MULL_WORK.MULL_LED.MULL_LED_HSV.H <= 0)
                 Test_flag = false;
             else if (MULL_WORK.MULL_LED.MULL_LED_HSV.H >= 360)
             {
                 Test_flag = true;
             }
             printf("\tIN!!!\n");

             TIM1_StatusClear(TIM1_WORK);

        }
//        printf("TIM1_WOKING[TIM1_WORK] = %d \n",TIM1_WOKING[TIM1_WORK]);

    }

    return 0;
}
