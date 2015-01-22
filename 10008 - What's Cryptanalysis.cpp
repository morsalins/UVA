#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char line[100];
    int i,j,k,l,n,otpt[26],max;

    while( scanf("%d\n", &n)==1 ){

        for(i=0;i<26;i++) otpt[i] = 0;

        for(l=1;l<=n;l++){
            //getchar();
            gets(line);

			for(i=0;i<strlen(line);i++){
                if(isalpha(line[i])){
                    line[i] = toupper(line[i]);
                    otpt[line[i]-65]++;
                }
            }
        }

         for(j=0;j<26;j++){
                max = 0;
                for(i=0;i<26;i++){
                    if(otpt[i]>otpt[max]) max=i;
                }
                if(otpt[max]!=0)
                    printf("%c %d\n", max+65,otpt[max]);
				otpt[max]=false;
        }
    }
    return 0;
}
