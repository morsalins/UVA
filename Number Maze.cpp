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
#define plli pair<long long, int>
#define pllpii pair<long long, pair<int, int> >
#define SIZE 1000
#define MAX 1000
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

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
int R, C;
int G[MAX+5][MAX+5];
I64 dist[MAX+5][MAX+5];

void dijkstra(pii u){

    priority_queue < pllpii, vector< pllpii >, greater< pllpii > > pq;

    pq.push( pllpii(G[0][0], u) );
    dist[0][0] = G[0][0];

    while( !pq.empty() ){

        int ur = pq.top().second.first;
        int uc = pq.top().second.second;
        pq.pop();

        for(int i=0; i<4; i++){

            int vr = ur + dr[i];
            int vc = uc + dc[i];

            if( (vr>=0&&vr<R) && (vc>=0&&vc<C) ){
                int w = G[vr][vc];
                if( dist[vr][vc] > dist[ur][uc] + w ){
                    dist[vr][vc] = (long long)(dist[ur][uc] + w);
                    pq.push( pllpii( dist[vr][vc], pii(vr, vc) ) );
                }
            }
        }
    }

    return;
}

int main()
{
    //READ("in.txt");

    int tc, Case=1, row, col;

    scanf("%d", &tc);

    while( tc-- ){

        scanf("%d%d", &row, &col);

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                scanf("%d", &G[i][j]);
            }
        }

        R = row; C = col;
        SET(dist, INF);

        dijkstra( pii(0, 0) );

        printf("%lld", dist[R-1][C-1]);
        printf("\n");

    }

    return 0;
}

