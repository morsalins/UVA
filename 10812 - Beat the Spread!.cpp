#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    unsigned int s, d, tc;
    int r;

    scanf("%u", &tc);

    while( tc-- ){

        scanf("%u%u", &s, &d);

        if(s<d) printf("impossible\n");

        else{
            r = (s-d) / 2;

            if( s-r == d+r ) printf("%d %d\n", s-r, r);

            else  printf("impossible\n");
        }
    }

    return 0;
}
