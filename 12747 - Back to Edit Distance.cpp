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
#define MAX 200000
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

int a[MAX+7], lis[MAX+7];
int dp[MAX+7];

int main()
{
    //READ("in.txt");
    int Case=1, n, data;
    char dump[2];

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d", &n);

        for(int i=0; i<n; i++){
            scanf("%d", &data);
            a[data] = i+1;
        }

        for(int i=0; i<n; i++){
            scanf("%d", &data);
            lis[i] = a[data];
        }

        for(int i=0; i<=n+1; i++) dp[i] = INF;
        dp[0] = -INF;
        int LIS = 0;

        for(int i=0; i<n; i++){
            int j = upper_bound( dp, dp+LIS+3, lis[i] ) - dp;
            if( dp[j-1] < lis[i] && lis[i] < dp[j] ){
                dp[j] = lis[i];
                LIS = max( LIS, j );
            }
        }

        int ans = (n-LIS) * 2;

        printf("Case %d: %d\n", Case++, ans);
    }

    return 0;
}
