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
#define SET(a, b) memset( a, b, sizeof (a) )
#define READ(f) freopen(f, "r", stdin);
#define WRITE(f) freopen(f, "w", stdout);

struct Edges{
    int u, v, w;
    bool operator < (const struct Edges &O ) const{
        return w < O.w;
    }
};

typedef struct Edges E;

vector <E> e;
int par[MAX+7];

int F(int r){

    if(par[r]==r) return r;

    return par[r] = F(par[r]);
}

void MST(int n){

    sort(e.begin(), e.end());
    int cnt = 0;
    int len = e.size();

    for(int i=0; i<len; i++){

        int u = F(e[i].u);
        int v = F(e[i].v);

        if( u!=v ){
            par[u] = v;
            e.erase( e.begin()+i );
            i--;
            cnt++;
            if(cnt == n-1) break;
        }
    }

    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    int Case=1, m, n;
    E get;

    //int tc; scanf("%d", &tc);

    while( scanf("%d %d", &n, &m) ){

        if(m==0 && n==0) return 0;

        for(int i=1; i<=m; i++){

            scanf("%d %d %d", &get.u, &get.v, &get.w);
            e.pb(get);
        }

        for(int i=0; i<=n+5; i++) par[i] =i;

        MST(n);

        if(e.size()==0) printf("forest\n");
        else{
            int len = e.size();
            for(int i=0; i<len; i++){
                printf("%d", e[i].w);
                if( i< len-1 )printf(" ");
            }
            puts("");
        }

        e.clear();
    }

    return 0;
}

