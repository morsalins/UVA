#include<stdio.h>

int main(){
    int n,x,i,count=0,caseno=1;

    while( scanf("%d",&n)!=EOF ){
        if(n<0)break;
        count=0;x=1;
        while(x<n){
        x=x+x;
        count++;
        }
        printf("Case %d: %d\n",caseno,count);
        caseno++;
    }

    return 0;
}
