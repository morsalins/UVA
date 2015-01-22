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
#define MAX 350
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

int dist[MAX+5];
int path[MAX+5];
queue <int> Q;

void findPath(int s, int d){

    if( path[d] != s ) findPath( s, path[d] );

    printf(" %d", d);
    return;
}

int main()
{
    //READ("in.txt");
    int Case=1, n, q;
    char dump[2], waste;
    string line;

    while( scanf("%d", &n)==1 ){

        gets(dump);

        VI G[MAX+5];
        int u, v, src, dest;

        for(int i=1; i<=n; i++){
            getline(cin, line);
            line += ',';

            stringstream SS(line);

            SS >> u;
            SS >> waste;

            while( SS >> v >> waste )
                G[u].pb(v);
        }

        printf("-----\n");

        scanf("%d", &q);
        for(int i=1; i<=q; i++){

            SET(dist, -1);

            scanf("%d %d", &src, &dest);

            Q.push(src);
            dist[src] = 0;
            path[src] = src;

            while( !Q.empty() ){
                int u = Q.front();
                for(int i=0; i<G[u].size(); i++){
                    int v = G[u][i];
                    if( v!=src && dist[v]==-1 ){
                        dist[v] = dist[u] + 1;
                        path[v] = u;
                        Q.push(v);
                    }
                }
                Q.pop();
            }

            if( dist[dest]==-1 ) printf("connection impossible\n");
            else{
                printf("%d", src);
                findPath(src, dest);
                puts("");
            }
        }
    }

    return 0;
}

