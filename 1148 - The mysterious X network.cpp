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

queue <int> Q;
bool visited[MAX+5];
int dist[MAX+5];

int main()
{
    //READ("in.txt");
    int Case=1, n, e, u, v;
    char dump[2];

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d", &n);

        VI G[MAX+5];

        for(int i=1; i<=n; i++){

            scanf("%d %d", &u, &e);
            while( e-- ){
                scanf("%d", &v);
                G[u].pb(v);
            }
        }

        int c1, c2; scanf("%d %d", &c1, &c2);

        SET(visited, false);
        SET(dist, -1);

        Q.push(c1);
        visited[c1] = true;
        dist[c1] = 0;

        while( !Q.empty() ){
            int u = Q.front();
            for(int i=0; i<G[u].size(); i++){
                int v = G[u][i];
                if( !visited[v] ){
                    visited[v] = true;
                    dist[v] = dist[u] + 1;
                    Q.push(v);
                }
            }
            Q.pop();
        }

        printf("%d %d %d\n", c1, c2, dist[c2]-1);
        if(tc) puts("");
    }

    return 0;
}

