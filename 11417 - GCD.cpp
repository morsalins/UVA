#include<cstdio>

using namespace std;

int GCD( int i, int j){

    if(i==0)
        return j;

    else
        return GCD( j%i, i);
}

int main()
{
    int n;
    long long int g;

    while( scanf("%d", &n) == 1){

        if( n==0 ) break;

        g = 0;

        for(int i=1; i<n; i++){
            for(int j=i+1; j<=n; j++){
                g += GCD(i, j);
            }
        }

        printf("%lld\n", g);
    }

    return 0;
}
