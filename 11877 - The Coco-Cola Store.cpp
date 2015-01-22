#include<cstdio>

using namespace std;

int main()
{
   // freopen("i.txt", "r", stdin);
   // freopen("o.txt", "w", stdout);

    int n, total;

    while( scanf("%d", &n) == 1 ){

        if(n==0)break;

        total = 0;
        while( n>=3 ){

            total += n/3;
            n = (n/3) + (n%3);
        }

        if(n==2)total++;

        printf("%d\n", total);
    }

    return 0;
}


