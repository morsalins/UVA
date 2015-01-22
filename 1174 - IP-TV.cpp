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
#define MAX 2000
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

class Edges{
public:
    string u, v;
    int w;
    bool operator < (const class Edges &O ) const{
        return w < O.w;
    }
};
typedef class Edges E;

vector <E> e;
map <string, string> par;

string F( string r ){

    if( par[r]==r ) return r;
    return par[r] = F( par[r] );
}

I64 MST(int n){

    I64 total = 0;
    int cnt = 0;

    sort(e.begin(), e.end());

    for(int i=0; i<e.size(); i++){
        string u = F( e[i].u );
        string v = F( e[i].v );

        if( u!=v ){
            par[u] = v;
            cnt++;
            total += e[i].w;
            if(cnt==n-1) break;
        }
    }

    return total;
}

int main()
{
    int Case=1, n, m;
    E get;

    int tc; scanf("%d", &tc);

    while( tc-- ){

        char dump[2];
        VS V;
        map <string, bool> occur;

        scanf("%d%d", &n, &m);
        gets(dump);

        for(int i=1; i<=m; i++){

            cin >> get.u >> get.v >> get.w;
            e.pb(get);

            if( !occur[ get.u ] ){
                V.pb(get.u);
                occur[ get.u ] = true;
            }
            if( !occur[ get.v ] ){
                V.pb(get.v);
                occur[ get.v ] = true;
            }
        }

        for(int i=0; i<V.size(); i++){
            par[ V[i] ] = V[i];
        }

        printf("%lld\n", MST( V.size() ) );
        if( tc>0 )puts("");

        e.clear();
    }

    return 0;
}

