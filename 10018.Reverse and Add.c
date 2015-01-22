#include<stdio.h>

int main(){
    long int num,new_num,temp,t;
    int r,i,count;

    while(scanf("%ld", &t)==1){

    for(i=1;i<=t;i++){
        scanf("%ld", &num);
        count=0;
        while(1){
            temp=num;
            new_num=0;
            while(num>0){
                r=num%10;
                num=num/10;
                new_num=10*new_num+r;
            }

            if(temp==new_num)
                break;

            else{
                count++;
                num=temp+new_num;
            }
        }

        printf("%d %ld", count, temp);
        printf("\n");
    }
    }

    return 0;
}
