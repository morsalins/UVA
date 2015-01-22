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
#define MAX 35
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

struct Dimension{
    int Z, X, Y;
};

typedef struct Dimension D;

int Case=1, l, r, c;

int dl[] = {0, 0, 0, 0, 1, -1};
int dr[] = {0, 0, 1, -1, 0, 0};
int dc[] = {1, -1, 0, 0, 0, 0};

bool isValid(int z, int x, int y){
    return (z>=0 && z<l) && (x>=0 && x<r) && (y>=0 && y<c);
}

int main()
{
    //READ("in.txt");
    char dump[2];

    while( scanf("%d %d %d", &l, &r, &c) ){

        if( l==0 && r==0 && c==0 ) return 0;

        char G[MAX+5][MAX+5][MAX+5];
        char line[40], ch;
        D src, dest;

        gets(dump);

        for(int z=0; z<l; z++){
            for(int x=0; x<r; x++){
                for(int y=0; y<c; y++){
                    G[z][x][y] = ( ch=getchar() );
                    if( ch=='S' ){
                        src.X = x; src.Y = y; src.Z = z;
                    }
                    else if( ch=='E' ){
                        dest.X = x; dest.Y = y; dest.Z = z;
                    }
                }
                G[z][x][c] = '\0';
                gets(dump);
            }
            gets(dump);
        }

        bool Continue = true;
        queue <D> Q;
        int dist[MAX+5][MAX+5][MAX+5];
        SET(dist, -1);

        Q.push(src);
        dist[src.Z][src.X][src.Y] = 0;

        while( !Q.empty() && Continue ){

            D u = Q.front();
            for(int i=0; i<6 && Continue; i++){

                int z = u.Z + dl[i];
                int x = u.X + dr[i];
                int y = u.Y + dc[i];

                if( isValid(z, x, y) && dist[z][x][y]==-1 && (G[z][x][y]=='.' || G[z][x][y]=='E') ){
                    D v;
                    v.Z = z; v.X = x; v.Y = y;
                    dist[v.Z][v.X][v.Y] = dist[u.Z][u.X][u.Y] + 1;
                    Q.push(v);
                    if( G[z][x][y]=='E' ) Continue = false;
                }
            }
            Q.pop();
        }

        if( dist[dest.Z][dest.X][dest.Y]==-1 ) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", dist[dest.Z][dest.X][dest.Y] );
    }

    return 0;
}

