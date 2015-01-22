#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include <sstream>
#include<set>
#include<stack>
#include<queue>
#include<cctype>
#include<math.h>
#include<cstdlib>

#define I64 long long int
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

using namespace std;

map <long long int, vector< long long int> > graph;
map <long long int, bool> visited;
map<long long int, int> dist;
long int notReachable;

void BFS(int source, int ttl){

    queue <long long int> Q;
    notReachable = 0;

    Q.push(source);
    visited[source] = true;
    dist[source] = 0;

    while( !Q.empty() ){

        long long int u = Q.front();
        //vector <long long int> temp = graph[u];
        int len = graph[u].size();

        for(int i=0; i<len; i++){

            long long int v = graph[u][i];

            if( !visited[v] ){

                visited[v] = true;
                dist[v] = dist[u] + 1;

                if( dist[v]>ttl)
                    notReachable++;

                Q.push(v);
            }
        }

        Q.pop();
    }

    return;
}

int main()
{
    //READ("in.txt");

    int nodes, Case=1;

    while( scanf("%d", &nodes) == 1 ){

        if( nodes==0 ) return 0;

        for(int i=1; i<=nodes; i++){

            int u, v;
            scanf("%d %d", &u, &v);

            graph[u].pb( v );
            graph[v].pb( u );
        }

        long long int source, ttl;
        while( scanf("%lld %lld", &source, &ttl)==2 ){

            if( source==0 && ttl==0 ) break;

            BFS( source, ttl );

            notReachable += graph.size() - visited.size();

            printf("Case %d: %ld nodes not reachable from node %lld with TTL = %lld.\n", Case++, notReachable, source, ttl);

            visited.clear();
            dist.clear();
        }
        graph.clear();
    }

    return 0;
}

