#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include <sstream>
#include<set>
#include<stack>
#include<queue>
#include<cctype>
#include<math.h>
#include<cstdlib>

#define I64 long long int
#define pii pair<int, int>
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

using namespace std;

bool grid[MAX][MAX];
bool visited[MAX][MAX];
int level[MAX][MAX];
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};
int R, C;
const bool BOMB = true;

bool isValid (pii v){

    return (v.first>=0 && v.first<R) && (v.second>=0 && v.second<C) && !visited[v.first][v.second];
}

void BFS (pii source, pii dest){

    queue <pii> Q;
    bool Continue = true;

    Q.push(source);
    visited[source.first][source.second] = true;
    level[source.first][source.second] = 0;

    while( !Q.empty() && Continue ){

        pii u = Q.front();

        for(int dir=0; dir<4; dir++){

            pii v;

            v.first = u.first + dr[dir];
            v.second = u.second + dc[dir];

            if( isValid(v) && grid[v.first][v.second]!=BOMB ){

                visited[v.first][v.second] = true;
                level[v.first][v.second] = level[u.first][u.second] + 1;

                if( v==dest ){
                    Continue = false;
                    break;
                }

                Q.push(v);
            }
        }

        Q.pop();
    }

    return;
}

int main()
{
    freopen("i.txt", "r", stdin);
    int tc;

    while( scanf("%d %d", &R, &C) == 2 ){

        if( R==0 && C==0 ) return 0;

        SET(visited, false);
        SET(level, 0);
        SET(grid, false);

        int bombsr;
        scanf("%d", &bombsr);

        while( bombsr-- ){

            int row;
            int bombsc;

            scanf("%d %d", &row, &bombsc);

            while( bombsc-- ){

                int col;
                scanf("%d", &col);
                grid[row][col] = BOMB;
            }
        }

        int sr, sc, dr, dc;
        scanf("%d %d %d %d", &sr, &sc, &dr, &dc);

        pii u = mp( sr, sc );
        pii v = mp( dr, dc);

        BFS(u, v);

        printf("%d\n", level[dr][dc]);

        /*for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
              cout << grid[i][j] << " ";
            }
            cout << "\n";
        }*/
    }
    return 0;
}
