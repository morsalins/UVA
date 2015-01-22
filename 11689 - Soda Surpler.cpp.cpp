#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int tc, e, f, c, cnt;

    scanf("%d", &tc);

    while( tc-- ){

       scanf("%d%d%d", &e, &f, &c);
       cnt = 0;
       int total = e+f;

       while( total>=c ){
            cnt += total/c;
            total = (total/c) + (total%c);
       }

        printf("%d\n", cnt);
    }
    return 0;
}
