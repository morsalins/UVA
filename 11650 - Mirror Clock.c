#include<stdio.h>

int main()
{
    int testcase,caseno,hours,mins;

    scanf("%d",&testcase);

    for(caseno=1;caseno<=testcase;caseno++){
        scanf("%d:%d", &hours,&mins);


        if(mins==0)hours=12-hours;

        else hours=(12-hours)-1;

        if(mins!=0)mins=60-mins;

        if(hours<=0)hours=hours+12;

        printf("%02d:%02d\n",hours,mins);
    }
    return 0;
}
