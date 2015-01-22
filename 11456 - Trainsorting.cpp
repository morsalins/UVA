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
#define SIZE 10000000
#define MAX 2000
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

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%d", &n);
        int ans = 0;

        for(int i=0; i<n; i++) scanf("%d", &A[i]);

        for(int i=n-1; i>=0; i--){

            lis[i] = 1; lds[i] = 1;

            for(int j=n-1; j>i; j--){

                if( A[i] < A[j] )
                    lis[i] = max( lis[i], lis[j]+1 );
                else if( A[i] > A[j] )
                    lds[i] = max( lds[i], lds[j]+1 );
            }

            ans = max( ans, lis[i]+lds[i]-1);
        }

        printf("%d\n", ans);
    }

    return 0;
}
