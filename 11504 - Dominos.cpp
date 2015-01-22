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
#define MAX  100000
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

VI G[MAX+5];
bool visited[MAX+5];
int cnt;
stack <int> S;

void dfs(int u){

    visited[u] = true;

    for(int i=0; i<G[u].size(); i++){
        if( !visited[ G[u][i] ] )
            dfs( G[u][i] );
    }

    S.push(u);

    return;
}

void dfs1(int u){

    visited[u] = true;

    for(int i=0; i<G[u].size(); i++){
        if( !visited[ G[u][i] ] )
            dfs1( G[u][i] );
    }

    return;
}

int main()
{
    //READ("in.txt");

    int Case=1, n, m, u, v;

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d%d", &n, &m);

        while( m-- ){

            scanf("%d%d", &u, &v);

            G[u].pb(v);
        }

        SET(visited, false);

        for(int i=1; i<=n; i++){
            if( !visited[i] ){
                dfs(i);
            }
        }

        cnt = 0;
        SET(visited, false);

        while( !S.empty() ){

            int u = S.top();
            S.pop();

            if( !visited[u] ){
                cnt++;
                dfs1(u);
            }
        }

        printf("%d\n", cnt);

        for(int i=0; i<=n; i++)G[i].clear();
        //components.clear();
    }

    return 0;
}

