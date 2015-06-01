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
#define MAX 50000
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

void PrimeDistance (int a, int b)
{
    int counter = 0, mn = 10000010, mx = -1, last = 0;
    PII mindist, maxdist;

    if (a <= 2) {
        last = 2;
        counter++;
        a = 3;
    }
    if (!(a & 1)) a++;

    for (I64 i = a; i <= b; i+=2) {
        bool flag = true;
        if (i <= MAX && !ifc(i)) {
            flag = true;
        }
        else {
            for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i && flag; j++) {
                if (i % primes[j] == 0) {
                    flag = false;
                }
            }
        }
        if (flag) {
            if (last != 0) {
                if (i - last > mx) {
                    mx = i - last;
                    maxdist = PII(last, i);
                }
                if (i - last < mn) {
                    mn = i - last;
                    mindist = PII(last, i);
                }
            }
            last = i;
            counter++;
        }//DEBUG(i, counter); getchar();
    }
    if (counter > 1) printf("%d,%d are closest, %d,%d are most distant.\n", mindist.ff, mindist.ss, maxdist.ff, maxdist.ss);
    else printf("There are no adjacent primes.\n");
    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int a, b;
    char dump[2];

   Sieve();

    while (scanf("%d %d", &a, &b) == 2) {
        PrimeDistance(a, b);
    }
    return 0;
}



