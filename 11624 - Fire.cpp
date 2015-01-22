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
#define ff first
#define ss second
#define SET(a, b) memset( a, b, sizeof (a) )
#define READ(f) freopen(f, "r", stdin);
#define WRITE(f) freopen(f, "w", stdout);

int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

char G[MAX+7][MAX+7];
bool visited[MAX+7][MAX+7];
int d[MAX+7][MAX+7], df[MAX+7][MAX+7];
int n, m;

bool isValid(int r, int c){

    return (r>=0 && r<n) && (c>=0 && c<m);
}

int main()
{
    //READ("in.txt");
    int Case=1;
    char dump[2], ch;
    pii J, F;
    pii fires[MAX+7];

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d %d", &n, &m);

        gets(dump);

        SET( visited, false );
        SET( d, INF );
        SET( df, INF );
        int idx = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ch = getchar();
                if( ch=='F' ) fires[idx++] = pii( i, j );
                if( ch=='J' ) J = pii( i, j );
                G[i][j] = ch;
            }
			getchar();
        }

        queue <pii> Q;

        for(int i=0; i<idx; i++){
            F = fires[i];
            Q.push(F);
            visited[F.ff][F.ss] = true;
            df[F.ff][F.ss] = 0;

            while( !Q.empty() ){

                pii u = Q.front();

                for(int i=0; i<4; i++){

                    pii v;
                    v.ff = u.ff + dr[i];
                    v.ss = u.ss + dc[i];

                    if( isValid(v.ff, v.ss) ){

                        if( !visited[v.ff][v.ss] && G[v.ff][v.ss] == 'F' ){
                            visited[v.ff][v.ss] = true;
                            df[v.ff][v.ss] = 0;
                            Q.push(v);
                        }

                        else if( !visited[v.ff][v.ss] && (G[v.ff][v.ss] == '.' || G[v.ff][v.ss] == 'J') ){
                            visited[v.ff][v.ss] = true;
                            df[v.ff][v.ss] = df[u.ff][u.ss] + 1;
                            Q.push(v);
                        }

                        else if( visited[v.ff][v.ss] && (G[v.ff][v.ss] == '.' || G[v.ff][v.ss] == 'J') ){
                            if( df[v.ff][v.ss] > df[u.ff][u.ss]+1 ){
                                df[v.ff][v.ss] = df[u.ff][u.ss]+1;
                                Q.push(v);
                            }
                        }
                    }
                }
                Q.pop();
            }
        }

        SET( visited, false);

        Q.push(J);
        visited[J.ff][J.ss] = true;
        d[J.ff][J.ss] = 0;
        bool possible = false;
        int ans;

        while( !Q.empty() && !possible ){

            pii u = Q.front();

            for(int i=0; i<4 && !possible; i++){

                pii v;
                v.ff = u.ff + dr[i];
                v.ss = u.ss + dc[i];

                if( v.ff==-1 || v.ff==n || v.ss==-1 || v.ss==m ){
                    possible = true;
                    ans = d[u.ff][u.ss] + 1;
                }

                if( isValid(v.ff, v.ss) && !visited[v.ff][v.ss] && d[u.ff][u.ss]+1 < df[v.ff][v.ss] && G[v.ff][v.ss] != '#' ){

                    visited[v.ff][v.ss] = true;
                    d[v.ff][v.ss] = d[u.ff][u.ss] + 1;
                    Q.push(v);
                }
            }
            Q.pop();
        }

        if( !possible ) printf("IMPOSSIBLE\n");
        else printf("%d\n", ans);
        /*for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( df[i][j] == INF ) printf("# ");
                else printf("%d ", df[i][j]);
            }
			puts("");
        }*/
    }

    return 0;
}

