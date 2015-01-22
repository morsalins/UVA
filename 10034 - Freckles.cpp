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
#include <cmath>
#include <cstdlib>

using namespace std;

#define I64 long long int
#define INF 0x7f7f7f7f
#define pii pair<int, int>
#define pdd pair <double, double>
#define SIZE 1000
#define MAX 200
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

    int u, v;
    double w;

    bool operator < (const struct Edges &obj) const{
        return w < obj.w;
    }
};

typedef struct Edges E;

vector < pdd > C;
vector < E > edge;
int par[MAX+7];

int F( int r ){

    if( par[r] == r ) return r;

    return par[r] = F( par[r] );
}

double MST(int n){

    double total = 0.0;
    int cnt = 0;

    for(int i=0; i<edge.size(); i++){

        int u = F(edge[i].u);
        int v = F(edge[i].v);

        if( u!=v ){

            par[u] = v;
            total += edge[i].w;
            cnt++;

            //if(cnt==n-1) break;
        }
    }

    return total;
}

int main()
{
    //READ("in.txt");

    int Case=1;

    int tc; scanf("%d", &tc);

    E get;

    while( tc-- ){

        int m; scanf("%d", &m);
        int loop = m;

        while( loop-- ){

            double a, b;
            scanf("%lf %lf", &a, &b);
            C.push_back( pdd(a,b) );
        }

        for(int i=0; i<C.size()-1; i++){
            for(int j=i+1; j<C.size(); j++){
                pdd p = C[i];
                pdd q = C[j];
                double dist = sqrt( ( (q.first-p.first)*(q.first-p.first) ) + ( (q.second-p.second)*(q.second-p.second) ) );
                get.u = i; get.v = j; get.w = dist;
                edge.pb(get);
            }

        }

        for(int i=0; i<=m+5; i++) par[i] = i;

        sort( edge.begin(), edge.end() );

        printf("%0.2lf\n", MST(m) );
        if( tc>0 )
            puts("");

        C.clear();
        edge.clear();
    }

    return 0;
}
