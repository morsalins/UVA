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

using namespace std;

char grid[MAX][MAX];
bool visited[MAX][MAX];
int cnt, R, C;
int dr[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dc[] = {1, -1, 0, 0, -1, 1, -1, 1};

bool isValid (int r, int c){

    return (r>=0 && r<R) && (c>=0 && c<C) && !(visited[r][c]);
}

void floodFill(int r, int c){

    visited[r][c] = true;
    cnt++;

    for(int dir=0; dir<8; dir++){

        int r1 = r + dr[dir];
        int c1 = c + dc[dir];

        if( isValid(r1, c1) && grid[r1][c1]=='W' ){
            floodFill(r1, c1);
        }
    }

    return;

}

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);

    int tc, r, c;
    char co_ord[MAX];

    scanf("%d", &tc);
    getchar();
    getchar();

    while( tc-- ){

        R = 0;
        while( gets(grid[R]) && grid[R][0]!='\0' ){

            if( isdigit(grid[R][0]) ){

                sscanf( grid[R], "%d %d", &r, &c);
                memset( visited, false, sizeof visited );
                cnt = 0;
                C = strlen(grid[0]);
                floodFill(r-1, c-1);
                printf("%d\n", cnt);
            }
            else R++;
        }

        if(tc) printf("\n");
    }

    return 0;
}

