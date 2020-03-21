#include <main.h>


int main()
{
    struct itimerval itv;
    signal(SIGALRM,time_resing);
    timer_init();
    while(1)
    {
        if(time_count)
        {
            printf("Working");
            time_count=0;
        }


    }

    return 0;
}
