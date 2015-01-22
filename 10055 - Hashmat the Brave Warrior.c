#include<stdio.h>

int main(){
    unsigned long long int hashmat, opponent;

    while( scanf("%llu%llu",&hashmat,&opponent)==2 ){
        if(opponent>hashmat)printf("%llu\n",opponent-hashmat);
        else printf("%llu\n",hashmat-opponent);
      }
    return 0;
}
