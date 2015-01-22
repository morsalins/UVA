#include<stdio.h>

int main()
{
    int line[3001],otpt[3001],n,i,j,flag,sub;

    while( scanf("%d", &n)==1 ){

        for(i=0;i<=3000;i++) otpt[i]=0;
        for(i=1;i<=n;i++) scanf("%d", &line[i]);

        if(n==1){
            printf("Jolly");
        }

        else{
            sub=0;flag=1;
            for(j=n;j>=2;j--){
                sub = line[j]-line[j-1];
                if(sub<0) sub = sub*(-1);

                if(otpt[sub]==0)
                    otpt[sub]=sub;

                else{
                    printf("Not jolly");
                    flag=0;break;
                }
            }
            if(flag==1){
                for(i=1;i<n;i++){

                    if(otpt[i]==i)continue;

                    else{
                        printf("Not jolly");
                        flag=0;break;
                    }
                }
            }

            if(flag==1)  printf("Jolly");
        }
        printf("\n");
    }
    return 0;
}
