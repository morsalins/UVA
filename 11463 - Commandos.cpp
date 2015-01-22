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
#define MAX 100
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

int d[MAX+5][MAX+5];

int main()
{
    //READ("in.txt");

    int Case=1, n, m, u, v;

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d %d", &n, &m);
        SET(d, INF);

        while( m-- ){

            scanf("%d %d", &u, &v);
            d[u][v] = 1;
            d[v][u] = 1;
        }

        int src, dest;
        scanf("%d %d", &src, &dest);

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if( i!=j && d[i][k]<INF && d[k][j]<INF)
                        d[i][j] = min( d[i][j], d[i][k]+d[k][j] );
                }
            }
        }

        int shortestPath = 0;
        for(int i=0; i<n; i++) d[i][i] = 0;

        for(int i=0; i<n; i++){
            if( d[src][i]<INF && d[i][dest]<INF )
                shortestPath = max( shortestPath, d[src][i]+d[i][dest] );
        }

        printf("Case %d: %d\n", Case++, shortestPath);
    }

    return 0;
}


