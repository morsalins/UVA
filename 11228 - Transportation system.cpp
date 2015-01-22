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
#define ff first
#define ss second
#define SET(a, b) memset( a, b, sizeof (a) )
#define READ(f) freopen(f, "r", stdin);
#define WRITE(f) freopen(f, "w", stdout);

struct Edge{
    int u, v;
    double w;
    bool operator < (const struct Edge &O) const{
        return w < O.w;
    }
};

typedef struct Edge E;

E e[MAX+7];
int par[SIZE+7], sz[SIZE+7];
int Index = 0;
int state, r;
double raillen;

int F (int r){
    if(par[r]==r) return r;
    return par[r] = F( par[r] );
}

double MST (int n){

    double total = 0.0;
    int cnt = 0;
    state = 1;
    raillen = 0.0;

    for(int i=0; i<Index; i++){

        int pu = F( e[i].u );
        int pv = F( e[i].v );

        if( pu!=pv ){

            if( sz[pu] < sz[pv] ) swap( pu, pv );
            par[pv] = pu;
            sz[pu] += sz[pv];

            total += e[i].w;

            if( e[i].w > r ){
                raillen += e[i].w;
                state++;
            }

            cnt++; if( cnt==n-1 ) break;
        }
    }

    return total;
}

int main()
{
    //READ("in.txt");
    int Case=1, n, x, y;
    pii nodes[SIZE+7];
    char dump[2];

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d %d", &n, &r);

        int idx = 0;
        Index = 0;

        for(int node=0; node<n; node++){

            par[node] = node; sz[node] = 1;

            scanf("%d %d", &x, &y);

            for(int i=0; i<idx; i++){
                double cost = hypot( nodes[i].ff-x, nodes[i].ss-y );
                e[Index].u = i; e[Index].v = idx; e[Index].w = cost;
                Index++;
            }
            nodes[idx].ff = x; nodes[idx].ss = y;
            idx++;
        }

        sort( e, e+Index );

        double roadLen = MST(n) - raillen;

        int rail, road;

        if( raillen-floor(raillen) >= ceil(raillen)-raillen ) rail = ceil(raillen);
        else rail = floor(raillen);

        if( roadLen-floor(roadLen) >= ceil(roadLen)-roadLen ) road = ceil(roadLen);
        else road = floor(roadLen);

        printf("Case #%d: %d %d %d\n", Case++, state, road, rail);
    }

    return 0;
}

