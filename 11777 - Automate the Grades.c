#include<stdio.h>

int main()
{
    int marks[8],testcase,caseno,i,min,result,classtest;
    char grad;

    scanf("%d",&testcase);

    for(caseno=1;caseno<=testcase;caseno++){
        for(i=1;i<8;i++) scanf("%d",&marks[i]);

        result = marks[1]+marks[2]+marks[3]+marks[4];
        classtest=0;
        if(marks[5]>marks[6]){
            classtest=classtest+marks[5];
            min=6;
        }
        else{
           classtest=classtest+marks[6];
           min=5;
        }

        if(marks[min]>marks[7])
           classtest=classtest+marks[min];
        else
           classtest=classtest+marks[7];

        result=result+(classtest/2);

        if(result>=90)grad='A';

        if(result>=80 && result<90)grad='B';

        if(result>= 70 && result<80)grad='C';

        if(result>=60 && result<70)grad='D';

        if(result<60)grad='F';

        printf("Case %d: %c\n",caseno,grad);
    }
    return 0;
}
