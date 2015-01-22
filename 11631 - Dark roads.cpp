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
#define MAX 200000
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

struct Edge{

    int u, v, w;

    bool operator < (const struct Edge &O ) const{

        return w < O.w;
    }
};

typedef struct Edge E;

vector <E> e;
int par[MAX+7];

int F( int r){

    if( par[r]==r ) return r;
    return par[r] = F( par[r] );
}

I64 MST(int n){

    I64 ttl = 0;
    int cnt = 0, len = e.size();

   for(int i=0; i<len; i++){

        int u = F( e[i].u );
        int v = F( e[i].v );

        if( u!=v ){
            par[u] = v;
            cnt++;
            ttl += e[i].w;
        }

        if( cnt==n-1) break;
    }

    return ttl;
}

int main()
{
    int Case=1;
    int n, m;
    E get;
    I64 total;
    //int tc; scanf("%d", &tc);

    while( scanf("%d%d", &n, &m) ){

        if( n==0 && m==0 ) return 0;

        total = 0;

        for(int i=1; i<=m; i++){

            scanf("%d %d %d", &get.u, &get.v, &get.w);
            total += get.w;
            e.pb(get);
        }

        sort( e.begin(), e.end() );

        for(int i=0; i<=n+5; i++) par[i] = i;

        printf("%lld\n", total-MST(n));

        e.clear();

    }

    return 0;
}

