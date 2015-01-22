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
#define MAX 100
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

int d[MAX+5][MAX+5];

int main()
{
    //READ("in.txt");

    int Case=1, n, m, u, v, w;
    string s;
    char dump[2];

    while(  scanf("%d %d", &n, &m) ){

        if( n==0 && m==0 ) return 0;

        gets(dump);
        map <int, string> pos;

        for(int i=1; i<=n; i++){
            cin >> s;
            pos[i] = s;
        }

        SET(d, INF);

        for(int i=1; i<=m; i++){
            scanf("%d %d %d", &u, &v, &w);
            d[u][v] = w;
            d[v][u] = w;
        }

        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if( i!=j && d[i][k]<INF && d[k][j]<INF )
                        d[i][j] = min( d[i][j], d[i][k]+d[k][j]);
                }
            }
        }

        I64 min_total = INF;
        string ans;
        for(int i=1; i<=n; i++){
            I64 total = 0;
            for(int j=1; j<=n; j++){
                if( d[i][j]<INF) total += d[i][j];
            }

            if( total < min_total ){
                min_total = total;
                ans = pos[i];
            }
        }

        printf("Case #%d : ", Case++);
        cout << ans << "\n";
    }

    return 0;
}


