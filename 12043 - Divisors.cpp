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
#define MAX 100000
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

bool prime[MAX + 7];
VI primes;

bool isPrime (int n)
{
    return n == 2 || ((n & 1) && prime[n]);
}

void Sieve ()
{
    SET(prime, true);
    prime[1] = false;
    prime[0] = false;
    int limit = sqrt(MAX) + 2;

    for (int i = 3; i <= limit; i += 2) {
        if (prime[i]) {
            for (int j = i * i, k = i << 1; j <= MAX; j += k) {
                prime[j] = false;
            }
        }
    }

    primes.pb(2);
    for (int i = 3; i <= MAX; i += 2) {
        if (prime[i]) {
            primes.pb(i);
        }
    }
    return;
}

I64 binPow (I64 b, I64 p)
{
    if (p == 0) return 1;
    if (p & 1) return binPow(b, p-1) * b;
    else {
        I64 t = binPow(b, p>>1);
        return t * t;
    }
}

void Divisors (int *num, I64 *sum, int n)
{
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
        int cnt = 0;
        if (n % primes[i] == 0) {
            while (n % primes[i] == 0) {
                n /= primes[i];
                cnt++;
            }
            *num *= (cnt + 1);
            *sum *= (binPow(primes[i], cnt + 1) - 1) / (primes[i] - 1);
        }
    }
    if (n > 1) {
        *num *= 2;
        *sum *= (binPow(n, 2) - 1) / (n - 1);
    }
    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    char dump[2];
    int a, b, k;
    int tc; scanf("%d", &tc);

    Sieve();

    while (tc--) {

        scanf("%d %d %d", &a, &b, &k);

        int num = 0;
        I64 sum = 0;

        if (k >= b || (a <= k && k <= b)) {
            a = k;
        }

        if (k <= a) {
            if (a % k != 0 ) {
                a = a + (k - (a % k));
            }
        }

        for (int i = a; i <= b; i += k) {
            if (isPrime(i)) {
                num += 2;
                sum += (i + 1);
            }
            else {
                int n = 1;
                I64 s = 1;
                Divisors(&n, &s, i);
                num += n;
                sum += s;
            }
        }
        printf("%d %lld\n", num, sum);
    }
    return 0;
}

