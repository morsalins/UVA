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
#define MAX 2000
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

VI G[MAX+5], T[MAX+5];
int visited[MAX+5];
stack <int> S;
int cnt;

void dfs(int u){

    visited[u] = true;

    for(int i=0; i<G[u].size(); i++){

        if( !visited[ G[u][i] ]){
            dfs( G[u][i] );
        }
    }
    S.push(u);

    return;
}

void dfs2(int u){

    visited[u] = true;

    for(int i=0; i<T[u].size(); i++){

        if( !visited[ T[u][i] ]){
            dfs2( T[u][i] );
        }
    }

    return;
}

int main()
{
    //READ("in.txt");

    int Case=1, n, m;
    int u, v, tp;
    //int tc; scanf("%d", &tc);

    while( scanf("%d%d", &n, &m) ){

        if( n==0 && m==0 ) return 0;

        while( m-- ){

            scanf("%d%d%d", &u, &v, &tp);

            if( tp==1 ){
                G[u].pb(v);
                T[v].pb(u);
            }

            else{
               G[u].pb(v);
               G[v].pb(u);
               T[v].pb(u);
               T[u].pb(v);
            }
        }

        SET(visited, false);

        for(int i=1; i<=n; i++){

            if( !visited[ i ] ){
                dfs( i );
            }
        }

        SET(visited, false);
        cnt = 0;


        while ( !S.empty() ){

            if( !visited[ S.top() ] ){

                cnt++;
                dfs2( S.top() );
            }
            S.pop();
        }

        if(cnt==1)printf("%d\n", cnt);
        else printf("0\n");

        for(int i=1; i<=n+2; i++){
            G[i].clear();
            T[i].clear();
        }
    }

    return 0;
}


