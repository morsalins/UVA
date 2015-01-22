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

VS str;
map <string, VS> G, T;
map <string, bool> visited;
stack <string> S;
int cnt;

void dfs(string u){

    visited[u] = true;

    for(int i=0; i<G[u].size(); i++){

        if( !visited[ G[u][i] ]){
            dfs( G[u][i] );
        }
    }
    S.push(u);

    return;
}

void dfs2(string u){

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
    string s1, s2;
    //int tc; scanf("%d", &tc);

    while( scanf("%d%d", &n, &m) ){

        if( n==0 && m==0 ) return 0;

        getchar();

        for(int i=1; i<=n; i++){

            getline(cin, s1);

            str.pb(s1);
        }

        while( m-- ){

            getline(cin, s1);
            getline(cin, s2);

            G[s1].pb(s2);
            T[s2].pb(s1);
        }

        visited.clear();

        for(int i=0; i<str.size(); i++){

            if( !visited[ str[i] ] ){
                dfs( str[i] );
            }
        }

        visited.clear();
        cnt = 0;


        while ( !S.empty() ){

            if( !visited[ S.top() ] ){

                cnt++;
                dfs2( S.top() );
            }
            S.pop();
        }

        printf("%d\n", cnt);

        G.clear();
        T.clear();
        str.clear();

    }

    return 0;
}

