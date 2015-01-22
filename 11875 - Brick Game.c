#include<stdio.h>

int main()
{
    int age[15],testcase,caseno,n,i,captain;

    scanf("%d", &testcase);

    for(caseno=1;caseno<=testcase;caseno++){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&age[i]);

        captain = (1+n)/2;
        printf("Case %d: %d\n", caseno,age[captain]);
    }
    return 0;
}
