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
#define ff first
#define ss second
#define SET(a, b) memset( a, b, sizeof (a) )
#define READ(f) freopen(f, "r", stdin);
#define WRITE(f) freopen(f, "w", stdout);

char G[MAX+7][MAX+7];
bool visited[MAX+7][MAX+7];
int d[MAX+7][MAX+7];

int dr[] = {-1, 0, 0, 1, -1, -1, 1, 1}; int dc[] = {0, -1, 1, 0, -1, 1, -1, 1};
int kdr[] = {-1, -2, -2, -1, 1, 2, 2, 1}; int kdc[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int R, C;

bool isValid( int r, int c){
    return (r>=0 && r<R) && (c>=0 && c<C);
}

int main()
{
    //READ("in.txt");
    int Case=1;
    char dump[2], ch;
    pii src, dest;

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d %d", &R, &C);

        SET( d, -1 );
        SET( visited, false );

        gets(dump);

        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                ch = getchar();
                if( ch == 'A' ) src = pii( i, j );
                if( ch == 'B' ) dest = pii( i, j );
                G[i][j] = ch;
            }
            getchar();
        }

        queue <pii> Q;

        Q.push(src);
        d[src.ff][src.ss] = 0;
        visited[src.ff][src.ss] = true;
        bool loop = true;

        while( !Q.empty() && loop ){
            pii u = Q.front();

            for(int i=0; i<8 && loop; i++){
                pii v;
                v.ff = u.ff + dr[i];
                v.ss = u.ss + dc[i];

                if( !visited[v.ff][v.ss] && v != dest ){
                    for(int j=0; j<8; j++){
                        int r = v.ff + kdr[j];
                        int c = v.ss + kdc[j];

                        if( isValid(r, c) && G[r][c] == 'Z' ){
                            visited[v.ff][v.ss] = true;
                            break;
                        }
                    }
                }

                if( isValid(v.ff, v.ss) && !visited[v.ff][v.ss] && (G[v.ff][v.ss] == '.' || G[v.ff][v.ss] == 'B') ){
                    visited[v.ff][v.ss] = true;
                    d[v.ff][v.ss] = d[u.ff][u.ss] + 1;
                    Q.push(v);

                    if( v == dest ){
                        loop = false;
                    }
                }
            }
            Q.pop();
        }

        if( loop ) printf("King Peter, you can't go now!\n");
        else printf("Minimal possible length of a trip is %d\n", d[dest.ff][dest.ss]);
    }

    return 0;
}

