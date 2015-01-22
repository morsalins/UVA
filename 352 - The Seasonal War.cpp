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
#define SET(a, b) memset( a, b, sizeof (a) )

using namespace std;

int R, C;
int cnt;
bool visited[MAX][MAX];
char grid[MAX][MAX];
int dr[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dc[] = {1, -1, 0, 0, -1, 1, -1, 1};

bool isValid(int r, int c){

    return (r>=0 && r<R) && (c>=0 && c<C) && !visited[r][c];
}

void DFS (int r, int c){

    visited[r][c] = true;

    for(int dir=0; dir<8; dir++){

        int r1 = r + dr[dir];
        int c1 = c + dc[dir];

        if( isValid(r1, c1) && grid[r1][c1]=='1' )
            DFS(r1, c1);
    }

    return;
}

int main()
{
    int tc, Case = 1;

    while( cin >> R ){

        getchar();

        C=R;

        for(int i=0; i<R; i++){
            gets( grid[i] );
        }

        SET( visited, false );
        cnt = 0;

        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){

                if( !visited[i][j] && grid[i][j]=='1' ){
                    cnt++;
                    DFS(i, j);
                }
            }
        }

        printf("Image number %d contains %d war eagles.\n", Case++, cnt);
    }

    return 0;
}

