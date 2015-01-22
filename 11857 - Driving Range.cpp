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

struct Edges{

    int u, v, w;
    bool operator < (const struct Edges &O )const{
        return w < O.w;
    }
};

typedef struct Edges E;

vector <E> e;
int par[MAX+7], Size[MAX+7];
int max_ancs;

int F(int r){
    if( r == par[r] )
        return r;
    return par[r] = F( par[r] );
}

int MST(int n){

    sort( e.begin(), e.end() );

    int ans=0, cnt=0;

    for(int i=0; i<e.size(); i++){

        int u = F( e[i].u );
        int v = F( e[i].v );

        if( u!=v ){

            if( Size[u] < Size[v] ) swap( u, v );
            par[v] = u;
            Size[u] += Size[v];
            //cout << Size[u] << endl;
            max_ancs = max( max_ancs, Size[u] );
            ans = max( ans, e[i].w );

            cnt++;
            if( cnt==n-1 ) break;
        }
    }

    return ans;
}

int main()
{
    //READ("in.txt");
    int Case=1, n, m;
    E get;

    //int tc; scanf("%d", &tc);

    while( scanf("%d %d", &n, &m) ){

        if( n==0 & m==0 ) return 0;

        for(int i=1; i<=m; i++){

            scanf("%d %d %d", &get.u, &get.v, &get.w);
            e.pb(get);
        }

        for(int i=0; i<=n+5; i++){
            par[i] = i;
            Size[i] = 1;
        }
        max_ancs = 0;
        int ans = MST(n);

        if( m==0 || max_ancs<n )printf("IMPOSSIBLE\n");
        else printf("%d\n",ans);

        e.clear();

    }

    return 0;
}

