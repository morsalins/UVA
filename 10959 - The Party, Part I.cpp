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
#define MAX 1000
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

int dist[MAX+5];
bool visited[MAX+5];

int main()
{
    //READ("in.txt");

    int Case=1, n, m, u, v;

    int tc; scanf("%d", &tc);

    while( tc-- ){

        VI G[MAX+5];

        scanf("%d %d", &n, &m);

        for(int i=1; i<=m; i++){
            scanf("%d %d", &u, &v);
            G[u].pb(v);
            G[v].pb(u);
        }

        queue <int> Q;
        SET(dist, 0);
        SET(visited, false);

        Q.push(0);
        dist[0] = 0;
        visited[0] = true;

        while( !Q.empty() ){
            u = Q.front();
            for(int i=0; i<G[u].size(); i++){
                v = G[u][i];
                if( !visited[v] ){
                    visited[v] = true;
                    dist[v] = dist[u] + 1;
                    Q.push(v);
                }
            }
            Q.pop();
        }

        for(int i=1; i<n; i++){
            printf("%d\n", dist[i]);
        }

        if( tc>0 ) printf("\n");
    }

    return 0;
}

