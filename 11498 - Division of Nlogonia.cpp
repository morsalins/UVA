#include<cstdio>

using namespace std;

int main()
{
    int k, n, m, x, y;

    while( scanf("%d", &k) ){

        if(k == 0) break;

        scanf("%d%d", &n, &m);

        for(int i=1; i<=k; i++){
            scanf("%d%d", &x, &y);

            if( x==n || y==m ) printf("divisa\n");

            else if( x>n ){

                if( y>m ) printf("NE\n");

                else if( y<m ) printf("SE\n");
            }

             else if( x<n ){

                if( y>m ) printf("NO\n");

                else if( y<m ) printf("SO\n");
            }
        }
    }

    return 0;
}
