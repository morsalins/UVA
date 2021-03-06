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
#define MAX 46500
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

    for (int i = 3; i <=limit; i += 2) {
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

I64 binPow (I64 b, I64 p)
{
    if (p == 0) return 1;
    if (p == 1) return b;

    if (p & 1) return binPow(b, p-1) * b;
    else {
        I64 t = binPow(b, p/2);
        return t * t;
    }
}

I64 min_Sum_LCM (int n)
{
    int cnt = 0;
    I64 sum = 0;

    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            cnt++;
            int p = 0;
            while (n % primes[i] == 0) {
                n /= primes[i];
                p++;
            }
            sum += binPow(primes[i], p);
        }
    }
    if (n > 1) {
        cnt++;
        sum += n;
    }

    if (cnt == 1) {
        sum += 1;
    }
    return sum;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case = 1, n;

    Sieve();

    while (scanf("%d", &n) == 1) {
        if (n == 0) return 0;
        if (n == 1) printf("Case %d: %d\n", Case++, 2);
        else printf("Case %d: %lld\n", Case++, min_Sum_LCM(n));
    }

    return 0;
}

