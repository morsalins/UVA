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

//VI primes;
unsigned composite[(MAX >> 6) + 7];

bool isPrime (int n)
{
    return (n == 2) || ((n & 1) && !ifc(n));
}

void Sieve ()
{
    int lim = sqrt(MAX) + 1;
    isc(1);

    for (int i = 3; i <= lim; i += 2) {
        if (!ifc(i)) {
            for (int j = i * i, k = i << 1; j <= MAX; j += k) {
                isc(j);
            }
        }
    }

//    primes.pb(2);
//    for (int i = 3; i <= MAX; i += 2) {
//        if (isPrime(i)) {
//            primes.pb(i);
//        }
//    }
    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int n;
    int ans[4];
    char dump[2];

    Sieve();

    while (scanf("%d", &n) == 1) {

        if (n < 8) puts("Impossible.");

        else {
            ans[0] = 2; ans[1] = 2 + (n & 1);
            n -= 4 + (n & 1);

            if (isPrime(n-2)) {
                ans[2] = 2; ans[3] = n - 2;
            }

            else {
                for (int i = 3; i <= n; i += 2) {
                    if (isPrime(i) && isPrime(n - i)) {
                        ans[2] = i; ans[3] = n - i;
                        break;
                    }
                }
            }

            for (int i = 0; i < 4; i++) {
                printf("%d ", ans[i]);
            }
            puts("");
        }
    }
    return 0;
}

