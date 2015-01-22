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

int grid[MAX][MAX];
bool visited[MAX][MAX];
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
int R, C;

bool isValid(int r, int c){

    return (r>=0 && r<R) && (c>=0 && c<C) && !visited[r][c];
}

void DFS(int r, int c, int val){

    visited[r][c] = true;

    for(int dir=0; dir<4; dir++){

        int r1 = r + dr[dir];
        int c1 = c + dc[dir];

        if( isValid(r1, c1) && grid[r1][c1]==val  ){

            DFS(r1, c1, val);
        }
    }

    return;
}

int main()
{
    int n, r, c;
    bool cover[MAX];

    while( scanf("%d", &n)==1 ){

        if( n==0 ) return 0;
        getchar();

        R = C = n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                grid[i][j] = n;
            }
        }

        for(int i=1; i<n; i++){

            string s;
            getline(cin, s);

            stringstream ss(s);

            while( ss >> r >> c ){

                grid[r-1][c-1] = i;
            }
        }

        SET( visited, false );
        SET( cover, false );

        bool Continue = true;

        for(int i=0; i<R && Continue; i++){

            for(int j=0; j<C && Continue; j++){

                int val = grid[i][j];

                if( !visited[i][j] ){

                    if( cover[val] ){
                        Continue = false;
                    }

                    else{
                        cover[val] = true;
                        DFS(i, j, val);
                    }
                }
            }
        }

        if( Continue ) printf("good\n");
        else printf("wrong\n");

    }
    return 0;
}

