#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){

    char line[1000];
    int i,j,k,num;
    unsigned int sum;

    while(gets(line)){
        if(line[0]==48)
            break;
        sum=0;
        for(i=strlen(line),j=0; j<strlen(line); j++,i--){
            num=line[j]-48;
            sum=sum+ num*( pow(2,i)-1);
        }
        printf("%ld\n",sum);
    }
    return 0;
}
