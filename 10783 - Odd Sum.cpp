#include<cstdio>

using namespace std;

int main()
{
    int a, b, sum, tc;

    scanf("%d", &tc);

    for(int kase=1; kase<=tc; kase++){

        scanf("%d%d", &a, &b);

        sum = 0;
        if(a%2==0)a++;
        if(b%2==0)b--;

        for(int i=a; i<=b; i+=2){
            sum+=i;
        }

        printf("Case %d: %d\n", kase, sum);
    }

    return 0;
}
