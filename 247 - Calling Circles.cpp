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

map <string, VS> G, T;
map <string, bool> occur, visited;
map <int, VS> ans;
VS S;
stack <string> stk;
int cnt;

void dfs1(string u){

    visited[u] = true;
    //cout << u << " ";
    for(int i=0; i<G[u].size(); i++){

        if( !visited[ G[u][i] ] )
            dfs1( G[u][i] );
    }
    //cout << u << " ";
    stk.push(u);

    return;
}

void dfs2 (string u){

    visited[u] = true;
    //cout << u << " " << cnt << "\n";
    ans[cnt].push_back(u);

    for(int i=0; i<T[u].size(); i++){

        if( !visited[ T[u][i] ] )
            dfs2( T[u][i] );
    }

    return;
}

int main()
{
    //READ("in.txt");

    int Case=1, n, m;

    //int tc; scanf("%d", &tc);

    while( scanf("%d%d", &n, &m) ){

        if( n==0 && m==0 ) return 0;

        getchar();

        string s1, s2;

        while( m-- ){

            cin >> s1 >> s2;

            G[s1].pb(s2);
            T[s2].pb(s1);

            if( occur[s1] != true ) {
                S.pb(s1);
                occur[s1] = true;
            }
            if( occur[s2] != true ){
                S.pb(s2);
                occur[s2] = true;
            }
        }

        //for(int i=0; i<S.size(); i++) cout << S[i] << " ";

        for(int i=0; i<S.size(); i++){
            if( !visited[ S[i] ] )
                dfs1( S[i] );
        }

        visited.clear();
        cnt = 1;

        while( !stk.empty() ){

            string u = stk.top();
            stk.pop();

            if( !visited[u] ){
                dfs2(u);
                cnt++;
            }

        }

        //cout << cnt;
        //for(int i=0; i<ans[1].size(); i++) cout << ans[1][i];

        if( Case!=1 )puts("");
        printf("Calling circles for data set %d:\n", Case++);
        for(int i=1; i<cnt; i++){

            for(int j=0; j<ans[i].size(); j++){
                cout << ans[i][j];
                if(j<ans[i].size()-1)printf(", ");
            }
            printf("\n");
        }

        G.clear();
        T.clear();
        ans.clear();
        occur.clear();
        visited.clear();
        S.clear();
    }

    return 0;
}

