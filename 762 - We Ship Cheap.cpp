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
#define SET(a, b) memset( a, b, sizeof (a) )
#define READ(f) freopen(f, "r", stdin);
#define WRITE(f) freopen(f, "w", stdout);

map <string, string> path;
map <string, bool> visited;
map <string, int> dist;
VS paths;

void findPath(string d){

    if( path[d] != d )findPath(path[d]);

    paths.pb(d);
    return;
}

int main()
{
    //READ("in.txt");
    int Case=1, n;
    char dump[2];
    string s1, s2;

    while( scanf("%d", &n)==1 ){

        gets(dump);
        map <string , VS> G;

        for(int i=1; i<=n; i++){
            cin >> s1 >> s2;
            G[s1].pb(s2);
            G[s2].pb(s1);
            path[s1] = s1;
            path[s2] = s2;
            visited[s1] = false;
            visited[s2] = false;
            dist[s1] = -1;
            dist[s2] = -1;
        }

        string src, dest;
        cin >> src >> dest;

        visited[dest] = false;
        dist[dest] = -1;

        queue <string> Q;

        Q.push(src);
        visited[src] = true;
        path[src] = src;
        dist[src] = 0;

        while( !Q.empty() ){
            string u = Q.front();
            for(int i=0; i<G[u].size(); i++){
                string v = G[u][i];
                if( !visited[v] ){
                    visited[v] = true;
                    dist[v] = dist[u] + 1;
                    path[v] = u;
                    Q.push(v);
                }
            }
            Q.pop();
        }

        paths.clear();
        findPath(dest);

        if(Case>1)puts("");
        Case++;
        if( src==dest ) printf("\n");
        else if( dist[dest] == -1 ) printf("No route\n");
        else{
            for(int i=0; i<paths.size()-1; i++){
                cout << paths[i] << " " << paths[i+1] << "\n";
            }
        }
    }

    return 0;
}

