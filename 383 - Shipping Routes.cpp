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

queue <string> Q;

int main()
{
    //READ("in.txt");
    int Case=1, n, m, p;
    char dump[2];

    int tc; scanf("%d", &tc);

    printf("SHIPPING ROUTES OUTPUT\n\n");

    while( tc-- ){

        scanf("%d %d %d", &n, &m, &p);
        gets(dump);

        map <string, VS> G;
        string s1, s2;

        for(int i=1;i<=n; i++){
            cin >> s1;
        }

        for(int i=1; i<=m; i++){
            cin >> s1 >> s2;
            G[s1].pb(s2);
            G[s2].pb(s1);
        }

        printf("DATA SET  %d\n\n", Case++);

        int sz;
        string src, dest;

        for(int q=1; q<=p; q++){

            cin >> sz >> src >> dest;
            //cout << sz << " " << src << " " << dest << "\n";
            map <string, int> dist;

            Q.push(src);
            dist[src] = 0;

            while( !Q.empty() ){

                string u = Q.front();
                for(int i=0; i<G[u].size(); i++){
                    string v = G[u][i];
                    if( v!=src && dist[v]==0 ){
                        dist[v] = dist[u] + 1;
                        Q.push(v);
                    }
                }
                Q.pop();
            }

            if( dest!=src && dist[dest]==0 ) printf("NO SHIPMENT POSSIBLE\n");
            else printf("$%lld\n", (I64)(sz*dist[dest]*100) );
        }
        puts("");

    }
    printf("END OF OUTPUT\n");

    return 0;
}

