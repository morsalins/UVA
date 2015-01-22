#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char line[210];
    int otpt[26],testcase,caseno,i,j,max;

    scanf("%d\n",&testcase);

    for(caseno=1;caseno<=testcase;caseno++){
        gets(line);
        for(i=0;i<26;i++)otpt[i]=0;

        for(i=0;i<strlen(line);i++){
            if(isalpha(line[i])){
                if(isupper(line[i]))
                    line[i]=tolower(line[i]);

                otpt[line[i]-97]++;
            }
        }
        max=0;
        for(i=1;i<26;i++){
            if(otpt[i]>otpt[max])max=i;
        }

        printf("%c",max+97);

        for(i=max+1;i<26;i++){
            if(otpt[i]==otpt[max])
                printf("%c",i+97);
        }
        printf("\n");
    }
    return 0;
}
