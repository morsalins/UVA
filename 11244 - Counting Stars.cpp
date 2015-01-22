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
#define MAX 128
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

char grid[MAX][MAX];
bool visited[MAX][MAX];
int dr[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dc[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int R, C, cnt;

bool isValid(int r, int c){

    return (r>=0 && r<R) && (c>=0 && c<C) && !visited[r][c];
}

void DFS(int r, int c){

    visited[r][c] = true;

    for(int dir=0; dir<8; dir++){

        int r1 = r + dr[dir];
        int c1 = c + dc[dir];

        if( isValid(r1, c1) && grid[r1][c1]=='*' ){
            cnt++;
            DFS(r1, c1);
        }
    }

    return;
}

int main()
{
    char ch;

    while( scanf("%d %d", &R, &C) == 2 ){

        if(R==0 && C==0) return 0;

        getchar();

        for(int i=0; i<R; i++){
            gets( grid[i] );
        }

        SET( visited, false);
        int stars = 0;

        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){

                ch = grid[i][j];
                cnt = 0;

                if( !visited[i][j] && ch=='*' ){
                    cnt++;
                    DFS(i, j);

                    if(cnt == 1) stars++;
                }
            }
        }

        printf("%d\n", stars);

    }
    return 0;
}

