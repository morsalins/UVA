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
#define MAX 1000000
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

int A[MAX+7], dp[MAX+7];

int LIS(int n){

    SET( dp, INF);
    dp[0] = -INF;
    int ans = 0;

    for(int i=n; i>=0; i--){

        int j = upper_bound( dp, dp+n, A[i] ) - dp;
        if( dp[j-1] < A[i] && A[i] < dp[j] ){
            dp[j] = A[i];
            ans = max( ans, j );
        }
    }

    return ans;
}

int main()
{
    //READ("in.txt");
    int Case=1, data = 0;
    char dump[2];

    scanf("%d", &data);

    while( data != -1 ){

        int idx = 0;
        while( data != -1){
            A[idx++] = data;
            scanf("%d", &data);
        }

        if( Case>1 ) puts("");
        printf("Test #%d:\n  maximum possible interceptions: %d\n", Case++, LIS(idx-1) );

        scanf("%d", &data);
    }

    return 0;
}

