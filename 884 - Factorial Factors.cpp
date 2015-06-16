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

bool composite[MAX + 7];
int factor[MAX + 7];
int factors[MAX + 7];
int totalFactors[MAX + 7];

bool isPrime (int n)
{
    return (n == 2) || ((n & 1) && !composite[n]);
}

void Sieve ()
{
    int limit = sqrt(MAX) + 2;

    composite[1] = true;

    for (int i = 3; i <= limit; i += 2) {
        if (!composite[i]) {
            for (int j = i * i, k = i << 1; j <= MAX; j += k) {
                composite[j] = true;
                factor[j] = i;
            }
        }
    }
    return;
}

void CalculateFactors ()
{
    factors[1] = 0;
    totalFactors[1] = 0;

    for (int i = 2; i <= MAX; i++) {
        if (isPrime(i)) {
            factors[i] = 1;
        }
        else {
            if (i & 1) factors[i] = factors[ i / factor[i] ] + 1;
            else factors[i] = factors[ i / 2 ] + 1;
        }
        totalFactors[i] = totalFactors[i-1] + factors[i];
    }
    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int n;

    Sieve();
    CalculateFactors();

    while (scanf("%d", &n) == 1) {
        printf("%d\n", totalFactors[n]);
    }
    return 0;
}

