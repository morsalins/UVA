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
#define MAX 1000000
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
    bool operator < (const struct Edge &obj) const {
        return w < obj.w;
    }
};

typedef struct Edge E;

vector <E> e;
int par[MAX+7];

int F(int r){

    if( r==par[r] ) return r;
    return par[r] = F( par[r] );
}

I64 MST(int n){

    sort( e.begin(), e.end() );

    int cnt=0, len = e.size();
    I64 total = 0;

    for(int i=0; i<len; i++){

        int u = F( e[i].u );
        int v = F( e[i].v );

        if( u!=v ){

            par[u] = v;
            total += e[i].w;
            cnt++;

            if( cnt==n-1 )break;
        }
    }

    return total;
}

int main()
{
    //READ("in.txt");

    int Case=1, n, k, m, u, v, w;
    E get;

    while( scanf("%d\n", &n)==1 ){

        I64 cost = 0;

        for(int i=1; i<n; i++){

            scanf("%d %d %d", &u, &v, &w);
            cost += w;
        }

        scanf("%d\n", &k);

        for(int i=0; i<k; i++){

            scanf("%d %d %d", &get.u, &get.v, &get.w);
            e.pb(get);
        }

        scanf("%d\n", &m);

        for(int i=0; i<m; i++){

            scanf("%d %d %d", &get.u, &get.v, &get.w);
            e.pb(get);
        }

        for(int i=0; i<=n+5; i++) par[i] = i;

        if( Case>1 )puts("");
        Case++;

        printf("%lld\n%lld\n", cost, MST(n));

        e.clear();
        //getchar();
    }

    return 0;
}

