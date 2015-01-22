#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include <sstream>
#include<stack>
#include<queue>
#include<cctype>
#include<math.h>
#include<cstdlib>

#define I64 long long int
#define SIZE 1000
#define MAX 128
#define VI vector <int>
#define VS vector <string>
#define MSI map <string, int>
#define MIS map <int, string>
#define MSS map <string, string>
#define pb push_back
#define pob pop_back
#define IT iterator
#define SET(a, b) memset( a, b, sizeof(a) );

using namespace std;

bool visited[MAX][MAX];
char grid[MAX][MAX];
int R, C, cnt;
int dr[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dc[] = {1, -1, 0, 0, -1, 1, -1, 1};

bool isValid (int r, int c){

    return (r>=0 && r<R) && (c>=0 && c<C) && !(visited[r][c]);
}

void floodFill(int r, int c){

    visited[r][c] = true;

    for(int dir=0; dir<8; dir++){

        int r1 = r + dr[dir];
        int c1 = c + dc[dir];

        if( isValid(r1, c1) && grid[r1][c1]=='@' ){
            floodFill(r1, c1);
        }
    }

    return;
}

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);

    int tc;

    while( cin >> R >> C ){

        getchar();
        if( R==0 )return 0;

        for(int i=0; i<R; i++){
            gets( grid[i] );
        }

        cnt= 0;
        SET(visited, false);

        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++){

                if( !(visited[r][c]) && grid[r][c]=='@' ){
                    cnt++;
                    floodFill(r, c);

                }
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}

