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
#define ff first
#define ss second
#define SET(a, b) memset( a, b, sizeof (a) )
#define READ(f) freopen(f, "r", stdin);
#define WRITE(f) freopen(f, "w", stdout);

struct edge{
    int u, v, w;

    bool operator < (const struct edge &O) const{
        if( w == O.w ){
            if( u == O.u ) return v < O.v;
            return u < O.u;
        }
        return w < O.w;
    }
};

typedef struct edge E;

E e[MAX+7], ans[MAX+7];
int par[MAX+7], sz[MAX+7], counter = 0;

int F(int r){

    if( par[r] == r ) return r;
    return par[r] = F( par[r] );
}

void MST(int n, int idx){

    int cnt = 0;

    for(int i=0; i<idx; i++){

        int pu = F( e[i].u );
        int pv = F( e[i].v );

        if( pu!=pv ){

            if( sz[pu] < sz[pv] ) swap( pu, pv );
            par[pv] = pu;
            sz[pu] += sz[pv];

            ans[counter].u = e[i].u; ans[counter].v = e[i].v; ans[counter].w = e[i].w;
            counter++;

            cnt++;
            if( cnt == n-1 ) break;
        }
    }

    return;
}

int main()
{
    //READ("in.txt");
    int Case=1, n, cost;
    char dump[2], ch;

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d", &n);
        int idx = 0;
        counter = 0;

        for(int i=0; i<n; i++){
            par[i] = i;
            sz[i] = 1;
            for(int j=0; j<n-1; j++){
                scanf("%d%c", &cost, &ch);
                if(cost != 0 && j>i){
                    e[idx].u = i; e[idx].v = j; e[idx++].w = cost;
                }
            }
            scanf("%d", &cost);
            if(cost != 0){
                e[idx].u = i; e[idx].v = n-1; e[idx++].w = cost;
            }
        }

        sort( e, e+idx );

        MST(n, idx);

        printf("Case %d:\n", Case++);
        for(int i=0; i<counter; i++){
            printf("%c-%c %d\n", ans[i].u+65, ans[i].v+65, ans[i].w);
        }
    }

    return 0;
}

