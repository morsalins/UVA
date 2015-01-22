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

int main()
{
    //READ("in.txt");
    int Case=1, n, q, value;
    int arr[MAX+7];
    char dump[2];

    while( scanf("%d %d", &n, &q) ){

        if( n==0 && q==0 ) return 0;

        for(int i=1; i<=n; i++){

            scanf("%d", &arr[i]);
        }

        sort( arr+1, arr+n+1 );

        printf("CASE# %d:\n", Case++);

        while( q-- ){

            scanf("%d", &value);

            int l = lower_bound( arr+1, arr+n+1, value ) - arr;
            int u = upper_bound( arr+1, arr+n+1, value ) - arr;

            if( u-l )printf("%d found at %d\n", value, l);
            else printf("%d not found\n", value);
        }
    }

    return 0;
}

