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
#define MAX 1000000
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

int in[MAX+5];
queue <int> Q;

VI toposort(map <int, VI> G){

    VI ans;

    while( !Q.empty() ){

        int u = Q.front();
        Q.pop();

        ans.push_back(u);

        for(int i=0; i<G[u].size(); i++){

            int v = G[u][i];
            in[v]--;

            if( in[v]==0 ) Q.push(v);
        }
    }

    return ans;
}

int main()
{
    int tc, Case=1, n, m, u, v;

    while( scanf("%d%d", &n, &m) ){

        if( n==0 && m==0 ) return 0;

        map <int, VI> G;
        SET(in, 0);

        for(int i=1; i<=m; i++){

            scanf("%d%d", &u, &v);

            G[u].pb(v);
            in[v]++;
        }

        for(int i=1; i<=n; i++)
            if( in[i]==0 )
                Q.push(i);

        VI ans = toposort( G );

        if( ans.size()==n )
            for(int i=0; i<ans.size(); i++)
                printf("%d\n", ans[i]);
        else
            printf("IMPOSSIBLE\n");

    }

    return 0;
}

