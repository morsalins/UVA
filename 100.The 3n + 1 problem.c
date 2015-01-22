#include<stdio.h>

int main(){
    int i,j,a,b,length,maxlength,temp,n;

    while( scanf("%d %d",&i,&j)==2){
        a=i;b=j;
        if(i>j){
            temp=i;
            i=j;
            j=temp;
        }
        maxlength=0;
        while(i<=j){
            n=i;
            length=1;
            while(n!=1){
                 if(n%2==0) n=n/2;
                 else n=3*n + 1;
                 length++;
            }
            if(length>maxlength) maxlength=length;
            i++;
        }

        printf("%d %d %d\n",a,b,maxlength);
    }
    return 0;
}
