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
#define MAX 10000
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

int A[MAX+7], lis[MAX+7], lds[MAX+7];

int main()
{
    //READ("in.txt");
    int Case=1, n;
    char dump[2];

    while( scanf("%d", &n) == 1 )
    {

        for(int i=0; i<n; i++) scanf("%d", &A[i]);

        int dp[n+7];
        SET( dp, INF);
        dp[0] = -INF;
        int mx = 0;

        for(int i=0; i<n; i++)
        {
            int j = upper_bound(dp, dp+n, A[i] ) - dp; //cout << j << " ";

            if( dp[j-1] < A[i] )
            {
                dp[j] = A[i];
                lis[i] = j;
            }
            else if( dp[j-1] == A[i] ) lis[i] = j-1;

            mx = max( mx, j );
        }

        SET( dp, INF );
        dp[0] = -INF;
        int ans = 0;
        mx = 0;

        for(int i=n-1; i>=0; i--)
        {
            int j = upper_bound(dp, dp+n, A[i] ) - dp;

            if( dp[j-1] < A[i] )
            {
                dp[j] = A[i];
                lds[i] = j;
            }
            else if( dp[j-1] == A[i] ) lds[i] = j-1;

            mx = max( mx, j );
            ans = max( ans, min(lis[i], lds[i]) );
        }
        /*for(int i=0; i<n; i++) cout << lis[i] << " ";
        cout << endl;
        for(int i=0; i<n; i++) cout << lds[i] << " ";
        cout << endl;*/
        printf("%d\n", (ans*2)-1 );
    }

    return 0;
}

