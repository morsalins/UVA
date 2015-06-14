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
#define MAX 32000
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

#define ifc(n) (composite[n>>6] & (1<<((n>>1)&31)))
#define isc(n) (composite[n>>6] |= (1<<((n>>1)&31)))

unsigned int composite[MAX];
VI primes;

bool isPrime (int n)
{
    return n == 2 || ((n & 1) && !ifc(n));
}

void Sieve ()
{
    int limit = sqrt(MAX) + 10;
    isc(1);

    for (int i = 3; i <= limit; i += 2) {
        if (!ifc(i)) {
            for (int j = i * i, k = i << 1; j <= MAX; j += k) {
                isc(j);
            }
        }
    }

    primes.pb(2);
    for (int i = 3; i<= MAX; i += 2) {
        if (!ifc(i)) {
            primes.pb(i);
        }
    }
}

int totalDivisors (int n)
{
    int res = 1;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
        int cnt = 0;
        while (n % primes[i] == 0) {
            n /= primes[i];
            cnt++;
        }
        res *= (cnt + 1);
    }
    if (n > 1) res *= 2;
    return res;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    Sieve();

    int tc; scanf("%d", &tc);

    while (tc--) {

        int l, u;
        int mx = -1, ans;

        scanf("%d %d", &l, &u);

        for (int i = l; i <= u; i++) {
            int divisors = 0;
            if (i <= MAX && isPrime(i)) {
                divisors = 2;
            }
            else {
                divisors = totalDivisors(i);
            }

            if (divisors > mx) {
                mx = divisors;
                ans = i;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, u, ans, mx);
    }
    return 0;
}

