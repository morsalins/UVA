#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <functional>
#include <iterator>
#include <map>
#include <numeric>
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
#define SIZE 1000
#define MAX 9876543210
#define EPS 1e-9
#define PI 2*acos(0.0)

#define PII pair <int, int>
#define PLL pair <I64, I64>
#define PDD pair <double, double>
#define PSI pair <string, int>
#define PIS pair <int, string>
#define PSS pair <string string>

#define MII map <int, int>
#define MLL map <I64, I64>
#define MDD map <double, double>
#define MSI map <string, int>
#define MIS map <int, string>
#define MSS map <string string>

#define VI vector <int>
#define VS vector <string>
#define QI queue <int>
#define QS queue <string>
#define SI stack <int>
#define SS stack <string>

#define pb push_back
#define pob pop_back
#define mp make_pair

#define IT iterator
#define ff first
#define ss second

#define SET(a, b) memset( a, b, sizeof (a) )
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define IAMHERE cout << "YES\n";
#define DEBUG(a, b) cout << a << ": " << b << "\n";

bool Check (I64 n)
{
    int mask = 0;
    while (n > 0) {
        int lastDigit = n % 10;
        if (mask & (1 << lastDigit)) return false;
        mask |= (1 << lastDigit);
        n /= 10;
    }
    return true;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    I64 Case=1, n, m, k;
    char dump[2];

    int tc; scanf("%d", &tc);

    while (tc--) {
        scanf("%lld", &n);

        if (Case > 1) puts("");
        Case++;

        for (I64 i = 1; i * n <= MAX; i++) {
            I64 res = i * n;
            if (Check(i) && Check(res)) {
                printf("%lld / %lld = %lld\n", res, i, n);
            }
        }
    }
    return 0;
}

