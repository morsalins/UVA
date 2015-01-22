#include<stdio.h>
#include<string.h>

int main(){

    char line[1000];
    int g,i,j,k,l;

    while( scanf("%d", &g)==1){

        if(g==0)break;
        getchar();
        gets(line);
        j=strlen(line)/g;

        for(i=0;i<strlen(line);i++){
            k=i;
            l=1;
            while(l<j){
                k++;l++;
            }
            l=k;
            while(l>=i){
                printf("%c",line[l--]);
            }
            i=k;

        }
        printf("\n");
    }
    return 0;
}

