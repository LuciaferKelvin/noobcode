#include <led_dirver.h>

RGB_Value  HSV_TO_RGB(HSV_Value * InitValue,RGB_Value * Resault)
{
        float HSV_C,HSV_X,HSV_M,F_abs;
        float FR,FG,FB;

        HSV_C=InitValue->V*InitValue->S;

        F_abs=((int)((InitValue->H*10/60))%20)/10-1;

        if(F_abs>0);
        else
         F_abs=-F_abs;

        HSV_X=HSV_C*(1-F_abs);

        HSV_M=InitValue->V-HSV_C;



        if(InitValue->H >= 0 && InitValue->H < 60)
        {
         FR=HSV_C;
         FG=HSV_X;
         FB=0;
        }
        else if(InitValue->H >= 60 && InitValue->H < 120)
        {
         FR=HSV_X;
         FG=HSV_C;
         FB=0;
        }

        else if(InitValue->H >= 120 && InitValue->H < 180)
        {
         FR=0;
         FG=HSV_C;
         FB=HSV_X;
        }
        else if(InitValue->H >= 180 && InitValue->H < 240)
        {
         FR=0;
         FG=HSV_X;
         FB=HSV_C;

        }
        else if(InitValue->H >= 240 && InitValue->H < 300)
        {
         FR=HSV_X;
         FG=0;
         FB=HSV_C;
        }
        else if(InitValue->H >= 300 && InitValue->H < 360)
        {
         FR=HSV_C;
         FG=0;
         FB=HSV_X;
        }
        else
        {
         FR=HSV_C;
         FG=HSV_X;
         FB=0;
        }

       Resault->Red_Value=   (int)((FR + HSV_M) * 255) ;
       Resault->Green_Value= (int)((FG + HSV_M) * 255) ;
       Resault->Blue_Value=  (int)((FB + HSV_M) * 255) ;

        return * Resault;

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

void Light_reflush(RGB_Value Resault)
{
    int Get_R_doc=0,Get_G_doc=0,Get_B_doc=0;
    int size_num=0;

    Get_R_doc=open(Red_light_PATH,O_WRONLY);
    Get_G_doc=open(Red_light_PATH,O_WRONLY);
    Get_B_doc=open(Red_light_PATH,O_WRONLY);

    if(time_count)
    {

        if(Resault.Red_Value>9)
            size_num=2;
        else if(Resault.Red_Value>99)
            size_num=3;
        else {
            size_num=1;
        }

        write(Get_R_doc,&Resault.Red_Value,(size_t)size_num);

        if(Resault.Blue_Value>9)
            size_num=2;
        else if(Resault.Blue_Value>99)
            size_num=3;
        else {
            size_num=1;
        }

        write(Get_R_doc,&Resault.Blue_Value,(size_t)size_num);

        if(Resault.Green_Value>9)
            size_num=2;
        else if(Resault.Green_Value>99)
            size_num=3;
        else {
            size_num=1;
        }

        write(Get_R_doc,&Resault.Green_Value,(size_t)size_num);
        time_count=0;
    }

}

void time_resing(int sig)
{
    time_count=1;
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
