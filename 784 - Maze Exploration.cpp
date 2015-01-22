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
#define MAX 200
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

char G[MAX+5][MAX+5];
bool visited[MAX+7][MAX+7];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};
int R, C;

bool isValid( int r, int c ){

    return (r>=0 && r<R) && (c>=0 && G[r][c]!='\0');
}

void DFS( pii u ){

    visited[u.ff][u.ss] = true;
    G[u.ff][u.ss] = '#';

    for(int i=0; i<4; i++){

        pii v;
        v.ff = u.ff + dr[i];
        v.ss = u.ss + dc[i];

        if( isValid( v.ff, v.ss) && !visited[v.ff][v.ss] && G[v.ff][v.ss] == ' ' ){
            DFS(v);
        }
    }

    return;
}

int main()
{
    //READ("in.txt");
    int Case=1;
    char dump[2], ch;

    int tc; scanf("%d", &tc);
    gets(dump);

    while( tc-- ){

        SET( visited, false );

        pii src;
        R = 0;

        while( true ){

            C = 0;
            while( (ch=getchar()) != '\n' ){
                G[R][C++] = ch;
                if( ch == '*' ) src = pii( R, C-1 );
            }
            G[R][C] = '\0';
            if( G[R][0] == '_' && G[R][C-1] == '_' ) break;

            R++;
        }

        DFS(src);
        for(int i=0; i<=R; i++){
            puts(G[i]);
        }
    }

    return 0;
}

