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
#define MAX 100
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

int primeIndex[MAX + 7];
int occur[105][30];
bool composite[MAX + 7];
VI primes;
int idx;

bool isPrime (int n)
{
    return (n == 2) || ((n & 1) && !composite[n]);
}

void Sieve ()
{
    composite[1] = true;
    idx = 0;
    primeIndex[2] = idx++;

    for (int i = 3; i <= MAX; i += 2) {
        if (!composite[i]) {
            primeIndex[i] = idx++;
            for (int j = i * i, k = i << 1; j <= MAX; j += k) {
                composite[j] = true;
            }
        }
    }

    primes.pb(2);
    primes.pb(3);
    primes.pb(5);
    primes.pb(7);
    primes.pb(11);
    return;
}

void findFactors ()
{
    for (int i = 2; i <= MAX; i++) {
        int n = i;
        if (isPrime(n)) {
            occur[i][ primeIndex[n] ]++;
        }
        else {
            for (int  j = 0 ; j < primes.size() && primes[j] * primes[j] <= n; j++) {
                while (n % primes[j] == 0) {
                    n /= primes[j];
                    occur[i][ primeIndex[primes[j]] ]++;
                }
            }
            if (n > 1) occur[i][ primeIndex[n] ]++;
        }

        for (int k = 0; k < idx; k++) {
            occur[i][k] += occur[i - 1][k];
        }
    }
    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int n;
    //for (int i = 1; i<=100; i++) cout << i << endl;
    Sieve();
    findFactors();

    while (scanf("%d", &n) == 1) {

        if (n == 0) return 0;

        int num = 0;

        printf("%3d! =", n);
        for (int i = 0; i < idx; i++) {
            if (occur[n][i]) {
                if (num == 15) {
                    printf("\n%6c", ' ');
                }
                printf("%3d", occur[n][i]);
                num++;
            }
        }
        puts("");
    }
    return 0;
}

