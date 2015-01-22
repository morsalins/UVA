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
#include <ctime>

using namespace std;

#define I64 long long int
#define INF 0x7f7f7f7f
#define pii pair<int, int>
#define SIZE 1000
#define MAX 10000
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
    bool operator <(const struct Edges &O) const{
        return w < O.w;
    }
};
typedef struct Edges E;

vector <E> e;
int par[MAX+5];
int Zeros;

int F(int r){
    if( par[r]==r ) return r;
    return par[r] = F( par[r] );
}

I64 MST(int n){

    I64 total = 0;
    int cnt = 0;

    sort(e.begin(), e.end());

    for(int i=0; i<e.size(); i++){
        int u = F( e[i].u );
        int v = F( e[i].v );
        if( u!=v ){
            par[v] = u;
            Zeros++;
            total += e[i].w;
            cnt++;
            if(cnt==n-1) break;
        }
    }

    return total;
}


int main()
{
    //READ("in.txt");
    int Case=1, n, m, costs;
    E get;

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d %d %d", &n, &m, &costs);

        for(int i=1; i<=m; i++){

            scanf("%d %d %d", &get.u, &get.v, &get.w);
            if( get.w < costs )
                e.pb(get);
        }

        Zeros = 0;

        for(int i=0; i<n+5; i++) par[i] = i;

        I64 total = MST(n);

        int root = n-Zeros;

        printf("Case #%d: %lld %d\n", Case++, total+(root*costs), root);

        e.clear();
    }

    return 0;
}


