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

map <string, string> par;
map <string, int> sz;
map <string, bool> occur;

string F( string r ){
    if( r==par[r] ) return r;
    return par[r] = F( par[r] );
}

int main()
{
    //READ("in.txt");
    int Case=1, m;
    string s1, s2;

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d", &m);
        char dump[2];
        gets(dump);

        for(int i=1; i<=m; i++){

            cin >> s1 >> s2;

            if( !occur[s1] ){
                par[s1] = s1;
                sz[s1] = 1;
                occur[s1] = true;
            }
            if( !occur[s2] ){
                par[s2] = s2;
                sz[s2] = 1;
                occur[s2] = true;
            }

            string u = F( s1 );
            string v = F( s2 );

            if( u!=v ){
                if( sz[u]<sz[v] ) swap(u, v);

                par[v] = u;
                sz[u] += sz[v];
            }

            printf("%d\n", sz[u]);
        }

        occur.clear();
    }

    return 0;
}

