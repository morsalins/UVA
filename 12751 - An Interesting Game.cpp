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

int main()
{
    int Case=1;
    char dump[2];
    I64 n, k, x;

    int tc; scanf("%d", &tc);

    while( tc-- ){

        scanf("%lld %lld %lld", &n, &k, &x);

        I64 N = (n*(n+1)) / 2;
        int l = x+k-1;
        I64 L = (l*(l+1)) / 2;
        int f = x-1;
        I64 F = (f*(f+1)) / 2;
        I64 t = L-F;
        I64 R = N-t;

        printf("Case %d: %lld\n", Case++, R);
    }

    return 0;
}

