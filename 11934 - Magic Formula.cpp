#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int a, b, c, d, l, cnt;

    while( cin >> a >> b >> c >> d >>l ){

        if( a==0 && b==0 && c==0 && d==0 && l==0 )break;

        cnt = 0;
        for(int i=0; i<=l; i++){
            long int res = (a*i*i) + (b*i) + c;
            if(res%d==0)cnt++;
        }

        printf("%d\n", cnt);
    }

    return 0;
}
