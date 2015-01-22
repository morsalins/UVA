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

#define INF 0x7f7f7f7f
#define I64 long long int
#define pii pair<int, int>
#define SIZE 1000
#define MAX 20000
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

vector <pii> G[MAX+5];
I64 dist[MAX+5];
bool change;

void dijkstra(int src, int dest){

    priority_queue < pair<I64, int>, vector < pair <I64, int> >, greater< pair <I64, int> > > PQ;

	change = false;

    PQ.push( pii(0, src) );
    dist[src] = 0;

    while( !PQ.empty() ){

        int u = PQ.top().second;
        int w = PQ.top().first;
        PQ.pop();

        for(int i=0; i<G[u].size(); i++){

            int v = G[u][i].first;
            w = G[u][i].second;

            if( dist[v] > dist[u]+w ){
                if( v==dest ) change = true;
                dist[v] = dist[u]+w;
                PQ.push( pii(dist[v], v) );
            }
        }
    }

    return;
}

int main()
{
	//READ("in.txt");

	int tc, Case=1;
    int nodes, edges, src, dest, u, v, w;

    scanf("%d", &tc);

    while( tc-- ){

        scanf("%d%d%d%d", &nodes, &edges, &src, &dest);

        for(int i=1; i<=edges; i++){

            scanf("%d%d%d", &u, &v, &w);

            G[u].pb( pii(v, w) );
            G[v].pb( pii(u, w) );
        }

        SET(dist, INF);

        dijkstra(src, dest);

        printf("Case #%d: ", Case++);
        if( change ) printf("%lld", dist[dest]);
        else  printf("unreachable");

        puts("");

        for(int i=0; i<MAX+5; i++){
            G[i].clear();
        }
    }

    return 0;
}

