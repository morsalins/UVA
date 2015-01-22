#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char line[1000], otpt[1000],otpt1[1000];
    int i,j,n,k;

    while(strcmp(gets(line),"DONE")!=0){
        j=0;
        for(i=0;i<strlen(line);i++){
            if(isalpha(line[i])){
                if(isupper(line[i]))
                    otpt[j++]=tolower(line[i]);
                else otpt[j++]=line[i];
            }
        }
        otpt[j]='\0';
        k=0;
        for(i=j-1;i>=0;i--){
            otpt1[k++]=otpt[i];
        }
        otpt1[k]='\0';

        if( strcmp( otpt,otpt1 )!= 0 )
            printf("Uh oh..\n");
        else
            printf("You won't be eaten!\n");
    }
    return 0;
}
