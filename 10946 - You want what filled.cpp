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
#define MAX 60
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
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
int R, C, cnt;

bool comp (const pair<char, int>& l, const pair<char, int>& r){

    if( l.second == r.second ) return l.first < r.first;

    return l.second > r.second;
}

bool isValid (int r, int c){

    return (r>=0 && r<R) && (c>=0 && c<C) && !visited[r][c];
}

void DFS(int r, int c, char ch){

    visited[r][c] = true;

    for(int dir=0; dir<4; dir++){

        int r1 = r + dr[dir];
        int c1 = c + dc[dir];

        if( isValid(r1, c1) && grid[r1][c1] == ch ){
            cnt++;
            DFS(r1, c1, grid[r1][c1]);
        }
    }

    return;
}

int main()
{
    vector < pair<char, int> > v;
    int Case=1;

    while( scanf("%d %d", &R, &C) == 2 ){

        if( R==0 && C==0 ) return 0;

        getchar();

        for(int i=0; i<R; i++){

            gets( grid[i] );
        }

        SET( visited, false );

        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){

                cnt = 0;
                char ch = grid[i][j];

                if( !visited[i][j] && ch!='.' ){
                    cnt++;
                    DFS(i, j, ch);
                    v.pb( mp(ch, cnt) );
                }
            }
        }

        sort( v.begin(), v.end(), comp );

        int len = v.size();

        printf("Problem %d:\n", Case++);
        for(int i=0; i<len; i++){

            cout << v[i].first << " " << v[i].second << "\n";
        }

        v.clear();
    }



    return 0;
}

