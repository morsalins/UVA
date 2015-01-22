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
#define pii pair <int, int>
#define pdd pair <double, double>
#define SIZE 1000
#define MAX 100000
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

queue <int> Q;
bool visited[MAX+7];
int d[MAX+7];

int main()
{
    //READ("in.txt");
    int Case=1, v, m;
    char dump[2];
    string line;

    while( scanf("%d %d", &v, &m) ){

        if( v==0 && m==0 ) return 0;

        pdd G[MAX+5];
        double X, Y;

        scanf("%lf %lf", &G[0].ff, &G[0].ss);
        scanf("%lf %lf", &G[1].ff, &G[1].ss);

        int idx = 2;
        gets(dump);

        while( getline(cin, line) ){
            if( line.size()==0 ) break;
            stringstream SS(line);
            SS >> X; SS >> Y;
            //cout << X << " " << Y << endl;
            G[idx].ff = X; G[idx].ss = Y;
            idx++;
        }

        SET(visited, false);
        SET(d, -1);
        double len = (double)(v*m*60);

        Q.push(0);
        visited[0] = true;
        d[0] = 0;

        while( !Q.empty() ){
            int u = Q.front();
            for(int v=0; v<idx; v++){
                if( v!=u ){
                    if( hypot( G[v].ff-G[u].ff, G[v].ss-G[u].ss ) < len ){
                        if( !visited[v] ){
                            visited[v] = true;
                            d[v] = d[u] + 1;
                            Q.push(v);
                        }
                    }
                }
            }
            Q.pop();
        }

        if( visited[1] ) printf("Yes, visiting %d other holes.\n", d[1]-1);
        else printf("No.\n");
    }

    return 0;
}

