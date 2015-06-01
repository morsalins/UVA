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
#define MAX 100000000
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

#define ifc(n) (composit[n>>6] & (1<<((n>>1)&31)))
#define isc(n) (composit[n>>6] |= (1<<((n>>1)&31)))

unsigned int composit[(MAX >> 6) + 10];
VI primes;

bool isPrime (int n)
{
    return (n == 2) || ((n & 1) && !ifc(n));
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
    for (int i = 3; i <= MAX; i += 2) {
        if (!ifc(i)) primes.pb(i);
    }
    return;
}

PII getAns (int i)
{
    PII t = PII(0, 0);

    if (i&1) {
        if(i - 2 > 0 && isPrime(i - 2)) t = PII(2, i - 2);
    }
    else {
        int mid = (i >> 1) + 1;
        int pos  = lower_bound(primes.begin(), primes.end(), mid) - primes.begin();
        bool flag = false;

        for (int j = pos; j >= 0 && !flag; j--) {
            int sub = i - primes[j];
            if (sub > 1 && (i != sub + sub) && isPrime(sub)) {//DEBUG(i, primes[j])
                flag = true;
                t = PII( min(primes[j], sub), max(primes[j], sub) );
            }
        }
    }
    return t;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int s;
    char dump[2];

   Sieve();

    while (scanf("%d", &s) == 1) {
        PII GC = getAns(s);
        if (GC != PII(0, 0)) printf("%d is the sum of %d and %d.\n", s, GC.ff, GC.ss);
        else printf("%d is not the sum of two primes!\n", s);
    }
    return 0;
}



