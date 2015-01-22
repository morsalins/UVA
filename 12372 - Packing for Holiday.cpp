#include<cstdio>

using namespace std;

int main()
{
    int t, l, w, h;

    scanf("%d", &t);

    for(int kase=1; kase<=t; kase++){

        scanf("%d%d%d", &l, &w, &h);

        if( l<=20 && w<=20 && h<=20 ) printf("Case %d: good\n", kase);

        else printf("Case %d: bad\n", kase);
    }

    return 0;
}
