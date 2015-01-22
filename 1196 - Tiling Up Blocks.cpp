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

int dp[MAX+7][MAX+7];

int main()
{
    int Case=1, x, y, n;
    char dump[2];

    while( scanf("%d", &n) ){

        if( n==0 ) break;

        int mx = 0, ans = 0;
        SET(dp, 0);

        for(int i=0; i<n; i++){
            scanf("%d %d", &x, &y);
            dp[x][y]++;
            mx = max( mx, max(x, y) );
        }

        for(int i=1; i<=mx; i++){
            for(int j=1; j<=mx; j++){
                dp[i][j] += max( dp[i-1][j], dp[i][j-1] );
                ans = max( ans, dp[i][j]);
            }
        }

        printf("%d\n", ans);
    }

    puts("*");
    return 0;
}

