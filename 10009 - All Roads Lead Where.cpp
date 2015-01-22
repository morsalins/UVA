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

map <string, string> path;
queue <string> Q;

void findPath(string d){

    if( path[d] != d ) findPath( path[d] );

    cout << d[0];
    return;
}

int main()
{
    //READ("in.txt");
    int Case=1, n, q;
    char dump[2];

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d %d", &n, &q);
        gets(dump);
        string s1, s2;
        map <string, VS> G;

        for(int i=1; i<=n; i++){
            cin >> s1 >> s2;
            G[s1].pb(s2);
            G[s2].pb(s1);
        }

        for(int i=1; i<=q; i++){

            map <string, bool> visited;

            cin >> s1 >> s2;

            Q.push(s1);
            visited[s1] = true;
            path[s1] = s1;

            while( !Q.empty() ){
                string u = Q.front();
                for(int j=0; j<G[u].size(); j++){
                    string v = G[u][j];
                    if( !visited[v] ){
                        visited[v] = true;
                        path[v] = u;
                        Q.push(v);
                    }
                }
                Q.pop();
            }

            findPath(s2);
            puts("");
        }
        if(tc) puts("");
    }

    return 0;
}

