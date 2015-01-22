#include<stdio.h>

int main()
{
    int testcase,caseno;
    float c,f,result;

	scanf("%d", &testcase);

    for(caseno=1;caseno<=testcase;caseno++){
        scanf("%f%f",&c,&f);

        result = (9*c)/5 + 32;

        result=result+f;

        result = (5*(result-32)) / 9;

        printf("Case %d: %.2f\n", caseno,result);
    }
    return 0;
}
