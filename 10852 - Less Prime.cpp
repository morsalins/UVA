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
#define MAX 10000
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

void Sieve ()
{
    SET(prime, true);
    prime[0] = false;
    prime[1] = false;
    int limit = sqrt(MAX) + 5;

    for (int i = 3; i <= limit; i++) {
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

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1, n;
    char dump[2];

    Sieve();

    int tc; scanf("%d", &tc);

    while (tc--) {

        scanf("%d", &n);
        int mx = -1, ans;

        for (int i = 0; i < primes.size() && primes[i] <= n; i++) {
            int p = n / primes[i];
            int v = n - (p * primes[i]);
            if (v > mx) {
                mx = v;
                ans = primes[i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

