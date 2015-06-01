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
#define MAX 10000000
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

unsigned int composite[MAX >> 6];
vector <I64> primes;

void Sieve ()
{
    int limit = sqrt(MAX) + 10;
    primes.pb(2);

    for (unsigned int i = 3; i <= limit; i += 2) {
        if (!ifc(i)) {
            for (unsigned int j = i * i, k = i << 1; j <= MAX; j += k) {
                isc(j);//DEBUG(i, isc(j))
            }
        }
    }

    for (int i = 3; i <= MAX; i += 2) {
        if (!ifc(i)) primes.pb(i);

    }
}

I64 LPD (I64 n)
{
    bool isprime = true;
    I64 largestPrime = -10;
    int cnt = 0;

    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
         if (n % primes[i] == 0) {
            cnt++;
            while (n % primes[i] == 0) {
                isprime = false;
                n /= primes[i];
                largestPrime = max(largestPrime, primes[i]);
            }
         }
    }
    if (!isprime && cnt >= 1 && n > 1) largestPrime = max(largestPrime, n);
    else if (isprime || cnt <= 1) largestPrime = -1;

    return largestPrime;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    I64 n;
    char dump[2];

    Sieve();

    while (scanf("%lld", &n) == 1) {
        if (n == 0) return 0;
        printf("%lld\n", LPD(abs(n)));
    }
    return 0;
}



