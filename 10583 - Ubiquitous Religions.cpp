#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <functional>
#include <map>
#include <cstring>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
#include <cctype>
#include <math.h>
#include <cstdlib>

using namespace std;

#define I64 long long int
#define INF 0x7f7f7f7f
#define pii pair<int, int>
#define SIZE 1000
#define MAX 50000
#define VI vector <int>
#define VS vector <string>
#define MSI map <string, int>
#define MIS map <int, string>
#define MSS map <string, string>
#define pb push_back
#define pob pop_back
#define mp make_pair
#define IT iterator
#define SET(a, b) memset( a, b, sizeof (a) )
#define READ(f) freopen(f, "r", stdin);
#define WRITE(f) freopen(f, "w", stdout);

int par[MAX+5], sz[MAX+5];

int F (int r){
    if( r==par[r] ) return r;
    return par[r] = F( par[r] );
}

int main()
{
    int Case=1, n, m, u, v;

    while( scanf("%d %d", &n, &m) ){

        if( n==0 & m==0 ) return 0;

        for(int i=1; i<=n+5; i++){
            par[i] = i;
            sz[i] = 1;
        }

        int zeros = 0;

        while( m-- ){

            scanf("%d %d", &u, &v);

            int pu = F(u);
            int pv = F(v);

            if( pu!=pv ){

                if( sz[pu] < sz[pv] ) swap(pu, pv);
                par[pv] = pu;
                //sz[pu] += sz[pv];
                sz[pv] = 0;
                zeros++;
            }
        }

        printf("Case %d: %d\n", Case++, n-zeros);
    }

    return 0;
}

