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
#define MAX 100
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

int d[MAX+5];
int path[MAX+5];

void findPath(int src, int d){

    if( path[d]!=src ) findPath( src, path[d]);

    printf(" %d", d);

    return;
}

int main()
{
    //READ("in.txt");

    int Case=1, u, v, w, n, src, tar;


    while( scanf("%d", &n) )
    {
        if( n==0 ) return 0;

        vector <pii> G[MAX+5];
        SET(d, INF);
        SET(path, -1);

        for(int i=1; i<=n; i++){
            int e; scanf("%d", &e);
            while( e-- ){
                scanf("%d %d", &v, &w);
                G[i].pb( pii(v, w) );
            }
        }
        scanf("%d %d", &src, &tar);

        priority_queue< pii, vector<pii>, greater<pii> > PQ;

        PQ.push( pii(0, src) );
        d[src] = 0;

        while( !PQ.empty() ){

            int u = PQ.top().second;
            for(int i=0; i<G[u].size(); i++){
                int v = G[u][i].first;
                int w = G[u][i].second;

                if( d[v] > d[u]+w ){
                    d[v] = d[u]+w;
                    path[v] = u;
                    PQ.push( pii(d[v], v) );
                }
            }
            PQ.pop();
        }

        printf("Case %d: Path = %d", Case++, src);
        findPath( src, tar );
        printf("; %d second delay\n", d[tar]);
    }

    return 0;
}
