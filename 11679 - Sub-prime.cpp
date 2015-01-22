#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
   int b, n, d, c, v, r[25];


   while( scanf("%d%d", &b, &n) == 2){

        if( b==0 && n==0 ) break;

        for(int i=1; i<=b; i++){
            scanf("%d", &r[i]);
        }

        d = 0; c = 0; v = 0;

        for(int i=1; i<=n; i++){
           scanf("%d%d%d", &d, &c, &v);
           r[d] -= v;
           r[c] += v;
        }

        bool flag = true;

        for(int i=1; i<=b; i++){
            if(r[i]<0) {
                flag = false;
                break;
            }
        }

        if(flag) printf("S\n");
        else printf("N\n");

   }

   return 0;
}
