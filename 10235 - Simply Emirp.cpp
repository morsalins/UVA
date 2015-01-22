#include<stdio.h>

int main()
{
    unsigned long long int n,i,j,rev,m;
    int flag,r,once=1;


    while(scanf("%llu", &n)==1){

        flag=1;

        if(n==0 || n==1) {
            printf("%llu is not prime.", n);
            flag=0;
        }

        for(j=2;j*j<=n;j++){
            if(n%j==0){
                printf("%llu is not prime.", n);
                flag=0;
                break;
            }
        }

        if(flag==1){
            m=n;
            rev=0;
            while(m!=0){
                r=m%10;
                m=m/10;
                rev=10*rev+r;
            }
            for(j=2;j*j<=rev;j++){
                if(rev%j==0){
                    printf("%llu is prime.", n);
                    flag=0;
                    break;
                }
            }


        }

        if(flag==1){
                if(n!=rev)printf("%llu is emirp.", n);
                else printf("%llu is prime.", n);
        }
        printf("\n");
    }
    return 0;
}
