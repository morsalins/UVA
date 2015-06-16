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
#define MAX 100
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

bool composite[MAX + 7];
VI primes;

void Sieve ()
{
    composite[0] = composite[1] = true;
    int limit = sqrt(MAX) + 2;

    for (int i = 3; i <= limit; i += 2) {
        if (!composite[i]) {
            for (int j = i * i, k = i << 1; j <= MAX; j += k) {
                composite[j] = true;
            }
        }
    }

    primes.pb(2);
    for (int i = 3; i <= MAX; i += 2) {
        if (!composite[i]) {
            primes.pb(i);
        }
    }
    return;
}

int getPower (unsigned long int n, unsigned long int p) {
    int res = 0;
    for (unsigned long int i = p; i <= n; i *= p) {
        res += (n / i);
    }
    return res;
}

bool isDivisible (int n, int m, int *mnP)
{
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= m; i++) {
        if (m % primes[i] == 0) {
            int p = 0;
            while (m % primes[i] == 0) {
                m /= primes[i];
                p++;
            }
            int t = getPower(n, primes[i]);
            if (p > t) {
                return false;
            }
            else {
                *mnP = min(*mnP, t / p);
            }
        }
    }

    if (m > 1) {
        int t1 = getPower(n, m);
        if (t1 < 1) {
            return false;
        }
        else {
            *mnP = min(*mnP, t1);
        }
    }
    return true;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1, n, m;
    char dump[2];

    int tc; scanf("%d", &tc);
    Sieve();

    while (tc--) {

        scanf("%d %d", &m, &n);

        int mnP = 1000000000;

        if (isDivisible(n, m, &mnP)) {
            printf("Case %d:\n%d\n", Case++, mnP);
        }
        else {
            printf("Case %d:\nImpossible to divide\n", Case++);
        }
    }
    return 0;
}

