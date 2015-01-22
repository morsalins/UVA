#include<stdio.h>

int main()
{
    int testcase,n,i,above;
    float grd[1005],avg,num,sum,result;

    scanf("%d", &testcase);

    while(testcase--){
        scanf("%d", &n);
        sum=0;
        for(i=0;i<n;i++){
            scanf("%f", &num);
            sum = sum+num;
            grd[i]=num;
        }

        avg=sum/n;
        above=0;

        for(i=0;i<n;i++){
            if(grd[i]>avg)
                above++;
		}
		result = (float)(above*100);

        printf("%.3f%%\n", result/n);
    }

    return 0;
}
