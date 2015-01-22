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
#define MAX 1024
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

pair < char, int > lang[26];
int R, C;
bool visited[MAX][MAX];
char grid[MAX][MAX];
int dr[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dc[] = {1, -1, 0, 0, -1, 1, -1, 1};

void reset(){

    for(int i=0; i<26; i++){
        lang[i] = make_pair(i+97, 0);
    }

    SET(visited, false);

    return;
}

bool comp( pair<char, int> l, pair<char, int> r ){

    if( l.second == r.second )
        return l.first < r.first;

    return l.second > r.second;
}

bool isValid(int r, int c){

    return (r>=0 && r<R) && (c>=0 && c<C) && !visited[r][c];
}

void BFS(int r, int c){

    visited[r][c] = true;

    for(int dir=0; dir<4; dir++){

        int r1 = r + dr[dir];
        int c1 = c + dc[dir];

        if( isValid(r1, c1) && grid[r1][c1] == grid[r][c] ){
            BFS(r1, c1);
        }
    }

    return;
}

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);

    int tc, Case=1;

    scanf("%d", &tc);

    while( tc-- ){

        scanf("%d%d", &R, &C);
        getchar();

        for(int i=0; i<R; i++){
            gets( grid[i] );
        }

        reset();

        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){

                if( !visited[i][j] ){
                    lang[ grid[i][j]-97 ].second++;
                    BFS(i, j);
                }
            }
        }

        sort(lang, lang+26, comp);

        printf("World #%d\n", Case++);
        for(int i=0; i<26 && lang[i].second ; i++){
            printf("%c: %d\n", lang[i].first, lang[i].second);
        }
    }

    return 0;
}

