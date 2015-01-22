#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int r, n, kase=1;

    while( cin >> r >> n){
        if(r==0 && n==0)break;

        if( n*26 >= r-n){

            if( r==n || r<n ) printf("Case %d: 0\n", kase);

            else if( (r-n) <= n ) printf("Case %d: 1\n", kase);

            else{
                int i;
                for(i=2; (n*i)<(r-n); i++);

                if(n*(i-1)==(n-r))printf("Case %d: %d\n", kase, i-1);
                else printf("Case %d: %d\n", kase, i);
            }
        }

        else printf("Case %d: impossible\n", kase);

        kase++;
    }

    return 0;
}
