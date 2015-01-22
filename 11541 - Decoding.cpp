#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char line[200],ch;
    int i,j,k,testcase,caseno,num;

    scanf("%d\n",&testcase);

    for(caseno=1;caseno<=testcase;caseno++){
        gets(line);

        printf("Case %d: ",caseno);
        for(i=0;i<strlen(line);i++){
            if(isalpha(line[i]))ch=line[i];

            else if( line[i]>=48 && line[i]<=57 ){
                k=i;num=0;
                while( line[k]>=48 && line[k]<=57 ){
                    num=10*num + (line[k]-48);
                    k++;
                }
                i=k-1;

                for(j=1;j<=num;j++)printf("%c",ch);
            }
        }
        printf("\n");
    }
    return 0;
}
