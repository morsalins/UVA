#include<stdio.h>

int main()
{
    int testcase,caseno,n,k,p,r,result,s;

    scanf("%d",&testcase);

    for(caseno=1;caseno<=testcase;caseno++){
          scanf("%d%d%d", &n,&k,&p);

          r = p%n;
          s=k+r;
          if(s<=n)
            result = s;

          else if(s>n)
            result = s-n;

          printf("Case %d: %d\n",caseno,result);
    }
    return 0;
}
