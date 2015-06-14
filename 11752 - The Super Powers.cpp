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
#define MAX 18446744073709551615
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

bool prime[110];

bool isPrime (int n)
{
    return n == 2 || ((n & 1) && prime[n]);
}

void Sieve ()
{
    int limit = sqrt(100) + 2;

    SET(prime, true);
    prime[0] = false;
    prime[1] = false;

    for (int i = 3; i <= limit; i += 2) {
        if (prime[i]) {
            for (int j = i * i, k = i << 1; j <= 100; j += k) {
                prime[j] = false;
            }
        }
    }
    return;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    Sieve();

    set <unsigned long long int> ans;
    ans.insert(1);

    for (unsigned long long int i = 2; i <= 100000; i++) {
        unsigned long long int res = i * i * i;
        for (int p = 4; p <= 64; p++) {
            if (MAX / res >= i) {
                res *= i;
                if (!isPrime(p)) {
                    ans.insert(res);
                }
            }
            else
            {
                break;
            }
        }
    }

    for (set <unsigned long long int> :: IT it = ans.begin(); it != ans.end(); it++) {
        unsigned long long int t = *it;
        printf("%llu\n", t);
    }

    return 0;
}

