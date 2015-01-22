#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
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

VI graph[MAX+5];
int in[MAX+5];
queue <int> Q;

VI f(int n){

    VI otpt;

    while( !Q.empty() ){

        int u = Q.front();
        otpt.pb(u);

        for(int i=0; i<graph[u].size(); i++){
            int v = graph[u][i];
            in[v]--;

            if( in[v]==0 )Q.push(v);
        }

        Q.pop();
    }

    return otpt;
}

int main()
{
    int tc, Case=1, n, m, u, v;

    while( scanf("%d%d", &n, &m) ==2 ){

        if( n==0 && m==0 ) return 0;

        SET(in, 0);

        for(int i=1; i<=m; i++){

            scanf("%d%d", &u, &v);
            in[v]++;
            graph[u].pb(v);
        }

        for(int i=1; i<=n; i++)
            if( in[i]==0 ) Q.push(i);

        VI otpt = f(n);

        for(int i=0; i<otpt.size(); i++){

            cout << otpt[i];
            if( i<(otpt.size()-1) ) printf(" ");
        }

        printf("\n");

        for(int i=0; i<=n; i++)
            graph[i].clear();
    }

    return 0;
}
