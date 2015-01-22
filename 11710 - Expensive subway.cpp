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

struct Edges{
    string u, v;
    int w;
    bool operator < (const struct Edges &O ) const{
        return w < O.w;
    }
};

typedef struct Edges E;

vector <E> e;
map <string, string> par;
map <string, int> Size;

string F (string r){
    if( r==par[r] ) return r;
    return par[r] = F( par[r] );
}

I64 MST(int n, string src){

    int cnt = 0;
    I64 total = 0;

    for(int i=0; i<e.size(); i++){

        string u = F( e[i].u );
        string v = F( e[i].v );

        if( u!=v ){
            if( u==src ){
                par[v] = u;
                Size[ u ] += Size[v];
            }
            else if( v==src ){
                par[u] = v;
                Size[ v ] += Size[u];
            }
            else{
                par[u] = v;
                Size[ v ] += Size[u];
            }

            total += e[i].w;

            cnt++;
            if(cnt==n-1){
                break;
            }
        }
    }

    return total;
}

int main()
{
    //READ("in.txt");

    int Case=1, n, m;
    string s1, s2, src;

    //int tc; scanf("%d", &tc);

    while( scanf("%d %d", &n, &m) ){

        if( n==0 && m==0 ) return 0;

        char dump[2];
        gets(dump);
        VS V;

        for(int i=0; i<n; i++){
            cin >> s1;
            //cout << s1 <<endl;
            V.pb(s1);
        }
        int cost;
        E get;
        for(int i=0; i<m; i++){

            cin >> get.u >> get.v;
            scanf("%d", &get.w);
            //cout << get.u << " " << get.v << " " << get.w << endl;
            e.pb(get);
            gets(dump);
        }

        cin >> src;
        //cout << src << endl;

        for(int i=0; i<V.size(); i++){
            par[ V[i] ] = V[i];
            Size[ V[i] ] = 1;
        }

        sort(e.begin(), e.end());

        I64 total = MST(n, src);
        //cout << src << ": " << Size[src] << " -> ";
        if(Size[src]<n) printf("Impossible\n");
        else printf("%lld\n", total);

        e.clear();
    }

    return 0;
}

