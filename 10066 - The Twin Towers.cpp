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

int N[MAX+7], M[MAX+7];
int dp[MAX+7][MAX+7];

int main()
{
    //READ("in.txt");
    int Case=1, n, m;
    char dump[2];

    while( scanf("%d %d", &n, &m) ){

        if( n==0 && m==0 ) return 0;

        for(int i=0; i<n; i++)scanf("%d", &N[i]);
        for(int i=0; i<m; i++)scanf("%d", &M[i]);

        SET(dp, 0);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){

                if( N[i-1] == M[j-1] )
                    dp[i][j] = dp[i-1][j-1] + 1;

                else dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }

        printf("Twin Towers #%d\nNumber of Tiles : %d\n", Case++, dp[n][m]);
        puts("");
    }

    return 0;
}

