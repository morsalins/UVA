#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    double p, n, k;

    while( scanf("%lf%lf", &n ,&p) == 2 ) {

        k = pow(p, (1/n) );

        printf("%.0lf\n", k);
    }

    return 0;
}
