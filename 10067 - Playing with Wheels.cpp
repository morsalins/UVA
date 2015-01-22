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
#define MAX 10000
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

#define piii pair <int, pii>
#define piiii pair <int, piii>

bool restrict[MAX+5];;
int dist[MAX+5];

int main()
{
    //READ("in.txt");
    int Case=1, n;
    char dump[2];
    int src[10], dest[10], forbid[10];

    int tc; scanf("%d", &tc);

    while( tc-- ){

        SET(restrict, false);
        SET(dist, -1);

        queue <piiii> Q;
        int idx;

        scanf("%d %d %d %d", &src[0], &src[1], &src[2], &src[3]);
        scanf("%d %d %d %d", &dest[0], &dest[1], &dest[2], &dest[3]);

        scanf("%d", &n);

        for(int i=0; i<n; i++){
            scanf("%d %d %d %d", &forbid[0], &forbid[1], &forbid[2], &forbid[3]);
            idx = (forbid[0]*1000) + (forbid[1]*100) + (forbid[2]*10) + (forbid[3]);
            restrict[idx] = true;
        }

        int idx_src = (src[0]*1000) + (src[1]*100) + (src[2]*10) + (src[3]);
        int idx_dest = (dest[0]*1000) + (dest[1]*100) + (dest[2]*10) + (dest[3]);

        piiii temp_src = piiii( src[0], piii( src[1], pii( src[2], src[3] ) ) );
        Q.push( temp_src );
        dist[idx_src] = 0;
        bool Continue = true;

        while( !Q.empty() && Continue ){

            int u[5];
            u[0] = Q.front().ff; u[1] = Q.front().ss.ff; u[2] = Q.front().ss.ss.ff; u[3] = Q.front().ss.ss.ss;
            int idx_u = (u[0]*1000) + (u[1]*100) + (u[2]*10) + (u[3]);
            int v[5];

            for(int i=0; i<4 && Continue; i++){

                v[0] = u[0]; v[1] = u[1]; v[2] = u[2]; v[3] = u[3];
                if ( v[i] == 9 ) v[i] = 0;
                else v[i] = u[i] + 1;
                idx = (v[0]*1000) + (v[1]*100) + (v[2]*10) + (v[3]);

                if( restrict[idx]==false && dist[idx]==-1 ){
                    dist[idx] = dist[idx_u] + 1;
                    Q.push( piiii( v[0], piii( v[1], pii( v[2], v[3] ) ) ) );
                    if( idx == idx_dest ) Continue = false;
                }
            }

             for(int i=0; i<4 && Continue; i++){

                v[0] = u[0]; v[1] = u[1]; v[2] = u[2]; v[3] = u[3];
                if ( v[i] == 0 ) v[i] = 9;
                else v[i] = u[i] - 1;
                idx = (v[0]*1000) + (v[1]*100) + (v[2]*10) + (v[3]);

                if( restrict[idx]==false && dist[idx]==-1 ){
                    dist[idx] = dist[idx_u] + 1;
                    Q.push( piiii( v[0], piii( v[1], pii( v[2], v[3] ) ) ) );
                    if( idx == idx_dest ) Continue = false;
                }
            }
            Q.pop();
        }

        if( dist[idx_dest] == -1 ) printf("-1\n");
        else printf("%d\n", dist[idx_dest] );
    }

    return 0;
}

