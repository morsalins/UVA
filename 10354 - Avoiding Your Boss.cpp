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
#define pci pair<char, int>
#define pic pair<int, char>
#define SIZE 1000
#define MAX 110
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

I64 db[MAX+5][MAX+5], dm[MAX+5][MAX+5];

int main()
{
    //READ("in.txt");

    int Case=1, n, p, r, bh, of, yh, m, u, v, w, srcS, srcM, type, dir;

    while(  scanf("%d %d %d %d %d %d", &n, &r, &bh, &of, &yh, &m)==6 ){

        SET(dm, INF);
        SET(db, INF);

        for(int i=1; i<=n; i++){
            db[i][i] = dm[i][i] = 0;
        }

        for(int i=1; i<=r; i++){

            scanf("%d %d %d", &u, &v, &w);
            dm[u][v] = dm[v][u] = db[u][v] = db[v][u] = w;
        }

        if( yh==bh || yh==of || m==bh || m==of ){
            printf("MISSION IMPOSSIBLE.\n");
            continue;
        }

        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if( i!=j && db[i][k]<INF && db[k][j]<INF ){
                        db[i][j] = min( db[i][j], db[i][k]+db[k][j] );
                    }
                }
            }
        }

        for(int i=1; i<=n; i++){
            if( db[bh][of] == db[bh][i]+db[i][of] ){
                for(int j=1; j<=n; j++){
                    dm[i][j] = INF;
                    dm[j][i] = INF;
                }
            }
        }

        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if( i!=j && dm[i][k]<INF && dm[k][j]<INF ){
                        dm[i][j] = min( dm[i][j], dm[i][k]+dm[k][j] );
                    }
                }
            }
        }

        if( ( dm[yh][m]<INF) ) printf("%lld\n", dm[yh][m]);
        else printf("MISSION IMPOSSIBLE.\n");

    }

    return 0;
}



