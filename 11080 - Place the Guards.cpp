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
#define ff first
#define ss second
#define SET(a, b) memset( a, b, sizeof (a) )
#define READ(f) freopen(f, "r", stdin);
#define WRITE(f) freopen(f, "w", stdout);

int color[MAX+7];
const int RED = 1;
const int BLUE = 2;

int main()
{
    //READ("in.txt");
    int Case=1, n, m, u, v;
    char dump[2];

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d %d", &n, &m);

        VI G[MAX+7];
        SET( color, 0 );

        for(int i=1; i<=m; i++){
            scanf("%d %d", &u, &v);
            G[u].pb(v); G[v].pb(u);
        }

        bool Continue = true;
        int ans = 0;

        for(int node=0; node<n && Continue; node++){

            int blue = 0, red = 0;

            if( !color[node] ){

                queue <int> Q;
                Q.push(node);
                color[node] = RED;
                red++;

                while( !Q.empty() && Continue ){

                    int u = Q.front();
                    for(int i=0; i<G[u].size() && Continue; i++){

                        int v = G[u][i];

                        if( color[u] == color[v] ) Continue = false;

                        if( !color[v] ){

                            if( color[u] == RED ){
                                color[v] = BLUE;
                                blue++;
                            }
                            else{
                                color[v] = RED;
                                red++;
                            }

                            Q.push(v);
                        }
                    }
                    Q.pop();
                }
            }
            if( blue == 0 ) ans += red;
            else ans += min( red, blue );
        }

        if( !Continue ) printf("-1\n");
        else printf("%d\n", ans);
    }

    return 0;
}

