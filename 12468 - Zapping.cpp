#include<cstdio>

using namespace std;

int main()
{
    int a, b, p;

    while( scanf("%d%d", &a, &b) == 2 ){

        if( a==-1 && b==-1) break;

        int up = a-b;

        if( up<0 ) up *= -1;

        int down = 100-up;

        up < down ? p = up : p = down;

        printf("%d\n", p);
    }

    return 0;
}
