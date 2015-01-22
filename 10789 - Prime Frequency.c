#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    int otpt[70],testcase,caseno,i,j,flag,prime;
    char line[2005];

    scanf("%d\n",&testcase);

    for(caseno=1;caseno<=testcase;caseno++){
        gets(line);

        for(i=0;i<70;i++) otpt[i]=0;

        for(i=0;i<strlen(line);i++){
            if(isalpha(line[i])){
                otpt[line[i]-55]++;
            }

            else{
                otpt[line[i]-48]++;
            }
        }
        printf("Case %d: ",caseno);
        prime=0;
        for(i=0;i<70;i++){
            flag = 1;
            if(otpt[i]==1||otpt[i]==0)continue;

            else{
                for(j=2;j*j<=otpt[i];j++){
                    if(otpt[i]%j==0){
                        flag=0;
                        break;
                    }
                }
            }
            if(flag){
                if(i>=0&&i<=9)printf("%c",i+48);
                else printf("%c",i+55);
                prime=1;
            }
        }
        if(!prime)printf("empty");
        printf("\n");
    }
    return 0;
}
