#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
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

#define I64 long long int
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
#define SET(a, b) memset( a, b, sizeof (a) )
#define READ(f) freopen(f, "r", stdin);
#define WRITE(f) freopen(f, "w", stdout);

using namespace std;

bool grid[MAX][MAX];
const bool visited = true;
map <pii, int> dist;
int R = 8, C = 8;
int dr[] = {-1, -2, -1, -2, 1, 2, 1, 2};
int dc[] = {-2, -1, 2, 1, -2, -1, 2, 1};

bool isValid (int r, int c){

    return (r>=0 && r<R) && (c>=0 && c<C);
}

void BFS (pii source, pii dest){

    queue <pii> Q;

    grid[source.first][source.second] = visited;
    Q.push(source);
    dist[source] = 0;

    bool Continue = true;

    while( !Q.empty() && Continue ){

        pii u = Q.front();

        for(int dir=0; dir<8 && Continue; dir++){

            pii v;
            v.first = u.first + dr[dir];
            v.second = u.second + dc[dir];

            if( isValid(v.first, v.second) && grid[v.first][v.second]!=visited ){

                grid[v.first][v.second] = visited;
                dist[v] = dist[u] + 1;
                Q.push(v);

                if( v==dest )
                    Continue = false;
            }
        }

        Q.pop();
    }

    return;
}

int main()
{
    //READ("in.txt");

    int tc, Case=1;
    char s1[3], s2[3];

    while( cin >> s1 >> s2 ){

        pii source, dest;

        source.first = s1[1] - 49;
        source.second = s1[0] - 97;

        dest.first = s2[1] - 49;
        dest.second = s2[0] - 97;

        SET( grid, false );

        BFS( source, dest );

        printf("To get from %s to %s takes %d knight moves.\n", s1, s2, dist[dest]);

        dist.clear();
    }

    return 0;
}

