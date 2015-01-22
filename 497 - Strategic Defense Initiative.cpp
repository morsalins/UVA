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
#define MAX 100000
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

int A[MAX+7], dp[MAX+7], id[MAX+7], path[MAX+7];

void F (int last){

    if( last == -1 ) return;

    F( path[last] );

    printf("%d\n", A[last] );

    return;
}

int main()
{
    //READ("in.txt");
    int Case=1, data;
    char dump[2], ms[30];

    int tc; scanf("%d", &tc);
    gets( dump );
    gets( dump );

    while( tc-- ){

        int idx = -1, ans = 0, last;
        SET( dp, INF );
        dp[0] = -INF;
        id[0] = -1;

        while( gets(ms) ){

            if( ms[0] == '\0' ) break;

            sscanf( ms, "%d", &data );
            A[++idx] = data;

            int j = upper_bound( dp, dp+ans+2, A[idx] ) - dp;

            if( dp[j-1] < A[idx] && A[idx] < dp[j] ){
                dp[j] = A[idx];
                id[j] = idx;
                path[idx] = id[j-1];

                if( ans < j ){
                    ans = j;
                    last = idx;
                }
            }
        }

        if( Case > 1 ) puts(""); Case++;
        printf("Max hits: %d\n", ans);
        F( last );
    }

    return 0;
}

