#include<cstdio>

using namespace std;

int main()
{
    int n, k, total;

    while( scanf("%d%d", &n, &k) == 2 ){

        total = n;
        while( n>=k ){

            total += n/k;
            n = (n/k) + (n%k);
        }

        printf("%d\n", total);
    }

    return 0;
}
