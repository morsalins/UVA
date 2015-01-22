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
#define MAX 30
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

int d[MAX+5][MAX+5];
int path[MAX+5][MAX+5];

void findPath(int src, int d){

    if( path[src][d]!=src ) findPath( src, path[src][d]);

    printf(" %c", d+65);

    return;
}

int main()
{
    //READ("in.txt");

    int Case=1, w, n, m, tar;
    char u, v, src, dest, dump[2];


    while( scanf("%d %d", &n, &m)==2 )
    {
        SET(d, INF);
        SET(path, -1);

        while( m-- ){
            gets(dump);
            scanf("%c %c %d", &u, &v, &w);
            d[u-65][v-65] = w; path[u-65][v-65] = u-65;
            d[v-65][u-65] = w; path[v-65][u-65] = v-65;
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if( i!=j && d[i][k]<INF && d[k][j]<INF ){
                        if( d[i][j] == d[i][k] + d[k][j] ){
                            path[i][j] = min( path[i][j], path[k][j] );
                        }
                        else if( d[i][j] > d[i][k] + d[k][j] ){
                            d[i][j] = d[i][k] + d[k][j];
                            path[i][j] = path[k][j];
                        }
                    }
                }
            }
        }


        int q; scanf("%d", &q);
        while( q-- ){
            gets(dump);
            scanf("%c %c", &src, &dest);
            printf("%c", src);
            //cout << src-65;
            findPath( src-65, dest-65 );
            puts("");
        }
    }

    return 0;
}
