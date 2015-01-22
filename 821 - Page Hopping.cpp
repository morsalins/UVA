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
#define MAX 110
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

int dist[MAX+5][MAX+5];
int nodes[MAX+5];
bool occur[MAX+5];

int main()
{
    //READ("in.txt");

    int Case=1;
    string in;

    while( getline(cin, in) )
    {
        stringstream ss(in);
        int u, v;
        ss >> u >> v;

        if(u==0 && v==0) return 0;

        SET(dist, INF);
        SET(occur, false);
        int idx = 0;

        if( !occur[u] )
        {
            occur[u] = true;
            nodes[idx++] = u;
        }
        if( !occur[v] )
        {
            occur[v] = true;
            nodes[idx++] = v;
        }


        do
        {
            if(u==0 && v==0) break;

            dist[u][v] = 1;
            if( !occur[u] )
            {
                occur[u] = true;
                nodes[idx++] = u;
            }
            if( !occur[v] )
            {
                occur[v] = true;
                nodes[idx++] = v;
            }

        } while(ss >> u >> v);

        int n = idx;

        for(int k=0; k<idx; k++)
        {
            int K = nodes[k];
            for(int i=0; i<idx; i++)
            {
                int I = nodes[i];
                for(int j=0; j<idx; j++)
                {
                    int J = nodes[j];
                    if( I!=J && dist[I][K]<INF && dist[K][J]<INF )
                        dist[I][J] = min( dist[I][J], dist[I][K]+dist[K][J] );
                }
            }
        }
        int total = 0.0;
        for(int i=0; i<idx; i++)
            for(int j=0; j<idx; j++)
                if(nodes[i]!=nodes[j])total += dist[ nodes[i] ][ nodes[j] ];

        int P = n*(n-1);
        printf("Case %d: average length between pages = %.3lf clicks\n", Case++, (double)(total/(double)P) );
    }

    return 0;
}
