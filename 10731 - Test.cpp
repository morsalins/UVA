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

map < char, vector <char> > G, T, ans;
map <char, bool> occur;
vector < char > V[MAX+5];
int visited[MAX+5];
stack <char> S;
int cnt;

void dfs(char u){

    visited[ u-65 ] = true;

    for(int i=0; i<G[u].size(); i++){

        char v = G[u][i];
        if( !visited[  v-65 ] ){
            dfs(v);
        }
    }

    S.push(u);
    return;
}

void dfs2(char u){

    visited[ u-65 ] = true;
    V[cnt].pb( u );

    for(int i=0; i<T[u].size(); i++){

        char v = T[u][i];
        if( !visited[  v-65 ] ){
            dfs2(v);
        }
    }

    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=0, n;
    char s[15];

    while( scanf("%d", &n) ){

        if( n==0 ) return 0;

        gets( s );

        while( n-- ){

            gets(s);

            char u = s[10];
			occur[ s[10] ] = true;

            if( u != s[0] ){
                G[u].pb( s[0] );
                T[s[0]].pb(u);
                if( !occur[s[0]] ) occur[s[0]] = true;
            }
            if( u != s[2] ){
                G[u].pb( s[2] );
                T[s[2]].pb(u);
                if( !occur[s[2]] ) occur[s[2]] = true;
            }
            if( u != s[4] ){
                G[u].pb( s[4] );
                T[s[4]].pb(u);
                if( !occur[s[4]] ) occur[s[4]] = true;
            }
            if( u != s[6] ){
                G[u].pb( s[6] );
                T[s[6]].pb(u);
                if( !occur[s[6]] ) occur[s[6]] = true;
            }
            if( u != s[8] ){
                G[u].pb( s[8] );
                T[s[8]].pb(u);
                if( !occur[s[8]] ) occur[s[8]] = true;
            }
        }

        SET(visited, false);

        for(map<char, bool> :: IT it=occur.begin(); it!=occur.end(); it++){

            char u = it->first;
            if( !visited[ u-65 ] ){
                dfs(u);
            }
        }

        SET(visited, false);
        cnt = 0;

        while( !S.empty() ){

            if( !visited[ S.top()-65 ] ){
                cnt++;
                dfs2(S.top());

                sort( V[cnt].begin(), V[cnt].end() );
                ans[ V[cnt][0] ] = V[cnt];
            }

            S.pop();
        }

        if( ++Case>1 ){
            printf("\n");
        }

        for(map < char, vector <char> > :: IT it=ans.begin(); it!=ans.end(); it++){

            for(int i=0; i<ans[it->first].size(); i++){

                cout << ans[it->first][i];

                if( i<ans[it->first].size()-1 ) printf(" ");
            }

            printf("\n");
        }

        G.clear();T.clear();ans.clear();occur.clear();
        for(int i=0; i<=30; i++) V[i].clear();
    }

    return 0;
}

