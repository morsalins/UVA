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
#define SIZE 10000
#define MAX 154750
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

struct edges{
    int u, v, w;
    bool operator < (const struct edges &O) const{
        return w < O.w;
    }
};

typedef struct edges E;

E e[MAX+5];
int keys[500+5];
int par[SIZE+5], sz[SIZE+5];
int ind = 0;

int compareWith0000(int shortest, int temp){

    int t0, t1, t2, t3;

    t0 = temp%10; temp/=10;  t1 = temp%10; temp/=10;   t2 = temp%10; temp/=10;   t3 = temp%10; temp/=10;

    temp = 0;

    temp += min ( abs(max(t0,0) - min(t0, 0)), abs(max(t0,0) - (min(t0, 0)+10)) );
    temp += min ( abs(max(t1,0) - min(t1, 0)), abs(max(t1,0) - (min(t1, 0)+10)) );
    temp += min ( abs(max(t2,0) - min(t2, 0)), abs(max(t2,0) - (min(t2, 0)+10)) );
    temp += min ( abs(max(t3,0) - min(t3, 0)), abs(max(t3,0) - (min(t3, 0)+10)) );

    shortest = min( temp, shortest);

    return shortest;
}

void compareWithAll(int key, int idx){

    int temp = key, t0, t1, t2, t3, k0, k1, k2, k3;

    t0 = temp%10; temp/=10;  t1 = temp%10; temp/=10;   t2 = temp%10; temp/=10;   t3 = temp%10; temp/=10;

    for(int i=0; i<idx; i++){

        temp = keys[i];
        k0 = temp%10; temp/=10;  k1 = temp%10; temp/=10;   k2 = temp%10; temp/=10;   k3 = temp%10; temp/=10;

        temp = 0;

        temp += min ( abs(max(t0,k0) - min(t0, k0)), abs(max(t0,k0) - (min(t0, k0)+10)) );
        temp += min ( abs(max(t1,k1) - min(t1, k1)), abs(max(t1,k1) - (min(t1, k1)+10)) );
        temp += min ( abs(max(t2,k2) - min(t2, k2)), abs(max(t2,k2) - (min(t2, k2)+10)) );
        temp += min ( abs(max(t3,k3) - min(t3, k3)), abs(max(t3,k3) - (min(t3, k3)+10)) );

        e[ind].u = key;
        e[ind].v = keys[i];
        e[ind].w = temp;
        ind++;
    }

    return;
}

int F (int r) {

    if( par[r] == r )return r;
    return par[r] = F( par[r] );
}

I64 MST(int n){

    I64 total = 0;
    int cnt = 0;

    for(int i=0; i<ind; i++){

        int pu = F( e[i].u );
        int pv = F( e[i].v );

        if( pu!=pv ){

            if( sz[pu] < sz[pv] ) swap( pu, pv );
            par[pv] = pu;
            sz[pu] += sz[pv];

            total += e[i].w;
            cnt++;
            if( cnt == n-1 ) break;
        }
    }

    return total;
}

int main()
{
    //READ("in.txt");
    int Case=1, n, key, temp;
    char dump[2];

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d", &n);
        int shortest_start = 100, idx=0;
        ind = 0;

        for(int i=1; i<=n; i++){

            scanf("%d", &key);
            par[key] = key;
            sz[key] = 1;

            shortest_start = compareWith0000(shortest_start, key);
            compareWithAll(key, idx);
            keys[idx++] = key;
        }

        sort( e, e+ind );

        printf("%lld\n", MST(n) + shortest_start );
    }

    return 0;
}

