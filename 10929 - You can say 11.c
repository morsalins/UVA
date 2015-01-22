#include<stdio.h>
#include<string.h>

int main()
{
    char line[1010];
    int i,d,once=1;

    while(gets(line)){

        if(!strcmp(line,"0")) break;

        d=0;
        for(i=0;i<strlen(line);i++){
            d = (10*d) + line[i]-48;
            d=d%11;
        }

        if(d==0)printf("%s is a multiple of 11.\n",line);
        else printf("%s is not a multiple of 11.\n",line);

    }
    return 0;
}
