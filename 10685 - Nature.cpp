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
#define MAX 50000
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

MSS par;
MSI sz;

string F (string r){
    if( r==par[r] ) return r;
    return par[r] = F( par[r] );
}

int main()
{
    //READ("in.txt");
    int Case=1, n, m;
    string s1, s2;
    char dump[2];

    while( scanf("%d %d", &n, &m) ){

        if( n==0 && m==0 ) return 0;

        gets(dump);

        for(int i=1; i<=n; i++){
            cin >> s1;
            par[s1] = s1;
            sz[s1] = 1;
        }

        int mx = 1;

        while( m-- ){

            cin >> s1 >> s2;
            string pu = F(s1);
            string pv = F(s2);

            if( pu!=pv ){

                if( sz[pu] < sz[pv] ) swap(pu, pv);
                par[pv] = pu;
                sz[pu] += sz[pv];
                mx = max( mx, sz[pu] );
            }
        }

        printf("%d\n", mx);
    }

    return 0;
}


