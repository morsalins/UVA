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
#define MAX 2000
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

const int Size = 50000;

int factors[Size];
bool prime[Size];
VI primes;

void Seive ()
{
    int limit = sqrt(Size);
    SET(prime, true);
    //prime[1] = false;

    for(int i = 3; i <= limit; i += 2) {
        if (prime[i]) {
           for (int j = i * i; j <= Size; j += i) {
                prime[j] = false;
           }
        }
    }

    primes.pb(2);
    for (int i = 3; i <= Size; i += 2) {
        if (prime[i]) primes.pb(i);
    }
}

void findFactors (int n, int &idx)
{
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
        while (n % primes[i] == 0) {
            n /= primes[i];
            factors[idx++] = primes[i];
        }
    }
    if (n > 1) factors[idx++] = n;
    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int Case=1;
    int n;
    char dump[2];

    Seive();

    while (scanf("%d", &n) == 1) {
        if (n == 0) return 0;

        int absn = abs(n);
        int idx = 0;

        if (n < 0) {
            factors[idx++] = -1;
        }

        findFactors(absn, idx);

        printf("%d = %d", n, factors[0]);
        for (int i = 1; i < idx; i++) {
            printf(" x %d", factors[i]);
        }
        puts("");
    }
    return 0;
}

