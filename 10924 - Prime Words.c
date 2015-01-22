#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char line[100];
    int i,j,flag,sum;

    while(gets(line)){
         sum=0;
         for(i=0;i<strlen(line);i++){
            if(isupper(line[i]))
                sum = sum + (line[i]-38);
            else if(islower(line[i]))
                sum = sum + (line[i]-96);
         }

         flag=1;
         if(sum==0){
            printf("It is not a prime word.\n");flag=0;
         }

         else{
            for(i=2;i*i<=sum;i++){
                if(sum%i==0){
                    printf("It is not a prime word.\n");
                    flag=0;
                    break;
                }
            }
         }

         if(flag)
            printf("It is a prime word.\n");
         //printf("\n");
    }
    return 0;
}
