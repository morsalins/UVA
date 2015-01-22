#include<stdio.h>

int main()
{
    int jumps[51],testcase,caseno,n,i,high,low;

    scanf("%d",&testcase);

    for(caseno=1;caseno<=testcase;caseno++){

        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&jumps[i]);

        high=0;low=0;
        for(i=1;i<=n-1;i++){
            if(jumps[i]==jumps[i+1]) continue;

            if(jumps[i]<jumps[i+1])
                high++;

            else if(jumps[i]>jumps[i+1])
                low++;

        }
        printf("Case %d: %d %d\n",caseno,high,low);
    }
    return 0;
}
