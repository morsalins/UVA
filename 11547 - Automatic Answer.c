#include<stdio.h>

int main()
{
    int testcase,n,tens;
    long long int result;

    scanf("%d",&testcase);

    while(testcase--){
        scanf("%d",&n);

        result = (((((n*567)/9)+7492)*235)/47)-498;

        if(result<0)result=result* (-1);
        int i=2;
        while(i--){
            tens = result%10;
            result=result/10;
        }
        printf("%d\n",tens);
    }

    return 0;
}
