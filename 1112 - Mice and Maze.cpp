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
#define INF 126
#define pii pair<int, int>
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

vector <pii> G[MAX+5];
I64 dist[MAX+5];

void dijkstra(int src){

    priority_queue < pii, vector <pii>, greater<pii> > PQ;

    dist[src] = 0;
    PQ.push( pii(dist[src], src) );

    while( !PQ.empty() ){

        int u = PQ.top().second;

        for(int i=0; i<G[u].size(); i++){
            int v = G[u][i].first;
            int w = G[u][i].second;

            if( dist[v] > dist[u]+w ){
                dist[v] = dist[u]+w;
                PQ.push( pii(dist[v], v) );
            }
        }

        PQ.pop();
    }
}

int main()
{
    //READ("in.txt");

    int tc, Case=1, nodes, M, E, T, u, v, w;
    char s[2];

    scanf("%d", &tc);

    while( tc-- ){

        gets(s);

        scanf("%d%d%d%d", &nodes, &E, &T, &M);

        for(int i=1; i<=M; i++){

            scanf("%d%d%d", &u, &v, &w);
            G[u].pb( pii(v, w) );
        }

        int cnt = 0;

        for(int i=1; i<=nodes; i++){

            SET( dist, INF);

            if( i!=E )dijkstra(i);

            if( dist[E]<=T || i==E ) cnt++;
        }

        printf("%d\n", cnt);

        if(tc>0) puts("");

        for(int i=0; i<=MAX; i++) G[i].clear();
    }

    return 0;
}
