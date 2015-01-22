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
#define SIZE 100
#define MAX 100000
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

class E
{
public:
    int u, v, w;
    bool operator < (const E &O) const
    {
        return w < O.w;
    }
};

E e[MAX+7];
int par[SIZE+7], sz[SIZE+7];
int d[SIZE+7][SIZE+7], dist[SIZE+7];
bool visited[MAX+7];

int F (int r)
{
    if( par[r] == -1 ) return r;
    return par[r] = F( par[r] );
}

int main()
{
    //READ("in.txt");
    int Case=1, n, m, q;
    char dump[2];

    while( scanf("%d %d", &n, &m) )
    {
        if( n==0 && m==0 ) return 0;

        SET(par, -1);
        SET(sz, INF);
        SET(d, INF);
        VI G[SIZE+7];

        for(int edge=0; edge<m; edge++) scanf("%d %d %d", &e[edge].u, &e[edge].v, &e[edge].w);

        sort( e, e+m );

        int cnt=0;

        for(int i=m-1; i>=0; i--)
        {
            int pu = F( e[i].u );
            if( sz[pu] > 101 ) sz[pu] = 1;
            int pv = F( e[i].v );
            if( sz[pv] > 101 ) sz[pv] = 1;

            if( pu!=pv )
            {
                if( sz[pu] < sz[pv] ) swap(pu, pv);
                par[pv] = pu;
                sz[pu] += sz[pv];

                G[ e[i].u ].pb( e[i].v );
                G[ e[i].v ].pb( e[i].u );
                d[ e[i].u ][ e[i].v ] = e[i].w;
                d[ e[i].v ][ e[i].u ] = e[i].w;

                cnt++;
                if( cnt == n-1 ) break;
            }
        }
        //if( Case>1 ) puts("");
        printf("Scenario #%d\n", Case++);

        int src, dest, people;

        SET(dist, INF);
        SET(visited, false);

        scanf("%d %d %d", &src, &dest, &people);

        queue <int> Q;

        Q.push(src);
        visited[src] = 0;
        dist[src] = 0;
        bool Continue = true;

        while( !Q.empty() && Continue )
        {
            int u = Q.front();

            for(int i=0; i<G[u].size() && Continue; i++)
            {
                int v = G[u][i];

                if( !visited[v] )
                {
                    visited[v] = true;
                    if( u==src ) dist[v] = d[u][v];
                    else dist[v] = min( d[u][v], dist[u] );
                    Q.push(v);
                    if( v==dest ) Continue = false;
                }
            }
            Q.pop();
        }

        int tourist = dist[ dest ] - 1;
        int trip;

        if( people%tourist == 0 ) trip = people/tourist;
        else trip = people/tourist + 1;

        printf("Minimum Number of Trips = %d\n\n", trip);
    }

    return 0;
}

