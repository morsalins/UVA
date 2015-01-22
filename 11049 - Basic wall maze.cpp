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
#define MAX 10
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

int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};
char dir[] = {'N', 'W', 'E', 'S'};

bool wall[5][MAX+7][MAX+7];
bool visited[MAX+7][MAX+7];
pii path[MAX+7][MAX+7];
char direction[MAX+7][MAX+7];

void wallNS(int r, int c, int c1){

    for(int i=min(c, c1)+1; i<=max(c, c1); i++){

        wall[3][r][i] = false;
        wall[0][r+1][i] = false;
    }

    return;
}

void wallEW(int r, int c, int r1){

    for(int i=min(r, r1)+1; i<=max(r, r1); i++){

        wall[2][i][c] = false;
        wall[1][i][c+1] = false;
    }

    return;
}

bool isValid(int r, int c){
    return (r>0 && r<=6) && (c>0 && c<=6);
}

void F(pii src, pii dest){

    if( path[dest.ff][dest.ss] != src ) F( src, path[dest.ff][dest.ss] );

    printf("%c", direction[dest.ff][dest.ss]);

    return;
}

int main()
{
    //READ("in.txt");
    int Case=1;
    char dump[2];
    pii src, dest;
    int r, c, r1, c1;

    while( scanf("%d %d", &src.ss, &src.ff) ){
        if( src == pii(0, 0) ) return 0;

        SET( wall, true );
        SET( visited, false );

        scanf("%d %d", &dest.ss, &dest.ff);

        for(int i=1; i<=3; i++){

            scanf("%d %d %d %d", &c, &r, &c1, &r1);

            if( c != c1 ){
                wallNS(r, c, c1);
            }
            else if( r != r1 ){
                wallEW(r, c, r1);
            }
        }

        queue <pii> Q;

        Q.push( src );
        visited[src.ff][src.ss] = true;
        path[src.ff][src.ss] = src;
        direction[src.ff][src.ss] = '0';
        bool loop = true;

        while( !Q.empty() && loop ){

            pii u = Q.front();
            for(int i=0; i<4 && loop; i++){

                pii v;
                v.ff = u.ff + dr[i];
                v.ss = u.ss + dc[i];

                if( isValid(v.ff, v.ss) && !visited[v.ff][v.ss] && wall[i][u.ff][u.ss] ){

                    visited[v.ff][v.ss] = true;
                    path[v.ff][v.ss] = u;
                    direction[v.ff][v.ss] = dir[i];
                    Q.push(v);
                    if( v == dest ) loop = false;
                }
            }
            Q.pop();
        }

        F(src, dest);
        puts("");
    }

    return 0;
}

