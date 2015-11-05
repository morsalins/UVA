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

#define I64 long long
#define INF 0x7f7f7f7f
#define SIZE 1000000
#define MAX 1000000
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

int factorFreq[MAX + 7];
I64 LCM[MAX + 7];
int composite[MAX + 7];
VI primes;

void Sieve ()
{
    int limit = MAX;
    int lim = (int)(sqrt(limit));

    for (int i = 3; i <= lim + 2; i += 2) {
        if (!composite[i]) {
            for (int j = i * i, k = i << 1; j <= limit; j += k) {
                composite[j] = true;
            }
        }
    }

    primes.pb(2);
    for (int i = 3; i <= limit; i += 2) {
        if (!composite[i]) {
            primes.pb(i);
        }
    }
    return;
}

void updateLCM (int idx)
{
    while (LCM[idx] % 10 == 0) {
        LCM[idx] /= 10;
    }
    LCM[idx] = LCM[idx] % 10000000;
    return;
}

void factorization (int n)
{
    int N = n;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            int cnt = 0;
            while (n % primes[i] == 0) {
                n /= primes[i];
                cnt++;
            }
            for (int j = 1; j <= cnt - factorFreq[primes[i]]; j++) {
                LCM[N] = LCM[N] * primes[i];
            }
            factorFreq[primes[i]] = max(factorFreq[primes[i]], cnt);
        }
    }

    if (n > 1) {
        for (int j = 1; j <= 1 - factorFreq[n]; j++) {
            LCM[N] = LCM[N] * n;
        }
        factorFreq[n] = max(factorFreq[n], 1);
    }
    updateLCM(N);
    return;
}

void init ()
{
    Sieve();

    LCM[1] = 1; LCM[2] = 2; LCM[3] = 6;
    factorFreq[2] = 1;
    factorFreq[3] = 1;

    for (int i = 4; i <= MAX; i++) {
        LCM[i] = LCM[i-1];
        factorization(i);
    }
    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int n;

    init();

    while (scanf("%d", &n) == 1) {
        if (n == 0) return 0;
        else printf("%d\n", LCM[n] % 10);
    }
    return 0;
}

